import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk
import os

class QuadratoMobile:
    def __init__(self, root):
        self.root = root
        self.root.title("Quadrato Mobile")
        
        # Impostazioni finestra: dimensione 150x150, senza bordi e sempre in primo piano
        self.size = 150
        self.root.geometry(f"{self.size}x{self.size}+500+300")
        self.root.overrideredirect(True)
        self.root.wm_attributes("-topmost", True)
        
        # Variabili di stato
        self.x_pressed = False
        self.drag_start_x = 0
        self.drag_start_y = 0
        self.current_image_path = None
        self.photo = None
        
        # Frame principale per gestire il layout
        self.main_frame = tk.Frame(root, bg="black", highlightthickness=1, highlightbackground="gray30")
        self.main_frame.pack(fill="both", expand=True)
        
        # Canvas per ospitare l'immagine
        self.canvas = tk.Canvas(
            self.main_frame, 
            width=self.size, 
            height=self.size - 25, 
            bg="gray20", 
            highlightthickness=0,
            cursor="hand2"
        )
        self.canvas.pack(fill="both", expand=True)
        
        # Bottom toolbar frame
        self.toolbar = tk.Frame(self.main_frame, bg="gray10", height=25)
        self.toolbar.pack(fill="x", side="bottom")
        self.toolbar.pack_propagate(False)
        
        # Pulsanti nel toolbar
        self.btn_close = tk.Button(
            self.toolbar, 
            text="✕", 
            command=self.close_app,
            bg="red",
            fg="white",
            font=("Arial", 10, "bold"),
            padx=3,
            pady=0,
            relief="flat",
            cursor="arrow"
        )
        self.btn_close.pack(side="right", padx=3, pady=2)
        
        self.btn_load = tk.Button(
            self.toolbar, 
            text="📁", 
            command=self.apri_selettore_immagine,
            bg="blue",
            fg="white",
            font=("Arial", 10, "bold"),
            padx=3,
            pady=0,
            relief="flat",
            cursor="arrow"
        )
        self.btn_load.pack(side="right", padx=2, pady=2)
        
        # Label per mostrare il nome del file
        self.info_label = tk.Label(
            self.toolbar,
            text="",
            bg="gray10",
            fg="gray70",
            font=("Arial", 7),
            anchor="w",
            padx=3
        )
        self.info_label.pack(side="left", fill="x", expand=True)

        # Eventi tastiera per attivare la modalità movimento con "X"
        self.root.bind("<KeyPress-x>", self.on_key_press)
        self.root.bind("<KeyRelease-x>", self.on_key_release)
        self.root.bind("<Escape>", lambda e: self.close_app())
        
        # Eventi mouse per il movimento e il doppio clic
        self.canvas.bind("<Button-1>", self.start_drag)
        self.canvas.bind("<B1-Motion>", self.do_drag)
        self.canvas.bind("<Double-Button-1>", self.apri_selettore_immagine)
        self.main_frame.bind("<Button-1>", self.start_drag)
        self.main_frame.bind("<B1-Motion>", self.do_drag)
        
        # Placeholder iniziale
        self.mostra_placeholder()

    def on_key_press(self, event):
        self.x_pressed = True

    def on_key_release(self, event):
        self.x_pressed = False

    def start_drag(self, event):
        # Memorizza il punto di partenza del trascinamento
        self.drag_start_x = event.x
        self.drag_start_y = event.y

    def do_drag(self, event):
        # Sposta la finestra solo se il tasto X è premuto durante il trascinamento
        if self.x_pressed:
            x = self.root.winfo_x() + (event.x - self.drag_start_x)
            y = self.root.winfo_y() + (event.y - self.drag_start_y)
            self.root.geometry(f"+{x}+{y}")

    def apri_selettore_immagine(self, event=None):
        # Finestra di dialogo per scegliere l'immagine
        file_path = filedialog.askopenfilename(
            filetypes=[("Immagini", "*.png;*.jpg;*.jpeg;*.gif;*.bmp")]
        )
        if file_path:
            self.carica_immagine(file_path)

    def carica_immagine(self, path):
        try:
            # Carica e ridimensiona l'immagine per adattarla al quadrato
            img = Image.open(path)
            img = img.resize((self.size, self.size - 25), Image.Resampling.LANCZOS)
            self.photo = ImageTk.PhotoImage(img)
            
            self.canvas.delete("all")
            self.canvas.create_image(0, 0, anchor="nw", image=self.photo)
            
            # Salva il percorso e mostra il nome del file
            self.current_image_path = path
            filename = os.path.basename(path)
            # Tronca il nome se troppo lungo
            if len(filename) > 20:
                filename = filename[:17] + "..."
            self.info_label.config(text=filename)
        except Exception as e:
            self.mostra_errore(f"Errore: {str(e)}")

    def mostra_placeholder(self):
        # Mostra un placeholder quando nessuna immagine è caricata
        self.canvas.delete("all")
        self.canvas.create_text(
            self.size // 2,
            (self.size - 25) // 2,
            text="🖼️\nDouble Click\nto Load",
            fill="gray60",
            font=("Arial", 9, "bold"),
            justify="center"
        )
        self.info_label.config(text="No image")

    def mostra_errore(self, messaggio):
        # Mostra un messaggio di errore
        self.canvas.delete("all")
        self.canvas.create_text(
            self.size // 2,
            (self.size - 25) // 2,
            text=messaggio,
            fill="red",
            font=("Arial", 8),
            justify="center"
        )

    def close_app(self):
        # Chiude l'applicazione
        self.root.quit()
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = QuadratoMobile(root)
    root.mainloop()
