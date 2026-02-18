# uloha 1

# class Obdlznik:
#
#     def __init__(self, a, b):
#         # inicializuje
#         self.a = a
#         self.b = b
#
#     def __str__(self):
#         # vráti reťazec v tvare 'Obdlznik(100, 70)'
#         return f"Obdlznik({self.a}, {self.b})"
#
#     def obsah(self):
#         # vráti obsah
#         return self.a * self.b
#
#     def obvod(self):
#         # vráti obvod
#         return 2 * (self.a + self.b)
#
#     def zmen_velkost(self, pomer):
#         # vynásobí obe veľkosti strán zadaným pomerom
#         self.a *= pomer
#         self.b *= pomer
#
#     def kopia(self):
#         # vyrobí kópiu samého seba
#         return Obdlznik(self.a, self.b)
#
#
# obd1 = Obdlznik(20, 7)
# print('obvod =', obd1.obvod())
# print(obd1)
# obd2 = obd1.kopia()
# obd2.zmen_velkost(2)
# print(obd2)

# uloha 2

# class TelefonnyZoznam:
#     def __init__(self, meno_suboru):
#         self.meno_suboru = meno_suboru
#         self.zoznam = []
#
#     def pridaj(self, meno, telefon):
#         for i in self.zoznam:
#             if i[0] == meno:
#                 self.zoznam.insert(self.zoznam.index(i), (meno, telefon))
#                 self.zoznam.pop(self.zoznam.index(i))
#                 return
#         self.zoznam.append((meno, telefon))
#
#     def vypis(self):
#         for i in self.zoznam:
#             print(i[0], i[1])
#
#     def zapis(self):
#         with open(self.meno_suboru, "w", encoding="utf8") as f:
#             for i in self.zoznam:
#                 print(f"{i[0]};{i[1]}", file=f)
#
#     def citaj(self):
#         with open(self.meno_suboru, "r", encoding="utf8") as f:
#             tmp = []
#             for line in f:
#                 tmp.append((line[:line.find(";")], line[line.find(";")+1:]))
#             self.zoznam = tmp
#
#
# tz = TelefonnyZoznam('tel.txt')
# tz.pridaj('Jana', '0901020304')
# tz.zapis()
# t2 = TelefonnyZoznam('tel.txt')
# t2.citaj()
# t2.vypis()

# uloha 3

# from random import randrange, randint
# from tkinter import Canvas, mainloop
#
#
# class Stv:
#     c = Canvas()
#     c.pack()
#
#     def __init__(self, x, y, a=20, farba=""):
#         if farba == "":
#             self.stvorec = self.c.create_rectangle(x-(a/2), y-(a/2), x+(a/2), y+(a/2), fill=f"#{randrange(256**3):06x}")
#         else:
#             self.stvorec = self.c.create_rectangle(x - (a / 2), y - (a / 2), x + (a / 2), y + (a / 2),fill=farba)
#
#     def posun(self,dx, dy):
#         self.c.move(self.stvorec, dx, dy)
#
#     def zmen_farbu(self, farba):
#         self.c.itemconfig(self.stvorec, fill=farba)
#
#
# mainloop()

# uloha 4

from random import randrange, randint
from tkinter import Canvas, mainloop


# class Stv:
#     c = Canvas()
#     c.pack()
#
#     def __init__(self, x, y, a=20, farba=""):
#         if farba == "":
#             self.stvorec = self.c.create_rectangle(x-(a/2), y-(a/2), x+(a/2), y+(a/2), fill=f"#{randrange(256**3):06x}")
#         else:
#             self.stvorec = self.c.create_rectangle(x - (a / 2), y - (a / 2), x + (a / 2), y + (a / 2),fill=farba)
#
#     def posun(self,dx, dy):
#         self.c.move(self.stvorec, dx, dy)
#
#     def zmen_farbu(self, farba):
#         self.c.itemconfig(self.stvorec, fill=farba)
#
#
# class Dvojica:
#     def __init__(self, x, y, a=20):
#         self.a = Stv(x, y, a)
#         self.b = Stv(x+a, y, a)
#
#     def posun(self, dx, dy):
#         self.a.posun(dx, dy)
#         self.b.posun(dx, dy)
#
#     def vymen(self):
#         c1 = self.a.c.itemcget(self.a.stvorec, "fill")
#         c2 = self.b.c.itemcget(self.b.stvorec, "fill")
#
#         self.a.c.itemconfig(self.a.stvorec, fill=c2)
#         self.b.c.itemconfig(self.a.stvorec, fill=c1)
#
#
# mainloop()

