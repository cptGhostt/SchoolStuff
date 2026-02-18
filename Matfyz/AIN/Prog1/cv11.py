# uloha 1

# from tkinter import Button
# from turtle import *
# t = Turtle()
# t.pensize(3)
# t.pencolor("blue")
# t.fillcolor("red")
#
# def dopredu():
#     t.fd(50)
#
#
# def doprava():
#     t.rt(90)
#
#
# def dolava():
#     t.lt(18)
#
#
# Button(text="dopredu", command=dopredu).pack()
# Button(text="vpravo", command=doprava).pack()
# Button(text="vlavo", command=dolava).pack()
#
# mainloop()

# TODO uloha 2

#

# uloha 3

# from random import randint
# from tkinter import Button
# from turtle import *
# t = Turtle()
# t.pencolor("gold")
#
#
# def slnko(pocet, velkost):
#     uhol = 360/pocet
#     t.pensize(10)
#
#     t.dot(velkost)
#
#     for i in range(pocet):
#         t.fd(velkost)
#         t.bk(velkost)
#         t.rt(uhol)
#
#
# def nove():
#     a = randint(3, 20)
#     b = randint(20, 100)
#     t.clear()
#     slnko(a, b)
#
#
# slnko(12, 100)
# Button(text="nove slnko", command=nove).pack()
#
# mainloop()

# uloha 4

# from tkinter import Button, Entry
# from turtle import *
# t = Turtle()
# farby = ["blue", "yellow"]
#
#
# def terc(pocet):
#     velkost = pocet * 15
#     for i in range(pocet):
#         t.pencolor(farby[i % 2])
#         t.dot(velkost)
#         velkost -= 15
#
#
# def novy():
#     farby[0] = e1.get()
#     farby[1] = e2.get()
#     terc(20)
#
#
# terc(20)
# Button(text="prekresli", command=novy).pack()
# e1 = Entry()
# e1.pack()
# e2 = Entry()
# e2.pack()
#
# mainloop()

# uloha 5

# from tkinter import Button
# from random import randint
# from turtle import *
# t = Turtle()
# t.pu()
# t.setpos(-250, 0)
# t.pd()
#
#
# def strom(kmen, koruna):
#     t.lt(90)
#     t.pensize(15)
#     t.pencolor("brown")
#     t.fd(kmen)
#     t.pensize(40)
#     t.pencolor("green")
#     t.fd(koruna)
#     t.pu()
#     t.bk(kmen + koruna)
#     t.rt(90)
#     t.pd()
#
#
# def pridaj():
#     strom(randint(30, 60), randint(10, 40))
#     t.pu()
#     t.fd(50)
#     t.pd()
#
#
# def uber():
#     t.pu()
#     t.bk(50)
#     t.pd()
#
#     t.lt(90)
#     t.pencolor("white")
#     t.pensize(40)
#     t.fd(100)
#     t.bk(100)
#     t.rt(90)
#
#
# for i in range(8):
#     strom(randint(30, 60), randint(10, 40))
#     t.pu()
#     t.fd(50)
#     t.pd()
#
# Button(text="pridaj", command=pridaj).pack()
# Button(text="uber", command=uber).pack()
#
# mainloop()

# uloha 6

# from math import sqrt
# from tkinter import Scale
# from turtle import *
# t = Turtle()
#
#
# def spirala(d, krok, uhol):
#     delay(0)
#     t.speed(0)
#     t.ht()
#
#     kde = t.pos()
#     pocet = 0
#     dlzka = d
#
#     while pocet < 200 and sqrt(t.pos()[0]**2 + t.pos()[1]**2) <= 250:
#         t.fd(dlzka)
#         t.lt(uhol)
#         dlzka += krok
#         pocet += 1
#
#
# def rob(x):
#     t.reset()
#     delay(0)
#     t.speed(0)
#     t.ht()
#
#     spirala(50, 5, int(x))
#
#
# spirala(50, 5, 60)
# Scale(command=rob, orient='horizontal', from_=5, to=179, length=300).pack()
#
# mainloop()

# uloha 7

