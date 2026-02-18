# uloha 1

# def mocnina(n, k):
#     if k == 0:
#         return 1
#     elif k % 2 == 1:
#         return n * mocnina(n, k-1)
#     else:
#         return mocnina(n, k//2) ** 2
#
#
# print(mocnina(2, 10000))
# print(2**10000)

# uloha 2

# def palindrom(retazec):
#     tmp = retazec.lower()
#     if len(tmp) == 0 or len(tmp) == 1:
#         return True
#     elif tmp[0] != tmp[len(tmp) - 1]:
#         return False
#     else:
#         return palindrom(tmp[1:len(tmp)-1])
#
#
# print(palindrom("JelenoviPivoNelej"))
# print(palindrom("JelenoviPzivoNelej"))

# uloha 3

# def nsd(a, b):
#     if b == 0:
#         return a
#     elif b > a:
#         return nsd(b, a)
#     else:
#         return nsd(b, a % b)
#
#
# print(nsd(24, 40))

# uloha 4

# def sucet(zoznam):
#     if len(zoznam) == 0:
#         return 0
#     elif len(zoznam) == 1:
#         return zoznam[0]
#     else:
#         return sucet(zoznam[:len(zoznam)//2]) + sucet(zoznam[len(zoznam)//2:])
#
#
# print(sucet([2, 4, 6, 8]))
# print(sucet(()))
# print(sucet(range(500)))
# print(sucet(range(2000)))

# TODO uloha 5

# def dva_sucty(zoznam):
#     a = 0
#     b = 0
#
#     if len(zoznam) == 0:
#         return [0, 0]
#     elif zoznam[0] < 0:
#         a += zoznam[0]
#         return [a + dva_sucty(zoznam[1:])[0], b + dva_sucty(zoznam[1:])[1]]
#     else:
#         b += zoznam[0]
#         return [a + dva_sucty(zoznam[1:])[0], b + dva_sucty(zoznam[1:])[1]]
#
#
# print(dva_sucty(range(-5, 7)))
# print(dva_sucty((0, 1, -2, 3, 4, -5, -6, 7)))
# # print(dva_sucty(list(range(100)) + list(range(0, -100, -1))))
# # print(dva_sucty([0]*1000+[1]+[0]*1000+[-1]+[0]*1000))

# uloha 6

# from turtle import *
# from tkinter import Scale
# t = Turtle()
#
# zoznam = ['red', 'blue', 'yellow', 'green']
#
#
# def strom(d):
#     t.fd(d)
#     if d > 10:
#         t.lt(40)
#         strom(d * 0.7)
#         t.rt(75)
#         strom(d * 0.6)
#         t.lt(35)
#     else:
#         t.dot(10, zoznam[0])
#         zoznam.append(zoznam[0])
#         zoznam.pop(0)
#     t.bk(d)
#
#
# def rob(a):
#     tracer(0)
#     t.clear()
#     strom(int(a))
#     tracer(1)
#
#
# t.lt(90)
# t.pu()
# t.fd(-200)
# t.pd()
# t.speed(0)
# strom(100)
#
# Scale(orient='horizontal', from_=10, to=200, command=rob).pack()
#
# mainloop()

# TODO uloha 7

#

# uloha 8

# from turtle import *
# from random import randrange
# from tkinter import Scale
# t = Turtle()
# t.speed(0)
# t.pu()
#
#
# def trojuholniky(n, a):
#     if n > 0:
#         if n == 1:
#             t.fillcolor(f"#{randrange(256 ** 3):06x}")
#             t.begin_fill()
#         for i in range(3):
#             t.fd(a)
#             t.lt(120)
#             trojuholniky(n - 1, a / 2)
#         if n == 1:
#             t.end_fill()
#
#
# def rob(a):
#     tracer(0)
#     t.clear()
#     trojuholniky(int(a), 300)
#     tracer(1)
#
#
# trojuholniky(4, 300)
# Scale(orient='horizontal', from_=1, to=7, command=rob).pack()
#
# mainloop()

# uloha 9

# from turtle import *
# t = Turtle()
#
#
# def vpisane3(n, a):
#     if n > 0:
#         for i in range(3):
#             t.fd(a)
#             t.lt(120)
#         t.pu()
#         t.fd(a/2)
#         t.pd()
#         t.lt(60)
#         vpisane3(n-1, a/2)
#         t.rt(60)
#         t.pu()
#         t.bk(a/2)
#         t.pd()
#
#
# vpisane3(4, 100)
#
# mainloop()

# uloha 10

# from turtle import *
# import math
# t = Turtle()
#
#
# def vpisane4(n, a):
#     if n > 0:
#         for i in range(4):
#             t.fd(a)
#             t.lt(90)
#         t.pu()
#         t.fd(a/2)
#         t.pd()
#         t.lt(45)
#         vpisane4(n - 1, math.sqrt((a/2)**2 + (a/2)**2))
#         t.rt(45)
#         t.pu()
#         t.bk(a/2)
#         t.pd()
#
#
# vpisane4(4, 100)
#
# mainloop()

# uloha 11

# from turtle import *
# t = Turtle()
#
#
# def kriziky4(n, a):
#     if n > 0:
#         for i in range(4):
#             t.fd(a)
#             t.lt(45)
#             kriziky4(n-1, a/3)
#             t.rt(45)
#             t.bk(a)
#             t.rt(90)
#
#
# t.speed(0)
# kriziky4(4, 100)
#
# mainloop()

# uloha 12

# from turtle import *
# t = Turtle()
#
#
# def kriziky(n, a, pocet):
#     if n > 0:
#         for i in range(pocet):
#             t.fd(a)
#             t.lt((360/pocet)/2)
#             kriziky(n - 1, a / 3, pocet)
#             t.rt((360/pocet)/2)
#             t.bk(a)
#             t.rt(360/pocet)
#
#
# t.speed(0)
# kriziky(4, 100, 5)
#
# mainloop()

# TODO uloha 13

from turtle import *
t = Turtle()


def troj3(n, a):
    if n > 0:
        t.lt(60)
        for i in range(3):
            t.fd(a)
            t.lt(120)

        t.rt(60)

        # for i in range(3):
        t.pu()
        t.fd(a/2)
        t.pd()
        troj3(n-1, a/2)
        t.pu()
        t.bk(a/2)
        t.lt(60)



troj3(2, 100)

mainloop()
