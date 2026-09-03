# QuadratoImageViewer - Video Script & Demo Guide

## 📹 Video Script (3-5 Minutes)

---

### **[INTRO - 0:00-0:15]**

**[Visual: App window appears on screen]**

**Narrator:**
"Welcome to QuadratoImageViewer – a lightweight, always-on-top floating image viewer for Windows. Whether you're a designer, photographer, or content creator, this small but powerful tool keeps your reference images just a click away."

**[Visual: Show the 150×150 window with no image]**

"At just 500KB and using minimal system resources, it's the perfect companion app."

---

### **[FEATURES OVERVIEW - 0:15-0:45]**

**[Visual: Zoom in on the window interface]**

**Narrator:**
"Let me show you what makes QuadratoImageViewer special."

**[Visual: Click the Load button]**

**Narrator:**
"First, you have two simple ways to load images. You can either click the Load button in the toolbar..."

**[Visual: File dialog opens, select an image]**

**Narrator:**
"...or just double-click anywhere on the window."

**[Visual: Image appears and fills the window]**

**Narrator:**
"The image instantly displays at full resolution, perfectly fitted to the 150×150 pixel window."

**[Visual: Show the filename in the status bar]**

**Narrator:**
"The filename is always visible, so you know exactly what you're viewing."

---

### **[DRAG FEATURE - 0:45-1:15]**

**[Visual: Move mouse to the window]**

**Narrator:**
"Now here's the really cool part – repositioning. Simply hold down the X key on your keyboard..."

**[Visual: Press and hold X key, then click and drag the window]**

**Narrator:**
"...then drag with your mouse to move the window anywhere on your screen. This stays-on-top design means your reference image is always visible, even when other windows are in focus."

**[Visual: Drag window to different positions on screen]**

**Narrator:**
"Perfect for side-by-side work with design software, video editors, or any other application."