# from turtle import *
# t = Turtle()
#
#
# def kosostvorec(velkost, farba):
#     t.fillcolor(farba)
#     t.begin_fill()
#     t.fd(velkost)
#     t.lt(45)
#     t.fd(velkost)
#     t.lt(135)
#     t.fd(velkost)
#     t.lt(45)
#     t.fd(velkost)
#     t.lt(135)
#     t.end_fill()
#
#
# farby = ["tan", "tomato"]
#
# for i in range(8):
#     kosostvorec(100, farby[i % 2 - 1])
#     t.lt(360/8)
#
# mainloop()

# uloha 8

# from turtle import *
# from math import sqrt
# t = Turtle()
#
#
# def domcek(d):
#     t.fd(d)
#     t.lt(135)
#     t.fd(sqrt(2 * (d**2)))
#     t.lt(135)
#     t.fd(d)
#     t.lt(135)
#     t.fd(sqrt(2 * (d**2)))
#     t.lt(135)
#     t.fd(d)
#     t.rt(135)
#     t.fd(sqrt((d**2)/2))
#     t.rt(90)
#     t.fd(sqrt((d**2)/2))
#     t.rt(45)
#     t.fd(d)
#     t.lt(90)
#
#
# t.rt(5)
# domcek(100)
# domcek(50)
# domcek(80)
#
# mainloop()

# uloha 9

# from turtle import *
# t = Turtle()
#
#
# def polkruznica(velkost, smer):
#     if smer:
#         for i in range(18):
#             t.fd(velkost)
#             t.lt(10)
#     else:
#         for i in range(18):
#             t.fd(velkost)
#             t.rt(10)
#
#
# t.rt(-90)
# for i in range(10):
#     if i % 2 == 0:
#         polkruznica(3, False)
#     else:
#         polkruznica(3, True)
#
# mainloop()

# uloha 10

# from random import randrange
# from turtle import *
# t = Turtle()
#
#
# def polkruznica(velkost, smer):
#     t.fillcolor(f"#{randrange(256**3):06x}")
#     t.begin_fill()
#     if smer:
#         for i in range(18):
#             t.fd(velkost)
#             t.lt(10)
#     else:
#         for i in range(18):
#             t.fd(velkost)
#             t.rt(10)
#     t.end_fill()
#
#
# t.rt(-90)
# for i in range(10):
#     if i % 2 == 0:
#         polkruznica(3, False)
#     else:
#         polkruznica(3, True)
#
# for i in range(10):
#     if i % 2 == 1:
#         polkruznica(3, False)
#     else:
#         polkruznica(3, True)
#
# mainloop()

# uloha 11

# from random import randint
# from turtle import *
# t = Turtle()
# t.pencolor("salmon")
# t.pu()
# t.setpos(-300, 250)
# t.pd()
#
#
# def bodky(n, m):
#     kde = list(t.pos())
#
#     for i in range(n):
#         for j in range(m):
#             t.dot(randint(20, 35))
#             t.pu()
#             t.fd(30)
#             t.pd()
#         kde[1] -= 30
#         t.pu()
#         t.setpos(kde)
#         t.pd()
#
#
# bodky(10, 15)
#
# mainloop()

# uloha 12

# from random import randrange
# from turtle import *
# t = Turtle()
#
#
# def stvorce(dlzka, krok):
#     t.pu()
#
#     while dlzka > 0:
#         t.fillcolor(f"#{randrange(256**3):06x}")
#         t.begin_fill()
#         for i in range(4):
#             t.fd(dlzka)
#             t.rt(90)
#         t.end_fill()
#         dlzka -= krok
#         t.fd(krok / 2)
#         t.rt(90)
#         t.fd(krok / 2)
#         t.lt(90)
#
#
# stvorce(200, 25)
#
# mainloop()

# uloha 13

# from random import randrange
# from turtle import *
# t = Turtle()
#
#
# def veza(dlzka, krok):
#     t.pu()
#
#     while dlzka > 0:
#         t.fillcolor(f"#{randrange(256**3):06x}")
#         t.begin_fill()
#         for i in range(4):
#             t.fd(dlzka)
#             t.rt(90)
#         t.end_fill()
#         dlzka -= krok
#         t.fd(krok / 2)
#         t.lt(90)
#         t.fd(dlzka)
#         t.rt(90)
#
#
# veza(120, 30)
#
# mainloop()

# uloha 14

