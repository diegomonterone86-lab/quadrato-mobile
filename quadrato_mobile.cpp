#include <windows.h>
#include <gdiplus.h>
#include <shellapi.h>
#include <string>
#include <filesystem>
#include <commdlg.h>

#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comdlg32.lib")

using namespace Gdiplus;
namespace fs = std::filesystem;

// Global variables
HWND g_hWnd = NULL;
HWND g_hCanvas = NULL;
HWND g_hLoadBtn = NULL;
HWND g_hCloseBtn = NULL;
HWND g_hInfoLabel = NULL;
Image* g_pImage = NULL;
bool g_xPressed = false;
int g_dragStartX = 0;
int g_dragStartY = 0;
std::wstring g_currentImagePath = L"";
ULONG_PTR g_gdiplusToken = 0;

const int WINDOW_SIZE = 150;
const int TOOLBAR_HEIGHT = 25;
const int CANVAS_HEIGHT = WINDOW_SIZE - TOOLBAR_HEIGHT;

// Forward declarations
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CanvasProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void LoadImage(const std::wstring& filePath);
void DrawPlaceholder(HDC hdc);
void DrawError(HDC hdc, const std::wstring& message);
std::wstring OpenFileDialog();

// Main window procedure
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        // Create canvas
        g_hCanvas = CreateWindowEx(
            0,
            L"STATIC",
            L"",
            SS_OWNERDRAW | WS_VISIBLE | WS_CHILD,
            0, 0,
            WINDOW_SIZE, CANVAS_HEIGHT,
            hWnd,
            (HMENU)1001,
            GetModuleHandle(NULL),
            NULL
        );

        // Create toolbar
        HWND hToolbar = CreateWindowEx(
            0,
            L"STATIC",
            L"",
            SS_LEFT | WS_VISIBLE | WS_CHILD,
            0, CANVAS_HEIGHT,
            WINDOW_SIZE, TOOLBAR_HEIGHT,
            hWnd,
            (HMENU)1002,
            GetModuleHandle(NULL),
            NULL
        );
        SetWindowLongPtr(hToolbar, GWLP_USERDATA, (LONG_PTR)g_hWnd);

        // Info label
        g_hInfoLabel = CreateWindowEx(
            0,
            L"STATIC",
            L"No image",
            SS_LEFT | WS_VISIBLE | WS_CHILD,
            3, CANVAS_HEIGHT + 4,
            WINDOW_SIZE - 70, TOOLBAR_HEIGHT - 8,
            hWnd,
            (HMENU)1003,
            GetModuleHandle(NULL),
            NULL
        );
        SetBkColor((HDC)0, RGB(20, 20, 20));
        SetTextColor((HDC)0, RGB(170, 170, 170));

        // Load button
        g_hLoadBtn = CreateWindowEx(
            0,
            L"BUTTON",
            L"📁",
            BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD,
            WINDOW_SIZE - 65, CANVAS_HEIGHT + 3,
            30, TOOLBAR_HEIGHT - 6,
            hWnd,
            (HMENU)1004,
            GetModuleHandle(NULL),
            NULL
        );

        // Close button
        g_hCloseBtn = CreateWindowEx(
            0,
            L"BUTTON",
            L"✕",
            BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD,
            WINDOW_SIZE - 30, CANVAS_HEIGHT + 3,
            25, TOOLBAR_HEIGHT - 6,
            hWnd,
            (HMENU)1005,
            GetModuleHandle(NULL),
            NULL
        );

        // Set colors for toolbar and labels
        HDC hdc = GetDC(hWnd);
        SetTextColor(hdc, RGB(170, 170, 170));
        SetBkColor(hdc, RGB(20, 20, 20));
        ReleaseDC(hWnd, hdc);

        break;
    }

    case WM_DRAWITEM:
    {
        DRAWITEMSTRUCT* pDis = (DRAWITEMSTRUCT*)lParam;
        if (pDis->CtlID == 1001) // Canvas
        {
            HBRUSH hBrush = CreateSolidBrush(RGB(32, 32, 32));
            FillRect(pDis->hDC, &pDis->rcItem, hBrush);
            DeleteObject(hBrush);

            if (g_pImage != NULL)
            {
                Graphics graphics(pDis->hDC);
                graphics.SetSmoothingMode(SmoothingModeHighQuality);
                graphics.DrawImage(g_pImage, 0, 0, WINDOW_SIZE, CANVAS_HEIGHT);
            }
            else
            {
                DrawPlaceholder(pDis->hDC);
            }
            return TRUE;
        }
        break;
    }

    case WM_KEYDOWN:
        if (wParam == 'X' || wParam == 'x')
        {
            g_xPressed = true;
        }
        break;

    case WM_KEYUP:
        if (wParam == 'X' || wParam == 'x')
        {
            g_xPressed = false;
        }
        if (wParam == VK_ESCAPE)
        {
            PostMessage(hWnd, WM_CLOSE, 0, 0);
        }
        break;

    case WM_LBUTTONDOWN:
    {
        g_dragStartX = GET_X_LPARAM(lParam);
        g_dragStartY = GET_Y_LPARAM(lParam);
        break;
    }

    case WM_MOUSEMOVE:
    {
        if (g_xPressed && (wParam & MK_LBUTTON))
        {
            int currentX = GET_X_LPARAM(lParam);
            int currentY = GET_Y_LPARAM(lParam);

            RECT rect;
            GetWindowRect(hWnd, &rect);

            int newX = rect.left + (currentX - g_dragStartX);
            int newY = rect.top + (currentY - g_dragStartY);

            SetWindowPos(hWnd, NULL, newX, newY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        break;
    }

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        if (wmId == 1004) // Load button
        {
            std::wstring filePath = OpenFileDialog();
            if (!filePath.empty())
            {
                LoadImage(filePath);
                InvalidateRect(g_hCanvas, NULL, FALSE);
            }
        }
        else if (wmId == 1005) // Close button
        {
            PostMessage(hWnd, WM_CLOSE, 0, 0);
        }
        break;
    }

    case WM_LBUTTONDBLCLK:
    {
        std::wstring filePath = OpenFileDialog();
        if (!filePath.empty())
        {
            LoadImage(filePath);
            InvalidateRect(g_hCanvas, NULL, FALSE);
        }
        break;
    }

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetBkColor(hdcStatic, RGB(20, 20, 20));
        SetTextColor(hdcStatic, RGB(170, 170, 170));
        return (INT_PTR)CreateSolidBrush(RGB(20, 20, 20));
    }

    case WM_CLOSE:
        PostQuitMessage(0);
        break;

    case WM_DESTROY:
        if (g_pImage != NULL)
        {
            delete g_pImage;
            g_pImage = NULL;
        }
        GdiplusShutdown(g_gdiplusToken);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

