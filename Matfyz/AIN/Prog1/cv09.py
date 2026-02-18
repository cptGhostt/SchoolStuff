# uloha 1

# def posun(zoznam):
#     a = zoznam[0]
#     zoznam.pop(0)
#     zoznam.append(a)
#
#
# a = [2, 3, 5, 7, 11]
# posun(a)
# print(a)
#
# zoz = 'kto druhemu jamu kope'.split()
# for i in range(5):
#         print(zoz)
#         posun(zoz)

# uloha 2

# def vyhod_none(ntica):
#     to_return = []
#     for i in ntica:
#         if i != None:
#             to_return.append(i)
#
#     return tuple(to_return)
#
#
# print(vyhod_none((None, 1, None, None)))

# uloha 3

# from random import randint
#
#
# def dve_kocky(pocet):
#     to_return = [0]*13
#
#     for i in range(pocet):
#         x = randint(1, 6)
#         y = randint(1, 6)
#         to_return[x+y] += 1
#
#     return to_return
#
#
# print(dve_kocky(1000))

# uloha 4

# def osmickova(cislo):
#     tmp = oct(cislo)
#     tmp = str(tmp)
#     tmp = list(tmp)
#     tmp.pop(0)
#     tmp.pop(0)
#
#     for i in range(len(tmp)):
#         tmp[i] = int(tmp[i])
#
#     return tmp
#
#
# print(osmickova(11213))

# uloha 5

# def dvojkova(cislo):
#     tmp = f"{cislo:b}"
#     tmp = list(tmp)
#
#     for i in range(len(tmp)):
#         tmp[i] = int(tmp[i])
#
#     return tmp
#
#
# print(dvojkova(11213))

# uloha 6

# def z_dvojkovej(zoznam):
#     tmp = ""
#     for i in zoznam:
#         tmp += str(i)
#     return int(tmp, 2)
#
#
# print(z_dvojkovej([1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1]))

# uloha 7

# from random import randrange
#
#
# def nahodne_body(pocet):
#     to_return = []
#     for i in range(pocet):
#         a = randrange(381), randrange(261)
#         to_return.append(a)
#     return to_return
#
#
# print(nahodne_body(5))

# uloha 8

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# a = nahodne_body(100)
# # c.create_line(a)
# c.create_line(sorted(a))
#
# mainloop()

# uloha 9

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def sort_y(zoznam):
#     tmp = []
#     for i in zoznam:
#         a = list(i)
#         a[0], a[1] = a[1], a[0]
#         tmp.append(a)
#     tmp.sort()
#
#     for i in tmp:
#         i[0], i[1] = i[1], i[0]
#
#     for i in range(len(zoznam)):
#         zoznam[i] = tuple(tmp[i])
#
#
# xy = [(100, 30), (200, 10), (300, 20)]
# print(xy)
# sort_y(xy)
# print(xy)
#
# a = nahodne_body(100)
# sort_y(a)
# c.create_line(a)
#
# mainloop()

# uloha 10

# def prerob(cislo):
#     a = str(cislo)
#     x = len(a) % 3
#     to_return = []
#     while len(a) > 0:
#         if x == 0:
#             x = 3
#         to_return.append(a[:x])
#         a = a[x:]
#         x = 3
#
#     return "_".join(to_return)
#
#
# print(prerob(1234567))
# print(prerob(12345678))
# print(prerob(123456789))

# uloha 11

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def sipka(xy1, xy2):
#     c.create_line(xy1, xy2, arrow="last", width=3)
#
#
# c.create_rectangle(150, 50, 250, 150, fill="gold")
# sipka((150, 50), (250, 50))
# sipka((250, 50), (250, 150))
# sipka((250, 150), (150, 150))
# sipka((150, 150), (150, 50))
#
# mainloop()

