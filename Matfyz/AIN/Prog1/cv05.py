# # uloha 1

# def obdlznik(a, znak = '*'):
#     print(znak * a)
#     print(znak, " " * (a-4), znak)
#     print(znak * a)
#
# obdlznik(30, '#')
# obdlznik(6)
# obdlznik(19, 'O')

# uloha 2

# def riadok(n, text = ""):
#     if len(text) == 0:
#         print('*' * n)
#     else:
#         if len(text)%2 == 0:
#             print('*' * int((n-len(text)-2)/2), text, '*' * int((n-len(text)-2)/2))
#         else:
#             print('*' * int((n-len(text)-2)/2), text, '*' * int((n-len(text)-2)/2 + 1))
#
# sir = 40
# riadok(sir)
# riadok(sir, 'Ján Botto')
# riadok(sir, 'Žltá ľalija')
# riadok(sir, '-')
# riadok(sir, 'Stojí stojí mohyla')
# riadok(sir, 'Na mohyle zlá chvíľa')
# riadok(sir, 'na mohyle tŕnie chrastie')
# riadok(sir, 'a v tom tŕní chrastí rastie')
# riadok(sir)

# uloha 3

# def priemer(a, b):
#     return (a+b)/2
#
# print(priemer(1, 4))
# print(priemer(3.14, 31.4))

# uloha 4

# def nsn(a, b):
#     if a < b:
#         c = b
#     else:
#         c = a
#
#     while ((c%a != 0) or (c%b != 0)):
#         c += 1
#
#     return c
#
#
# a, b = 129, 162
# print(f'nsn({a}, {b}) =', nsn(a, b))
# a, b = 60, 168
# print(f'nsn({a}, {b}) =', nsn(a, b))

# uloha 5

# def fibonacci_medzi(a, b):
#     n1 = 0
#     n2 = 1
#
#     while (n1 < b):
#         if (n1 > a):
#             print(n1, end = " ")
#         n1, n2 = n2, n1+n2
#     print()
#
# fibonacci_medzi(10, 100)
# fibonacci_medzi(1000, 3000)

# uloha 6

# from math import sqrt
#
# def je_prvocislo(a):
#     control = True
#
#     for i in range(2,int(sqrt(a) + 1)):
#         if a%i == 0:
#             control = False
#             break
#
#     return control
#
# def dvojicky(a, b):
#     n1 = 0
#     n2 = 0
#
#     while not(je_prvocislo(a)):
#         a += 1
#     n1 = a
#
#     while n2 <= b:
#         a += 1
#
#         if je_prvocislo(a):
#             n2 = a
#             if(n2 - n1 == 2):
#                 print(n1, n2)
#             n1 = n2
#
# dvojicky(3, 50)
# dvojicky(1000000, 1000300)

# uloha 7

# def vyhod_medzery(text):
#     retText = ""
#
#     for i in text:
#         if i != ' ':
#             retText += i
#
#     return retText
#
# print(vyhod_medzery("  mám   rád Python "))
# print(vyhod_medzery("      "))

# uloha 8

# from random import randint
#
# def hadanie(od, do):
#     x = randint(od, do)
#     i = 1
#
#     print(f"Myslim si cislo od {od} do {do}, uhadni ho!")
#     while i <= 10:
#         tip = int(input("tvoj tip: "))
#
#         if tip == x:
#             print(f"uhadol si na {i}. pokus. Gratulujem.")
#             return
#         elif tip < x:
#             print("*** pridaj")
#             i += 1
#         else:
#             print("*** uber")
#             i += 1
#
#     print(f"neuhadol si ani na 10 pokusov\nmyslel som na cislo {x}.")
#
# hadanie (1, 100)

# uloha 9

# import tkinter
#
#
# def koleso(x, y, r=15, color="blue"):
#     canvas.create_oval(x-r, y-r, x+r, y+r, fill=color)
#
#
# def doska(x, y, a=100, b=20, color="red"):
#     canvas.create_rectangle(x-a/2, y-b, x+a/2, y, fill=color)
#
#
#
# def maly_vozik(x, y):
#     doska(x, y)
#     koleso(x - 30, y)
#     koleso(x + 30, y)
#
#
# def velky_vozik(x, y):
#     doska(x, y, 150, 40, 'green')
#     koleso(x - 35, y, 25, 'orange')
#     koleso(x + 35, y, 25, 'orange')
#
#
# canvas = tkinter.Canvas()
# canvas.pack()
#
# maly_vozik(200, 100)
# velky_vozik(150, 200)
# maly_vozik(300, 210)
#
# tkinter.mainloop()

# uloha 10

# from random import randint, randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def kruhy(x, y):
#     r = 50
#
#     for i in range(10):
#         c.create_oval(x-r, y-r, x+r, y+r, fill=f"#{randrange(256**3):06x}")
#         r -= 5
#
#
# for i in range(10):
#     kruhy(randint(50, 330), randint(50, 210))
#
# mainloop()

