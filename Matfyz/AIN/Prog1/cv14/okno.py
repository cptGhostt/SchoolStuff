import tkinter


class Okno:

    def __init__(self, text):
        self.c = tkinter.Canvas(height=100)
        self.c.pack()
        self.id = self.c.create_text(190, 50, text=text, font="Arial 50")

    def zmen(self, text):
        self.c.itemconfig(self.id, text=text)

    def farba(self, farba):
        self.c.itemconfig(self.id, fill=farba)
