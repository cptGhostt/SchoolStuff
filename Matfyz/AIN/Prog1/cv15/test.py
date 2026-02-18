from tkinter import Canvas, mainloop


class Klikanie:
    def __init__(self):
        self.zoznam = []
        self.c = Canvas()
        self.c.pack()
        self.c.bind("<Button-1>", self.klik)

    def klik(self, event):
        self.zoznam.append((event.x, event.y))
        self.c.create_oval(event.x - 2, event.y - 2, event.x + 3, event.y +3)

    def vypis(self):
        for i in self.zoznam:
            print(i)


k = Klikanie()
mainloop()