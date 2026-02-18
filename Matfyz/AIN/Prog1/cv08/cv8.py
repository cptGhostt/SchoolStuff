# uloha 1

# def vypis_typy(zoznam):
#     for prvok in zoznam:
#         print(prvok, "-", end=" ")
#         if type(prvok) == float or type(prvok) == int:
#             print("cislo")
#         elif type(prvok) == str:
#             print("retazec")
#         else:
#             print("iny typ")
#
#
# vypis_typy([12, 'x', None, 3.14, [], range(5), '123'])

# uloha 2

# def nakup(zoznam):
#     suma = 0
#     for i in range(0, len(zoznam), 2):
#         suma += (zoznam[i] * zoznam[i+1])
#
#     return suma
#
#
# print(nakup([3, 2.5, 0.5, 10, 1.2, 1.2]))

# uloha 3

# def sucin(zoznam):
#     suc = zoznam[0]
#     for i in range(1, len(zoznam)):
#         suc *= zoznam[i]
#
#     return suc
#
#
# print(sucin([2, 3, 5, 7, 11]))
# print(sucin(list(range(1, 11))))
# print(sucin([2] * 20))

# uloha 4

# def vypis_zoznam(zoznam, pocet=1):
#     count = 1
#     for i in zoznam:
#         print(i, end=" ")
#         if count % pocet == 0:
#             print()
#         count += 1
#
#
#
# vypis_zoznam(list(range(1, 19)), 4)
# vypis_zoznam(list("Python"), 2)
# vypis_zoznam(["prvy", "druhy", "treti"])

# uloha 5

# def spoj(zoznam, retazec=""):
#     if len(zoznam) > 0:
#         to_return = str(zoznam[0])
#     else:
#         to_return = ""
#     for i in range(1, len(zoznam)):
#         to_return += retazec+str(zoznam[i])
#
#     return to_return
#
#
# print(spoj(['12', 3, '456', '7'], '+'))
# print(spoj(['12', 3, '456', 7], ' <=> '))
# print(spoj([], '*'))
# print(spoj(list('python'), '*'))
# print(spoj(list(range(11, 20))))

# uloha 6

# def zacina(zoznam, zacina_retazcom):
#     to_return = []
#     for i in zoznam:
#         if i.count(zacina_retazcom) > 0:
#             to_return.insert(len(to_return), i)
#
#     return to_return
#
#
# print(zacina(['hela', 'adam', 'boris', 'adela', 'bobo', 'miso', 'hektor', 'borka', 'mino'], "mi"))
# print(zacina(['hela', 'adam', 'boris', 'adela', 'bobo', 'miso', 'hektor', 'borka', 'mino'], "bor"))
# print(zacina(['hela', 'adam', 'boris', 'adela', 'bobo', 'miso', 'hektor', 'borka', 'mino'], "b"))

# uloha 7

# def zostupne(zoznam):
#     for i in range(len(zoznam)-1):
#         if zoznam[i] < zoznam[i+1]:
#             return False
#     return True
#
#
# print(zostupne([5, 5, 4, 4, 4, 2, 1]))
# print(zostupne([5, 5, 4, 4, 1, 2, 1]))
# print(zostupne(['zu', 'ta', 'si', 'mu', 'el']))

# uloha 8

# def postupnost(start, koniec, krok=1.0):
#     to_return = []
#     if krok == 0:
#         return to_return
#     elif krok < 0:
#         while start > koniec:
#             to_return.insert(len(to_return), start)
#             start += krok
#     else:
#         while start < koniec:
#             to_return.insert(len(to_return), start)
#             start += krok
#     return to_return
#
#
# print(postupnost(3, 100, 7))
# print(postupnost(0, 3, 0.5))
# print(postupnost(1, 5, 0))
# print(postupnost(20, 0, -2))

# uloha 9

# def sucet(zoznam1, zoznam2):
#     if len(zoznam1) < len(zoznam2):
#         for i in range(len(zoznam1)):
#             zoznam2[i] = zoznam1[i] + zoznam2[i]
#         return zoznam2
#     else:
#         for i in range(len(zoznam2)):
#             zoznam1[i] += zoznam2[i]
#         return zoznam1
#
#
# print(sucet([1, 20, 3, 40], [10, 2, 30, 4]))
# print(sucet([2, 3, 4, 5, 6, 7], [10, 20, 30]))
# print(sucet([], [2, 3, 5, 7]))
# print(sucet(['1.', '2.', '3.', '4.'], list('python')))

# uloha 10

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def kresli_kruhy(zoznam, r):
#     x, y = 10+r, 100
#     for farba in zoznam:
#         c.create_oval(x-r, y-r, x+r, y+r, fill=farba)
#         x += 2*r
#
#
# kresli_kruhy(['red', 'red', 'blue', 'orange', 'green', 'yellow'], 20)
#
# mainloop()