# uloha 12

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def sipka(xy1, xy2):
#     c.create_line(xy1, xy2, arrow="last", width=3)
#
#
# def vektor(xy, dlzka, uhol):
#     x1 = xy[0] + dlzka * cos(radians(uhol))
#     y1 = xy[1] + dlzka * sin(radians(uhol))
#     xy1 = x1, y1
#
#     sipka(xy, xy1)
#
#     return xy1
#
#
# poz = (200, 120)
# for uhol in range(0, 720, 144):
#     poz = vektor(poz, 100, uhol)
#
# mainloop()

# TODO uloha 13

#

# TODO uloha 14

#

# uloha 15

# def zadaj(pocet):
#     tmp = ""
#     while tmp.count(" ") != pocet-1:
#         tmp = input(f"zadaj {pocet} cisla: ")
#
#     tmp = tmp.split(" ")
#     to_return = []
#     for i in tmp:
#         to_return.append(int(i))
#
#     return tuple(to_return)
#
#
# print(zadaj(3))

# uloha 16

# def zisti(slovo1, slovo2):
#     a = sorted(list(slovo1.lower()))
#     b = sorted(list(slovo2.lower()))
#
#     return a == b
#
#
# print(zisti("Skola", "Lasko"))
# print(zisti('poobede', 'bopeodo'))

# uloha 17

# def vsetky_rozne(zoznam):
#     a = sorted(zoznam)
#
#     for i in range(len(a) - 1):
#         if a[i] == a[i+1]:
#             return False
#     return True
#
#
# print(vsetky_rozne([3, 8, 7, 9, 4, 1, 6, 10, 5, 2]))
# zoz = [3, 8, 7, 9, 4, 1, 6, 3, 10, 5, 2]
# print(zoz)
# print(vsetky_rozne(zoz))
# print(zoz)

# uloha 18

# def enum(postupnost):
#     to_return = []
#     for i in range(len(postupnost)):
#         a = i, postupnost[i]
#         to_return.append(a)
#
#     return tuple(to_return)
#
#
# print(enum([12, "dva", 3.14]))

# uloha 19

# def moj_zip(post1, post2):
#     to_return = []
#     if len(post1) < len(post2):
#         for i in range(len(post1)):
#             a = post1[i], post2[i]
#             to_return.append(a)
#     else:
#         for i in range(len(post2)):
#             a = post1[i], post2[i]
#             to_return.append(a)
#     return to_return
#
#
# print(moj_zip('python', [2, 3, 5, 7]))
# print(moj_zip([2, 3, 5, 7], "python"))

# uloha 20

# def enum(postupnost):
#     return moj_zip(range(len(postupnost)), postupnost)
#
#
# print(enum([12, "dva", 3.14]))

# uloha 21

# def od_zip(zoznam):
#     a = []
#     b = []
#     for i in zoznam:
#         a.append(i[0])
#         b.append(i[1])
#     return a, b
#
#
# z1, z2 = od_zip([(2, 'a'), ('h', 3), (5, 'o'), ('j', 7)])
# print(z1)
# print(z2)

# uloha 22

# def moj_zip(post1, post2):
#     to_return = []
#     if len(post1) < len(post2):
#         for i in range(len(post1)):
#             a = post1[i], post2[i]
#             to_return.append(a)
#     else:
#         for i in range(len(post2)):
#             a = post1[i], post2[i]
#             to_return.append(a)
#     return to_return
#
# # def do_dvojic(zoznam):
# #     to_return = []
# #     for i in range(0, len(zoznam), 2):
# #         a = zoznam[i], zoznam[i+1]
# #         to_return.append(a)
# #     return to_return
#
#
# def do_dvojic(zoznam):
#     return moj_zip(zoznam[::2], zoznam[1::2])
#
#
# print(do_dvojic(('11', 22, '3', 4)))

# uloha 23

from random import randrange


def pomiesaj(zoznam):
    for i in range(len(zoznam)):
        a = randrange(0, len(zoznam)-i)
        zoznam[a], zoznam[len(zoznam)-1-i] = zoznam[len(zoznam)-1-i], zoznam[a]


for i in range(4):
    p = list(range(1, 11))
    pomiesaj(p)
    print(p)