# uloha 11

# import random
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def karticka(x, y, text):
#     c.create_rectangle(x-50, y-20, x+50, y+20, fill="lightgrey")
#     c.create_text(x, y, text=text, font="arial 14")
#
#
# for i in range(10):
#     karticka(random.randint(50, 300), random.randint(50, 200), 'Python')
#
# mainloop()

# uloha 12

# from random import randrange, randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def dom(x, y, vel1, vel2):
#     c.create_rectangle(x, y, x+vel1, y-vel1, fill=f"#{randrange(256**3):06x}")
#     c.create_polygon(x,y-vel1, x+vel1,y-vel1, x+vel1/2,y-vel1-vel2, fill=f"#{randrange(256**3):06x}", outline="black")
#
#
# x, y = 10, 150
# while x < 330:
#     v = randint(20, 50)
#     dom(x, y, v, randint(v // 2, v))
#     x += v
#
# mainloop()

# uloha 13

# import math
# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def vzd(x1, y1, x2, y2):
#     return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
#
#
# def kresli_bodku(x, y, farba):
#     c.create_oval(x - 2, y - 2, x + 2, y + 2, fill=farba, width=0)
#
#
# def farebne_bodky(r, x1, y1, x2, y2, x3, y3):
#     for i in range(20000):
#         x = randint(10, 370)
#         y = randint(10, 260)
#
#         if vzd(x, y, x1, y1) < r-2:
#             if vzd(x, y, x2, y2) < r-2:
#                 if vzd(x, y, x3, y3) < r-2:
#                     kresli_bodku(x, y, "yellow")
#                 else:
#                     kresli_bodku(x, y, "darkblue")
#             elif vzd(x, y, x3, y3) < r-2:
#                 kresli_bodku(x, y, "darkblue")
#             else:
#                 kresli_bodku(x, y, "yellow")
#         elif vzd(x, y, x2, y2) < r-2:
#             if vzd(x, y, x3, y3) < r-2:
#                 kresli_bodku(x, y, "darkblue")
#             else:
#                 kresli_bodku(x, y, "yellow")
#         elif vzd(x, y, x3, y3) < r-2:
#             kresli_bodku(x, y, "yellow")
#         else:
#             kresli_bodku(x, y, "darkblue")
#
#
# farebne_bodky(80, 120, 120, 180, 110, 160, 170)
#
# mainloop()

# uloha 14

# from random import randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def rgb(r, g, b):
#     return f"#{r:02x}{g:02x}{b:02x}"
#
#
# def stv(riadok, stlpec, farba="white"):
#     c.create_rectangle(stlpec*30+5, riadok*30+5, stlpec*30+35, riadok*30+35, fill=farba, width=0)
#
#
# for i in range(8):
#     for j in range(12):
#         stv(i, j, rgb(255, 14*(i+j), 0))
#         # if i == j:
#         #     stv(i, j)
#         # else:
#         #     stv(i, j, f"#{randrange(256**3):06x}")
#
# mainloop()

# uloha 15

# import random
# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def vektor(x, y, dlzka, uhol):
#     x1 = x - dlzka * cos(radians(uhol))
#     y1 = y - dlzka * sin(radians(uhol))
#     x2 = x + dlzka * cos(radians(uhol))
#     y2 = y + dlzka * sin(radians(uhol))
#
#     c.create_line(x1, y1, x2, y2, arrow="last")
#
#
# for i in range(10):
#     vektor(random.randint(50, 300), random.randint(50, 200),
#            random.randint(10, 80), random.randint(0, 359))
#
# mainloop()

# uloha 16

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def slnko(n, x, y):
#     c.create_oval(x-40, y-40, x+40, y+40, fill="gold", width=0)
#
#     for i in range(n):
#         x1 = x + 70 * cos(radians((360/n) * (i+1)))
#         y1 = y + 70 * sin(radians((360/n) * (i+1)))
#         c.create_line(x, y, x1, y1, fill="gold", width=10)
#
#
# slnko(10, 100, 80)
# slnko(20, 250, 120)
#
# mainloop()

# uloha 17

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def vybodkuj_usecku(x1, y1, x2, y2, n):
#     xDif = (x1 - x2)/(n-1)
#     yDif = (y1 - y2)/(n-1)
#     for i in range(n):
#         c.create_oval(x1-i*xDif-3, y1-i*yDif-3, x1-i*xDif+3, y1-i*yDif+3, fill="blue")
#
#
# c.create_line(100, 80, 280, 120, fill='lightgray', width=11)
# vybodkuj_usecku(100, 80, 280, 120, 20)
# c.create_line(280, 120, 150, 200, fill='lightgray', width=11)
# vybodkuj_usecku(280, 120, 150, 200, 10)
# c.create_line(150, 200, 100, 80, fill='lightgray', width=11)
# vybodkuj_usecku(150, 200, 100, 80, 8)
#
# mainloop()