# uloha 11

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def kresli_stvorce(zoznam):
#     x, y = 10, 250
#     for i in range(0, len(zoznam), 2):
#         c.create_rectangle(x, y, x+zoznam[i], y-zoznam[i], fill=zoznam[i+1])
#         x += zoznam[i]
#
#
# kresli_stvorce([50, 'red', 100, 'blue', 70, 'yellow', 120, 'pink'])
#
# mainloop()

# uloha 12

# from random import randint, randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def nahodny_zoznam(n, od, do):
#     to_return = []
#     for i in range(n):
#         to_return.append(randint(od, do))
#
#     return to_return
#
#
# def histogram(zoznam):
#     x, y = 10, 250
#     for i in zoznam:
#         c.create_rectangle(x, y, x+(360/len(zoznam)), y-i, fill=f"#{randrange(256**3):06x}")
#         x += 360/len(zoznam)
#
#
# zoz = nahodny_zoznam(20, 10, 240)
# print(zoz)
# histogram(zoz)
#
# mainloop()

# uloha 13

# from random import randrange, randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def nahodny_zoznam(n, od, do):
#     to_return = []
#     for i in range(n):
#         to_return.append(randint(od, do))
#
#     return to_return
#
#
# def kresli_polygon(zoznam_x, zoznam_y):
#     zoznam = []
#     for i in range(len(zoznam_x)):
#         zoznam.append(zoznam_x[i])
#         zoznam.append(zoznam_y[i])
#     c.create_polygon(zoznam, fill=f"#{randrange(256**3):06x}", outline="black")
#
#
# # kresli_polygon([50, 150, 120, 60, 220], [10, 50, 200, 120, 150])
# kresli_polygon(nahodny_zoznam(20, 10, 360), nahodny_zoznam(20, 10, 250))
#
# mainloop()

# uloha 14

# def replace_novy(zoznam, co, zaco):
#     to_return = []
#     for i in zoznam:
#         if i == co:
#             to_return.append(zaco)
#         else:
#             to_return.append(i)
#
#     return to_return
#
# zoz = [12, 13, 14, 13, 11, 14, 15, 13]
# print(replace_novy(zoz, 13, "x"))
# print(zoz)
# print(replace_novy([1, 2] * 10, 1, 9))

# uloha 15

# def replace(zoznam, co, zaco):
#     for i in range(len(zoznam)):
#         if zoznam[i] == co:
#             zoznam.pop(i)
#             zoznam.insert(i, zaco)
#
#
# zoz = [12, 13, 14, 13, 11, 14, 15, 13]
# print(zoz)
# replace(zoz, 13, "x")
# print(zoz)
#
# zoz = [1, 2] * 10
# print(zoz)
# replace(zoz, 1, 9)
# print(zoz)

# TODO uloha 16

#

# uloha 17

# def fibonacci(zoznam, n):
#     for i in range(n):
#         zoznam.append(zoznam[len(zoznam)-1] + zoznam[len(zoznam)-2])
#
#
# zoz = [0, 1]
# print(zoz)
# fibonacci(zoz, 10)
# print(zoz)
# fibonacci(zoz, 5)
# print(zoz)
# zoz = [0, -2]
# print(zoz)
# fibonacci(zoz, 10)
# print(zoz)

# TODO uloha 18

#

# uloha 19

# def zoznam_cifier(cislo):
#     tmp = []
#     to_return = []
#
#     while cislo > 0:
#         tmp.append(cislo % 10)
#         cislo //= 10
#
#     for i in reversed(tmp):
#         to_return.append(i)
#
#     return to_return
#
#
# print(zoznam_cifier(478632))
# print(zoznam_cifier(111111111 ** 2))

# uloha 20

# def cislo_zo_zoznamu(zoznam):
#     cislo = 0
#     for i in range(len(zoznam)):
#         cislo += (zoznam[i] * (10**(len(zoznam)-1))) / (10**i)
#
#     return int(cislo)
#
#
# print(cislo_zo_zoznamu(list(range(1, 10))))
# print(cislo_zo_zoznamu(zoznam_cifier(2 ** 20)))

# uloha 21

# def citaj_cisla(meno_suboru):
#     to_return = []
#
#     with open(meno_suboru, "r") as subor:
#         for riadok in subor:
#             to_return.append(int(riadok.strip()))
#
#     return to_return
#
#
# # print('123\n 45\n  678  \n-9 ', file=open('cisla.txt', 'w'))
# print(citaj_cisla("cisla.txt"))

# TODO uloha 22

#

# uloha 23

from math import sin, cos, radians
from tkinter import Canvas, mainloop
c = Canvas()
c.pack()


def stvorec(x, y, r, uhol):
    to_return = []
    for i in range(4):
        x1 = x + r * cos(radians((90 * (i+1)) + uhol))
        y1 = y + r * sin(radians((90 * (i+1)) + uhol))
        to_return.append(x1)
        to_return.append(y1)

    return to_return


c.create_polygon(stvorec(180, 130, 110, 20), fill='red')
c.create_polygon(stvorec(180, 130, 90, 45), fill='green')
c.create_polygon(stvorec(180, 130, 70, 70), fill='gold')
c.create_polygon(stvorec(180, 130, 50, 95), fill='blue')

mainloop()