**[Visual: Release X key, try dragging without it – window doesn't move]**

**Narrator:**
"When you're not holding X, the window stays locked in place, so you won't accidentally move it while working."

---

### **[GLOBAL HOOKS VERSION - 1:15-1:45]**

**[Visual: Show working in Photoshop with QuadratoImageViewer on screen]**

**Narrator:**
"And here's where it gets crazy. We have TWO versions of this app."

**[Visual: Show cursor in Photoshop, press X key]**

**Narrator:**
"The standard version works great when the window is focused. But the GLOBAL HOOKS version?"

**[Visual: Drag QuadratoImageViewer while Photoshop is active]**

**Narrator:**
"You can hold X and drag the image from ANY application. You don't even need to click on our window. It's like the app is integrated into Windows itself."

**[Visual: Show dragging from VS Code, then Chrome, then other apps]**

**Narrator:**
"System-wide keyboard and mouse hooks mean the app responds globally, making it feel like a true Windows system tool."

---

### **[MULTIPLE FORMATS - 1:45-2:15]**

**[Visual: Load different image types]**

**Narrator:**
"QuadratoImageViewer supports all common image formats."

**[Visual: Load a PNG image]**

**Narrator:**
"PNG with transparency – check."

**[Visual: Load a JPG image]**

**Narrator:**
"JPG photographs – no problem."

**[Visual: Load a GIF]**

**Narrator:**
"Even GIF animations display beautifully."

**[Visual: Load a BMP image]**

**Narrator:**
"And classic BMP files are fully supported."

---

### **[QUICK CLOSE - 2:15-2:30]**

**[Visual: Show the X button in the toolbar]**

**Narrator:**
"Closing is just as simple. Click the X button in the top-right corner..."

**[Visual: Click X button, window closes]**

**Narrator:**
"...or press Escape on your keyboard."

---

### **[TECHNICAL SPECS - 2:30-3:00]**

**[Visual: Show system specs on screen]**

**Narrator:**
"Here's what you're getting under the hood:"

**[Visual: Display each spec]**

**Narrator:**
"Pure C++ using Windows Win32 API – that means it's fast and efficient.

Built with GDI+, so image rendering is smooth and accurate.

Completely portable – just 500 kilobytes, no installation needed.

Memory-light, using only 10 to 20 megabytes of RAM.

Always on top, so it never gets lost behind other windows.

And it works on Windows 7 all the way through Windows 11.

We even have a GLOBAL HOOKS version with system-wide integration."

---

### **[USE CASES - 3:00-3:45]**

**[Visual: Show different scenarios]**

**Narrator:**
"Who should use QuadratoImageViewer?"

**[Visual: Designer working in Photoshop with reference image floating]**

**Narrator:**
"Designers can reference mood boards, color palettes, or client specs while working – and with the global hooks version, move it around without losing focus."

**[Visual: Video editor with storyboard visible]**

**Narrator:**
"Video editors can keep storyboards or color grades visible during editing."

**[Visual: Developer with design mockup]**

**Narrator:**
"Web developers can match designs pixel-perfect while coding."

**[Visual: Artist with reference photo]**

**Narrator:**
"Digital artists can keep reference photos visible while drawing."

**[Visual: Photography workflow]**

**Narrator:**
"Photographers can compare shots side-by-side or reference editing guidelines."

---

### **[PERFORMANCE DEMO - 3:45-4:15]**

**[Visual: Open Task Manager showing memory usage]**

**Narrator:**
"Let's talk performance. Even with a high-resolution image loaded..."

**[Visual: Load a large image, show system resources]**

**Narrator:**
"...the app uses minimal CPU and memory. You can leave it running all day without any slowdown."

**[Visual: Drag window smoothly across screen multiple times]**

**Narrator:**
"The drag operation is buttery smooth, even when the window is always on top."

**[Visual: Switch between apps while QuadratoImageViewer stays visible]**

**Narrator:**
"And with the global hooks version, drag responsiveness is instant from any application."

---

### **[INSTALLATION & SETUP - 4:15-4:45]**

**[Visual: Show GitHub repository]**

**Narrator:**
"Getting started is easy. Head to the GitHub repository..."

**[Visual: Clone or download]**

**Narrator:**
"...download or clone the source code."

**[Visual: Show two versions - Standard and GlobalHooks]**

**Narrator:**
"You'll find TWO C++ source files. The standard version for basic use, and the global hooks version for system-wide integration."

**[Visual: Open Visual Studio]**

**Narrator:**
"If you want to compile from source, we provide detailed build instructions for Visual Studio, command line, and MinGW."

**[Visual: Show compiler output, executable created]**

**Narrator:**
"Compilation takes just a few seconds, and you get a lightweight, standalone executable."

**[Visual: Double-click exe, app opens]**

**Narrator:**
"Double-click to run – no installation, no dependencies, just works."

---

### **[CUSTOMIZATION - 4:45-5:00]**

**[Visual: Show source code in editor]**

**Narrator:**
"The source code is open and easy to modify. Want to change the window size? Simple. 

Different colors? Just edit the RGB values.

Change the hotkey from X to Ctrl? A few seconds.

You have complete control to make it your own."

---

### **[OUTRO - 5:00-5:15]**

**[Visual: Show both app versions in action]**

**Narrator:**
"QuadratoImageViewer – lightweight, fast, and powerful. 

Two versions: Standard for simplicity, Global Hooks for ultimate system integration.

Perfect for professionals who need quick image referencing.

Open source, completely free, and ready to enhance your workflow."

**[Visual: GitHub link appears on screen]**

**Narrator:**
"Check out the repository, grab your copy, and start using it today.

Thanks for watching!"

**[Visual: Fade to black with GitHub URL]**

---

## 🎬 **SCENE BREAKDOWN FOR RECORDING**

### **Scene 1: Intro (15 seconds)**
- App window appears at (500, 300)
- Show window with no image loaded
- Empty state visible

### **Scene 2: Loading Images (30 seconds)**
1. Click Load button → file dialog opens
2. Select an image file (use a nice landscape or portrait photo)
3. Image loads and displays
4. Repeat with different image types (PNG, JPG, GIF, BMP)

### **Scene 3: Drag Feature (30 seconds)**
1. Press X key
2. Click and drag window slowly across screen
3. Show window moving to different positions
4. Release X key
5. Try dragging without X to show lock

### **Scene 4: Global Hooks Demo (30 seconds)**
1. Open Photoshop or VS Code
2. Have QuadratoImageViewer in background
3. Work in the other app
4. Press X key without clicking on QuadratoImageViewer
5. Drag window from background app
6. Show smooth operation

### **Scene 5: Technical Demo (30 seconds)**
1. Show the executable in File Explorer
2. Display its size (~500 KB)
3. Open Task Manager showing memory usage
4. Show smooth performance with image loaded
5. Switch between apps quickly

### **Scene 6: Close App (15 seconds)**
1. Click X button → window closes
2. OR press Escape → window closes

---

## 📝 **TALKING POINTS FOR LIVE DEMO**

1. **Lightweight:** "At just 500KB, it's one of the smallest image viewers out there."

2. **Always Visible:** "The always-on-top feature means your reference image never gets buried."

3. **Easy Navigation:** "With just a few clicks or keyboard shortcuts, you're viewing images instantly."

4. **Professional Quality:** "Built with pure C++ and Win32 API for maximum performance."

5. **Zero Dependencies:** "No .NET framework, no external libraries – it just works on any Windows PC."

6. **Portable:** "No installation needed. Download, run, enjoy."

7. **Developer Friendly:** "Open source code makes it easy to customize or extend."

8. **Two Versions:** "Choose between standard simplicity or global hooks for system-wide integration."

9. **System Integration:** "The global hooks version feels like a built-in Windows feature."

10. **Drag From Anywhere:** "Hold X and drag from ANY application - it's that powerful."

---

## 🎥 **RECORDING TIPS**

1. **Use 1080p Resolution** - Clear, sharp video
2. **Slow Down Cursor Movements** - Give viewers time to see what you're doing
3. **Use Keyboard Shortcuts** - Shows power users the quick way
4. **Load Different Image Types** - Showcases versatility
5. **Speak Clearly** - Pause between points
6. **Use Background Music** - Adds polish (royalty-free instrumental)
7. **Add Text Overlays** - Highlight key features
8. **Show File Path** - So viewers know exactly what they're opening
9. **Demonstrate Both Versions** - Show the difference clearly
10. **Highlight Hotkey Usage** - Makes the global version impressive

---

## 🔊 **AUDIO/MUSIC SUGGESTIONS**

- Background: Upbeat, modern instrumental (90-120 BPM)
- Intro Music: Tech-focused, energetic
- Section Transitions: Smooth fade-outs/fade-ins
- Sound Effects: Soft click sounds for interactions
- Outro Music: Same as intro or similar style

**Royalty-Free Sources:**
- Epidemic Sound
- Artlist.io
- YouTube Audio Library
- Freepik Music
- Incompetech

---

## 📊 **VIDEO STRUCTURE SUMMARY**

| Section | Duration | Key Points |
|---------|----------|--------|
| Intro | 0:15 | What is it? Why use it? |
| Features | 0:30 | Load images, easy interface |
| Drag Feature | 0:30 | X+drag, stays on top |
| Global Hooks | 0:30 | System-wide integration |
| Multiple Formats | 0:30 | PNG, JPG, GIF, BMP support |
| Close App | 0:15 | Two ways to close |
| Tech Specs | 0:30 | C++, Win32, performance |
| Use Cases | 0:45 | Designer, developer, artist workflows |
| Performance | 0:30 | Low resource usage, smooth |
| Installation | 0:30 | How to get it, how to compile |
| Two Versions | 0:15 | Standard vs Global Hooks |
| Customization | 0:15 | Open source, modifiable |
| Outro | 0:15 | Call to action, GitHub link |
| **TOTAL** | **~5:15** | **Professional demo** |

---

## ✅ **CHECKLIST BEFORE RECORDING**

- [ ] Test both app versions on clean Windows system
- [ ] Use high-quality sample images (diverse formats)
- [ ] Set resolution to 1080p or higher
- [ ] Use a clear microphone
- [ ] Have GitHub repository URL ready
- [ ] Prepare 2-3 image files to load (different sizes/formats)
- [ ] Test X+drag feature multiple times
- [ ] Test global hooks version with other apps running
- [ ] Show build instructions on screen
- [ ] Practice speaking the script smoothly
- [ ] Plan camera/screen layout
- [ ] Download royalty-free background music
- [ ] Prepare title slides and overlays

---

## 🌟 **BONUS POINTS TO MENTION**

- "Available on GitHub for Windows 7 through Windows 11"
- "Perfect for side-by-side workflows"
- "No internet required after download"
- "Completely free and open source"
- "Customizable through source code"
- "Fast startup – ready in milliseconds"
- "Two distinct versions with different use cases"
- "Global hooks version is as close as you can get to Windhawk-level integration"
- "Professional-grade performance in a tiny package"
- "Created with pure C++ and Win32 API"

---

## 🎯 **YOUTUBE OPTIMIZATION TIPS**

### **Title Suggestions**
- "QuadratoImageViewer - Crazy Windows Integration Image Viewer"
- "Hold X Key, Drag Floating Window From ANY App (Global Hooks)"
- "Lightweight Image Viewer with System-Wide Integration"
- "Windhawk Alternative: Global Keyboard & Mouse Hooks"

### **Description Template**
```
QuadratoImageViewer - A lightweight floating image viewer with TWO versions:

📌 Standard Version
- Click to open images
- Hold X + drag to move
- Always on top
- 500KB, zero dependencies

🔥 Global Hooks Version
- X key works from ANY app
- Drag from background applications
- System-wide integration
- Windows 7/10/11 compatible

⬇️ Download
GitHub: [link]

⏱️ Timestamps
0:00 - Intro
0:15 - Features
0:45 - Drag Feature
1:15 - Global Hooks Demo
1:45 - Formats Supported
2:15 - Quick Close
2:30 - Technical Specs
3:00 - Use Cases
3:45 - Performance
4:15 - Installation
4:45 - Customization
5:00 - Outro

#QuadratoImageViewer #WindowsTools #OpenSource
```

### **Tags**
- QuadratoImageViewer
- Windows tools
- Image viewer
- Global hooks
- Win32 API
- C++ application
- Open source software
- Windhawk alternative
- System integration
- Floating window

---

## 📸 **SCREENSHOT GUIDE (For Written Tutorial)**

If creating a written guide instead, include:

1. **Empty Window** - "Fresh start, ready to load"
2. **Load Dialog** - "Click Load or double-click window"
3. **Image Loaded** - "Full resolution in tiny 150×150 window"
4. **X Key + Drag** - "Hold X, then drag to reposition"
5. **Multiple Formats** - "PNG, JPG, GIF, BMP all supported"
6. **Task Manager** - "Minimal resource usage (~15MB RAM)"
7. **Side-by-Side** - "Works great with other applications"
8. **Global Hooks** - "X key works from any app"

---

This comprehensive script provides everything needed for a professional, engaging video demonstration!
