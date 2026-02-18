# uloha 1

# class Zviera:
#     def __init__(self, meno):
#         self.meno = meno.capitalize()
#
#     def __str__(self):
#         return f'zviera {self.typ} má meno {self.meno} a robí {self.zvuk}'
#
# class Pes(Zviera):
#     typ = 'pes'
#     zvuk = 'haf-haf'
#
# class Macka(Zviera):
#     typ = 'mačka'
#     zvuk = 'mnau-mnau'
#
# class Kacka(Zviera):
#     typ = 'kačka'
#     zvuk = 'ga-ga'
#
# z1 = Pes('dunčo')
# z2 = Macka('mica')
# z3 = Pes('bono')
# z4 = Kacka('gréta')
# z3.zvuk = 'vrr-vrr'
# for z in z1, z2, z3, z4:
#     print(z)

# uloha 2

# class Zviera:
#     def __init__(self, meno):
#         self._meno = meno.capitalize()
#         self._zvuk = self.zvuk
#         self._typ = self.typ
#
#     def __str__(self):
#         return f'zviera {self.typ} má meno {self.meno} a robí {self.zvuk}'
#
#     @property
#     def typ(self):
#         return self._typ
#
#     @property
#     def zvuk(self):
#         return self._zvuk
#
#     @zvuk.setter
#     def zvuk(self, zvuk):
#         if zvuk.find("-") != -1:
#             self._zvuk = zvuk
#         else:
#             self._zvuk = zvuk + "-" + zvuk
#
#     @property
#     def meno(self):
#         return self._meno
#
#     @meno.setter
#     def meno(self, meno:str):
#         self._meno = meno.capitalize()
#
#
# class Pes(Zviera):
#     _typ = 'pes'
#     _zvuk = "haf-haf"
#
#
# class Macka(Zviera):
#     _typ = 'mačka'
#     _zvuk = "mnau-mnau"
#
#
# class Kacka(Zviera):
#     _typ = 'kačka'
#     _zvuk = "ga-ga"
#
#
# z1 = Pes('dunčo')
# z2 = Macka('mica')
# z3 = Pes('bono')
# z4 = Kacka('gréta')
# for z in z1, z2, z3, z4:
#     print(z)
# z3.zvuk = "vrr"
# print(z3.zvuk)
# z4.zvuk = "GA-GA"
# print(z4.zvuk)
# z4.meno = "grETA"
# print(z4.meno)
# # z2.typ = "cat"
# print(z2.typ)

# uloha 3

# class Ucet:
#     def __init__(self, meno, suma=0):
#         self.meno = meno
#         self.suma = suma
#
#     def __str__(self):
#         return f"ucet {self.meno} -> {self.suma} euro"
#
#     def stav(self):
#         return self.suma
#
#     def vklad(self, suma):
#         self.suma += suma
#
#     def vyber(self, suma):
#         if suma < 0:
#             return 0
#
#         if self.suma - suma >= 0:
#             self.suma -= suma
#             return suma
#         else:
#             tmp = self.suma
#             self.suma = 0
#             return tmp
#
#
# mbank = Ucet('mbank')
# csob = Ucet('csob', 100)
# tatra = Ucet('tatra', 17)
# sporo = Ucet('sporo', 50)
# mbank.vklad(sporo.vyber(30) + tatra.vyber(30))
# csob.vyber(-5)
# spolu = 0
# for ucet in mbank, csob, tatra, sporo:
#     print(ucet)
#     spolu += ucet.stav()
# print('spolu = ', spolu)

# uloha 4

# class Ucet:
#     def __init__(self, meno, suma=0):
#         self.meno = meno
#         self.suma = suma
#
#     def __str__(self):
#         return f"ucet {self.meno} -> {self.suma} euro"
#
#     def stav(self):
#         return self.suma
#
#     def vklad(self, suma):
#         self.suma += suma
#
#     def vyber(self, suma):
#         if suma < 0:
#             return 0
#
#         if self.suma - suma >= 0:
#             self.suma -= suma
#             return suma
#         else:
#             tmp = self.suma
#             self.suma = 0
#             return tmp
#
#
# class UcetHeslo(Ucet):
#     def __init__(self, meno, heslo, suma=0):
#         super().__init__(meno, suma)
#         self.heslo = heslo
#
#     def vklad(self, suma):
#         heslo = input(f"Zadaj heslo uctu {self.meno}: ")
#         if heslo == self.heslo:
#             super().vklad(suma)
#
#     def vyber(self, suma):
#         heslo = input(f"Zadaj heslo uctu {self.meno}: ")
#         if heslo == self.heslo:
#             return super().vyber(suma)
#
#
# mbank = UcetHeslo('mbank', 'gigi')
# csob = Ucet('csob', 100)
# tatra = UcetHeslo('tatra', 'gogo', 17)
# sporo = Ucet('sporo', 50)
# mbank.vklad(sporo.vyber(30) + tatra.vyber(30))
# csob.vyber(-5)
# spolu = 0
# for ucet in mbank, csob, tatra, sporo:
#     print(ucet)
#     spolu += ucet.stav()
# print('spolu = ', spolu)

# uloha 5