# uloha 5

# from tkinter import Canvas, mainloop
#
#
# class Klikanie:
#     def __init__(self):
#         self.c = Canvas()
#         self.c.pack()
#         self.c.bind("<Button-1>", self.klik)
#
#     def klik(self, event):
#         self.c.create_oval(event.x - 2, event.y - 2, event.x + 3, event.y +3)
#
#
# k = Klikanie()
# mainloop()

# uloha 6

# from tkinter import Canvas, mainloop
#
#
# class Klikanie:
#     def __init__(self):
#         self.zoznam = []
#         self.c = Canvas()
#         self.c.pack()
#         self.c.bind("<Button-1>", self.klik)
#
#     def klik(self, event):
#         self.zoznam.append((event.x, event.y))
#         self.c.create_oval(event.x - 2, event.y - 2, event.x + 3, event.y +3)
#
#     def vypis(self):
#         for i in self.zoznam:
#             print(i)
#
#
# k = Klikanie()
# mainloop()

# uloha 7

from tkinter import Canvas, mainloop


# class Klikanie:
#     def __init__(self):
#         self.zoznam = []
#         self.c = Canvas()
#         self.c.pack()
#         self.c.bind("<Button-1>", self.klik)
#
#     def klik(self, event):
#         if len(self.zoznam) > 0:
#             self.c.create_line(self.zoznam[len(self.zoznam) - 1], event.x, event.y)
#         self.zoznam.append((event.x, event.y))
#         self.c.create_oval(event.x - 2, event.y - 2, event.x + 3, event.y +3)
#
#     def vypis(self):
#         for i in self.zoznam:
#             print(i)
#
#
# k = Klikanie()
# mainloop()

# uloha 8

# class Tahanie:
#     def __init__(self):
#         self.zoznam = []
#         self.c = Canvas()
#         self.c.pack()
#         self.c.bind("<Button-1>", self.klik)
#         self.c.bind("<B1-Motion>", self.tahanie)
#
#     def klik(self, event):
#         self.zoznam.append((event.x, event.y))
#         self.c.create_oval(event.x - 2, event.y - 2, event.x + 3, event.y +3)
#
#     def tahanie(self, event):
#         self.c.create_line(self.zoznam[len(self.zoznam)-1], event.x, event.y)
#         self.zoznam.append((event.x, event.y))
#
#
# t = Tahanie()
# mainloop()

# uloha 9

# from tkinter import Canvas, mainloop
#
#
# class VyrobPolygon:
#     def __init__(self, meno_suboru):
#         self.meno_suboru = meno_suboru
#         with open(meno_suboru, "w") as f:
#             pass
#         self.c = Canvas()
#         self.c.pack()
#         self.polygon = self.c.create_polygon(0, 0, fill="white", outline="black")
#         self.zoznam = []
#         self.c.bind("<Button-1>", self.klik)
#         self.c.bind_all("<Return>", self.enter)
#
#     def klik(self, event):
#         self.zoznam.append(event.x)
#         self.zoznam.append(event.y)
#         self.c.coords(self.polygon, self.zoznam)
#
#     def enter(self, event):
#         with open(self.meno_suboru, "a") as f:
#             for i in self.zoznam:
#                 print(i, end=" ", file=f)
#             print("", file=f)
#
#         self.zoznam.clear()
#         self.c.coords(self.polygon, 0, 0)
#
#
# v = VyrobPolygon("suradnice.txt")
# mainloop()

# uloha 10

from tkinter import Canvas, mainloop
from random import randrange


class CitajPolygon:
    def __init__(self, meno_suboru):
        self.c = Canvas()
        self.c.pack()
        self.zoznam = []
        with open(meno_suboru, "r") as f:
            for i in f:
                tmp = i.split()
                for j in range(len(tmp)):
                    tmp[j] = int(tmp[j])

                self.zoznam.append(self.c.create_polygon(tmp, fill="white", outline="black"))
        self.c.bind("<Button-1>", self.prefarbi)

    def prefarbi(self, event):
        for i in self.zoznam:
            self.c.itemconfigure(i, fill=f"#{randrange(256**3):06x}")


c = CitajPolygon("suradnice.txt")
mainloop()