void LoadImage(const std::wstring& filePath)
{
    if (g_pImage != NULL)
    {
        delete g_pImage;
        g_pImage = NULL;
    }

    g_pImage = new Image(filePath.c_str());

    if (g_pImage->GetLastStatus() == Ok)
    {
        g_currentImagePath = filePath;

        // Extract filename
        size_t pos = filePath.find_last_of(L"\\/");
        std::wstring filename = (pos == std::wstring::npos) ? filePath : filePath.substr(pos + 1);

        // Truncate if too long
        if (filename.length() > 20)
        {
            filename = filename.substr(0, 17) + L"...";
        }

        SetWindowText(g_hInfoLabel, filename.c_str());
    }
    else
    {
        delete g_pImage;
        g_pImage = NULL;
        SetWindowText(g_hInfoLabel, L"Error loading image");
    }
}

void DrawPlaceholder(HDC hdc)
{
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeHighQuality);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);

    // Draw background
    SolidBrush bgBrush(Color(255, 32, 32, 32));
    graphics.FillRectangle(&bgBrush, 0, 0, WINDOW_SIZE, CANVAS_HEIGHT);

    // Draw text
    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 10, FontStyleBold, UnitPixel);
    SolidBrush textBrush(Color(255, 150, 150, 150));
    StringFormat format;
    format.SetAlignment(StringAlignmentCenter);
    format.SetLineAlignment(StringAlignmentCenter);

    RectF rect(0, 0, WINDOW_SIZE, CANVAS_HEIGHT);
    graphics.DrawString(L"🖼️\nDouble Click\nto Load", -1, &font, rect, &format, &textBrush);
}

void DrawError(HDC hdc, const std::wstring& message)
{
    Graphics graphics(hdc);
    graphics.SetSmoothingMode(SmoothingModeHighQuality);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);

    SolidBrush bgBrush(Color(255, 32, 32, 32));
    graphics.FillRectangle(&bgBrush, 0, 0, WINDOW_SIZE, CANVAS_HEIGHT);

    FontFamily fontFamily(L"Arial");
    Font font(&fontFamily, 8, FontStyleRegular, UnitPixel);
    SolidBrush textBrush(Color(255, 255, 0, 0));
    StringFormat format;
    format.SetAlignment(StringAlignmentCenter);
    format.SetLineAlignment(StringAlignmentCenter);

    RectF rect(0, 0, WINDOW_SIZE, CANVAS_HEIGHT);
    graphics.DrawString(message.c_str(), -1, &font, rect, &format, &textBrush);
}

std::wstring OpenFileDialog()
{
    wchar_t szFile[MAX_PATH] = { 0 };

    OPENFILENAME ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = g_hWnd;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(szFile[0]);
    ofn.lpstrFilter = L"Images\0*.PNG;*.JPG;*.JPEG;*.GIF;*.BMP\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameW(&ofn))
    {
        return std::wstring(szFile);
    }

    return L"";
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // Initialize GDI+
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&g_gdiplusToken, &gdiplusStartupInput, NULL);

    // Register window class
    const wchar_t CLASS_NAME[] = L"QuadratoMobileClass";

    WNDCLASSEX wcex = { 0 };
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(20, 20, 20));
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = CLASS_NAME;
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wcex);

    // Create window
    g_hWnd = CreateWindowEx(
        WS_EX_TOPMOST,
        CLASS_NAME,
        L"Quadrato Mobile",
        WS_POPUP | WS_VISIBLE,
        500, 300,
        WINDOW_SIZE, WINDOW_SIZE,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!g_hWnd)
    {
        GdiplusShutdown(g_gdiplusToken);
        return 1;
    }

    // Message loop
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Macro for extracting x and y from lParam
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