# import turtle
# from random import randint
#
#
# class MojaTurtle(turtle.Turtle):
#     def __init__(self, x=0, y=0):
#         super().__init__()
#         self.speed(0)
#         self.pu()
#         self.setpos(x, y)
#         self.pd()
#
#     def domcek(self, dlzka):
#         for uhol in 90, 90, 90, 30, 120, -60:
#             self.fd(dlzka)
#             self.rt(uhol)
#
#
# zoznam = []
# x = -300
# y = 150
# for i in range(10):
#     zoznam.append(MojaTurtle(x, y))
#     x += 60
#
# for i in zoznam:
#     i.domcek(randint(30, 50))
#
# turtle.done()

# uloha 6

# import turtle
# from random import randint, choice
#
#
# class MojaTurtle(turtle.Turtle):
#     def __init__(self, x=0, y=0):
#         super().__init__()
#         self.speed(0)
#         self.pu()
#         self.setpos(x, y)
#         self.pd()
#
#     def domcek(self, dlzka):
#         for uhol in 90, 90, 90, 30, 120, -60:
#             self.fd(dlzka)
#             self.rt(uhol)
#
#
# class MojaTurtle1(MojaTurtle):
#     def fd(self, dlzka):
#         while dlzka >= 5:
#             self.lt(60)
#             super().fd(5)
#             self.rt(120)
#             super().fd(5)
#             self.lt(60)
#             dlzka -= 5
#         super().fd(dlzka)
#
#
# class MojaTurtle2(MojaTurtle):
#     def fd(self, dlzka):
#         super().fd(dlzka)
#         self.rt(180 - randint(-3, 3))
#         super().fd(dlzka)
#         self.rt(180 - randint(-3, 3))
#         super().fd(dlzka)
#
#
# zoznam = []
# x = -300
# y = 150
# for i in range(10):
#     zoznam.append(choice((MojaTurtle(x, y), MojaTurtle1(x, y), MojaTurtle2(x, y))))
#     x += 60
#
# for i in zoznam:
#     i.domcek(randint(30, 50))
#
# turtle.done()

# uloha 7

# import turtle
#
#
# class Turtle1(turtle.Turtle):
#     def trojuholnik(self, dlzka):
#         self.fd(dlzka)
#         self.lt(120)
#         self.fd(dlzka)
#         self.lt(120)
#         self.fd(dlzka)
#         self.lt(120)
#
#
# t = Turtle1()
# for i in range(5):
#     t.trojuholnik(150)
#     t.lt(72)
#
# turtle.done()

# uloha 8

# import turtle
# from random import randrange
#
#
# class Turtle1(turtle.Turtle):
#     def trojuholnik(self, dlzka):
#         self.fd(dlzka)
#         self.lt(60)
#         self.fd(10)
#         self.lt(60)
#         self.fd(dlzka)
#         self.lt(60)
#         self.fd(10)
#         self.lt(60)
#         self.fd(dlzka)
#         self.lt(60)
#         self.fd(10)
#         self.lt(60)
#
#
# class Turtle2(Turtle1):
#     def trojuholnik(self, dlzka):
#         self.fillcolor(f"#{randrange(256**3):06x}")
#         self.begin_fill()
#         super().trojuholnik(dlzka)
#         self.end_fill()
#
#
# t = Turtle2()
# for i in range(5):
#     t.trojuholnik(150)
#     t.lt(72)
#
# turtle.mainloop()

# uloha 9

# from tkinter import Canvas, mainloop
#
#
# class Pero:
#     canvas = None
#     sirka, vyska = 400, 300
#
#     def __init__(self, x=0, y=0):
#         if self.canvas is None:
#             self.canvas = Canvas(width=self.sirka, height=self.vyska)
#             self.canvas.pack()
#         self.x = x
#         self.y = y
#         self.stav = True
#
#     def pu(self):
#         self.stav = False
#
#     def pd(self):
#         self.stav = True
#
#     def setpos(self, x, y):
#         if self.stav:
#             self.canvas.create_line(self.x, self.y, x, y)
#         self.x = x
#         self.y = y
#
#
# p1 = Pero(100, 200)
# p1.setpos(200, 200)
# p1.setpos(200, 300)
# p1.setpos(100, 300)
# p1.setpos(100, 200)
#
# p2 = Pero(200, 150)
# p2.setpos(250, 150)
# p2.setpos(250, 100)
# p2.setpos(200, 100)
# p2.setpos(200, 150)
#
# mainloop()

# uloha 10

from math import sin, cos, radians
from tkinter import Canvas, mainloop


class Pero:
    canvas = None
    sirka, vyska = 400, 300

    def __init__(self, x=0, y=0):
        if self.canvas is None:
            self.canvas = Canvas(width=self.sirka, height=self.vyska)
            self.canvas.pack()
        self.x = x
        self.y = y
        self.stav = True

    def pu(self):
        self.stav = False

    def pd(self):
        self.stav = True

    def setpos(self, x, y):
        if self.stav:
            self.canvas.create_line(self.x, self.y, x, y)
        self.x = x
        self.y = y


class Korytnacka(Pero):
    def __init__(self, x=0, y=0):
        super().__init__(x, y)
        self.uhol = 0

    def lt(self, uhol):
        self.uhol += uhol

    def rt(self, uhol):
        self.uhol -= uhol

    def fd(self, dlzka):
        super().setpos(self.x+dlzka*cos(radians(self.uhol)), self.y+dlzka*sin(radians(self.uhol)))


t = Korytnacka(200, 150)
for i in range(1, 200, 2):
    t.fd(i)
    t.lt(89)
mainloop()