# uloha 18

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def n_uholnik(n, x0, y0, r):
#     uhol = 360/n
#     for i in range(n):
#         x1 = x0 + r * cos(radians(uhol * i))
#         y1 = y0 + r * sin(radians(uhol * i))
#         x2 = x0 + r * cos(radians(uhol * (i + 1)))
#         y2 = y0 + r * sin(radians(uhol * (i + 1)))
#         c.create_line(x1, y1, x2, y2)
#
#
# n_uholnik(3, 50, 50, 45)
# n_uholnik(4, 150, 50, 45)
# n_uholnik(5, 250, 50, 45)
#
# n_uholnik(6, 50, 150, 45)
# n_uholnik(7, 150, 150, 45)
# n_uholnik(8, 250, 150, 45)
#
# mainloop()

# uloha 19

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def n_hviezda(n, x0, y0, r, k=2):
#     uhol = 360/n
#     for i in range(n):
#         x1 = x0 + r * cos(radians(uhol * i))
#         y1 = y0 + r * sin(radians(uhol * i))
#         x2 = x0 + r * cos(radians(uhol * (i + k)))
#         y2 = y0 + r * sin(radians(uhol * (i + k)))
#         c.create_line(x1, y1, x2, y2)
#
# n_hviezda(5, 50, 50, 45)
# n_hviezda(7, 150, 50, 45)
# n_hviezda(7, 250, 50, 45, 3)
#
# n_hviezda(9, 50, 150, 45)
# n_hviezda(9, 150, 150, 45, 4)
# n_hviezda(11, 250, 150, 45, 4)
#
# mainloop()

# uloha 20

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def n_spirala(n, x0, y0, r):
#     uhol = 360 / n
#     rCurrent = 5
#     i = 0
#     while(rCurrent <= r):
#         x1 = x0 + rCurrent * cos(radians(uhol * i))
#         y1 = y0 + rCurrent * sin(radians(uhol * i))
#         x2 = x0 + (rCurrent+2) * cos(radians(uhol * (i + 1)))
#         y2 = y0 + (rCurrent+2) * sin(radians(uhol * (i + 1)))
#         c.create_line(x1, y1, x2, y2)
#         i += 1
#         rCurrent += 2
#
#
# # n_spirala(5, 190, 130, 125)
#
# n_spirala(3, 50, 50, 45)
# n_spirala(4, 150, 50, 45)
# n_spirala(5, 250, 50, 45)
#
# n_spirala(6, 50, 150, 45)
# n_spirala(7, 150, 150, 45)
# n_spirala(8, 250, 150, 45)
#
# mainloop()

# uloha 21

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def dolna(x0, y0, r):
#     uhol = 360/36
#     for i in range(18):
#         x1 = x0 + r * cos(radians(uhol * i))
#         y1 = y0 + r * sin(radians(uhol * i))
#         x2 = x0 + r * cos(radians(uhol * (i + 1)))
#         y2 = y0 + r * sin(radians(uhol * (i + 1)))
#         c.create_line(x1, y1, x2, y2)
#
#
# def horna(x0, y0, r):
#     uhol = 360/36
#     for i in range(18):
#         x1 = x0 - r * cos(radians(uhol * i))
#         y1 = y0 - r * sin(radians(uhol * i))
#         x2 = x0 - r * cos(radians(uhol * (i + 1)))
#         y2 = y0 - r * sin(radians(uhol * (i + 1)))
#         c.create_line(x1, y1, x2, y2)
#
#
# horna(30, 100, 30)
# dolna(90, 100, 30)
# horna(150, 100, 30)
# dolna(210, 100, 30)
# horna(270, 100, 30)
# dolna(330, 100, 30)
#
# for i in range(6):
#     horna(30+60*i, 200, 30)
#
# mainloop()

# uloha 22

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def rucicka(uhol, dlzka, hrubka, farba):
#     x = 190 + dlzka * cos(radians(uhol))
#     y = 130 + dlzka * sin(radians(uhol))
#
#     c.create_line(190, 130, x, y, fill=farba, width=hrubka, arrow="last")
#
#
# def hodinky(hod, min, sek):
#     c.create_oval(90, 30, 290, 230, fill="white")
#
#     for i in range(12):
#         x = 190 + 90 * cos(radians((360/12) * (i-2)))
#         y = 130 + 90 * sin(radians((360/12) * (i-2)))
#         c.create_text(x, y, text=str(i+1))
#
#     rucicka((360/12)*(hod-2), 60, 10, "gray")
#     rucicka((360/60)*(min-15), 70, 6, "black")
#     rucicka((360/60)*(sek-15), 80, 2, "red")
#
#
# # hodinky(8, 55, 10)
# import time
#
# while True:
#     c.delete('all')
#     h, m, s = time.localtime()[3:6]
#     hodinky(h, m, s)
#     c.update()
#     c.after(1000)
#
# mainloop()