# from turtle import *
# t = Turtle()
# t.ht()
#
#
# def prerusovana_ciara(d):
#     for i in range(11):
#         if i % 2 == 0:
#             t.pd()
#             t.fd(d/11)
#         else:
#             t.pu()
#             t.fd(d/11)
#
#
# def cikcakova_ciara(d):
#     t.speed(0)
#     smer = t.heading()
#     t.lt(60)
#     for i in range(d//5):
#         t.fd(5)
#         t.rt(120)
#         t.fd(5)
#         t.lt(120)
#     t.setheading(smer)
#
# def dom(d):
#     # for i in range(4):
#     #     t.fd(d)
#     #     t.rt(90)
#     # t.lt(60)
#     # t.fd(d)
#     # t.rt(120)
#     # t.fd(d)
#
#     for i in range(4):
#         prerusovana_ciara(d)
#         t.rt(90)
#     t.lt(60)
#     prerusovana_ciara(d)
#     t.rt(120)
#     prerusovana_ciara(d)
#
#     # for i in range(4):
#     #     cikcakova_ciara(d)
#     #     t.rt(90)
#     # t.lt(60)
#     # cikcakova_ciara(d)
#     # t.rt(120)
#     # cikcakova_ciara(d)
#
#
# dom(100)
#
# mainloop()

# uloha 15

# from random import randrange
# import math
# from turtle import *
# t = Turtle()
#
#
# def pytagoras(prepona, uhol):
#     o1 = prepona * math.cos(math.radians(uhol))
#     o2 = prepona * math.sin(math.radians(uhol))
#
#     t.fillcolor(f"#{randrange(256**3):06x}")
#     t.begin_fill()
#     for i in range(4):
#         t.fd(prepona)
#         t.rt(90)
#     t.end_fill()
#
#     t.lt(uhol)
#     t.fillcolor(f"#{randrange(256 ** 3):06x}")
#     t.begin_fill()
#     for i in range(4):
#         t.fd(o1)
#         t.lt(90)
#     t.end_fill()
#     t.pu()
#     t.fd(o1)
#     t.pd()
#
#     t.rt(90)
#     t.fillcolor(f"#{randrange(256 ** 3):06x}")
#     t.begin_fill()
#     for i in range(4):
#         t.fd(o2)
#         t.lt(90)
#     t.end_fill()
#
#     print(f"stvorec nad preponou = {prepona**2}")
#     print(f"stvorec nad 1. odvesnou = {o1**2}")
#     print(f"stvorec nad 2. odvesnou = {o2**2}")
#     print(f"sucet = {o1**2 + o2**2}")
#
#
# pytagoras(150, 17)
#
# mainloop()

# uloha 16

# from random import randrange
# import math
# from turtle import *
# t = Turtle()
#
#
# def troj(rameno, uhol):
#     t.fillcolor(f"#{randrange(256**3):06x}")
#     t.begin_fill()
#     t.fd(rameno)
#     a = t.pos()
#     t.bk(rameno)
#     t.rt(uhol)
#     t.fd(rameno)
#     b = t.pos()
#     t.lt((180 - uhol) / 2 + uhol)
#     t.fd(math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2))
#     t.end_fill()
#     t.bk(math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2))
#     t.rt((180 - uhol) / 2 + uhol)
#     t.bk(rameno)
#     t.lt(uhol)
#
#
# for i in range(36):
#     t.speed(0)
#     troj(300, 10)
#     t.rt(10)
#
# mainloop()

# uloha 17

# import math
# from turtle import *
# t = Turtle()
#
#
# def kruznica(r):
#     smer = t.heading()
#     t.pu()
#     t.fd(r)
#     t.pd()
#     t.rt(95)
#
#     for i in range(36):
#         t.fd((2 * math.pi * r) / 36)
#         t.rt(10)
#
#     t.lt(95)
#     t.pu()
#     t.bk(r)
#     t.pd()
#
#
#
#
# t.dot(200, 'yellow')
# kruznica(100)
# t.pu()
# t.fd(120)
# t.lt(90)
# t.fd(100)
# t.rt(37)
# t.pd()
# t.dot(140, 'gold')
# kruznica(70)
#
# mainloop()

# TODO uloha 18

#

# TODO uloha 19

# 
