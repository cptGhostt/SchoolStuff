# uloha 1

# start = int(input("zadaj km prvy den: "))
# finish = int(input("zadaj cielove km: "))
# days = 1
#
# while start<finish:
#     days += 1
#     start *= 1.10
#
# print(f"na {days}. prebehne {start:.2f} km")

# uloha 2

# n = int(input("zadaj cislo: "))
# print(f"{n}", end = "")
#
# while n != 1:
#     if n%2 == 0:
#         n /= 2
#     else:
#         n = n*3 + 1
#     print(f", {int(n)}", end = "")

# uloha 3

# sum = 0
# n = 1
# count = 1
#
# while n != 0:
#     n = float(input(f"zadaj {count}. cislo: "))
#     count += 1
#     sum += n
#
# print(f"sucet vsetkych precitanych cisel je {sum}")

# uloha 4

# n = int(input("zadaj cislo: "))
# div = 2
# count = 1
#
# print(f"{n} = ", end = "")
#
# while n != 1:
#     if n%div == 0:
#         n /= div
#         if count == 1:
#             print(f"{div}", end = "")
#             count += 1
#         else:
#             print(f" * {div}", end = "")
#     else:
#         div += 1

# uloha 5

# n = int(input("zadaj cislo: "))
# sum = 0
#
# while n != 0:
#     print(f"{int(n%10)}")
#     sum += (int(n%10))
#     n //= 10
#
# print("ciferny sucet =", sum)

# uloha 6

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj cislo: "))
# x, y = 330, 100
#
# while n != 0:
#     z = int(n%10)
#     c.create_rectangle(x, y, x+35, y+35, fill = "lightblue")
#     c.create_text(x+35/2, y+35/2, text = str(z), font = "arial 26")
#     x -= 40
#     n //= 10
#
# mainloop()

# uloha 7

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# #num = oct(int(input("zadaj cislo: ")))         # riadok pre osmickove cislo
# num = bin(int(input("zadaj cislo: ")))          # riadok pre dvojkove cislo
# s = ""
# n = 0
# count = 0
# x, y = 330, 100
#
#
# for i in num:
#     if count < 2:
#         count += 1
#         continue
#     else:
#         s += str(i)
#
# n = int(s)
#
# while n != 0:
#     z = int(n%10)
#     c.create_rectangle(x, y, x+35, y+35, fill = "lightblue")
#     c.create_text(x+35/2, y+35/2, text = str(z), font = "arial 26")
#     x -= 40
#     n //= 10
#
# mainloop()

# uloha 8

# import tkinter
#
# canvas = tkinter.Canvas()
# canvas.pack()
#
# n = 10
# for i in range(n):
#     for j in range(n):
#         x = j*20 + 100
#         y = i*20 + 12
#         if i == n//2 or j == n//2:           # uloha A
#         #if i == j or i+j == n-1:        # uloha B
#             farba = 'red'
#         else:
#             farba = 'white'
#         canvas.create_oval(x - 8, y - 8, x + 8, y + 8, fill=farba)
#
# tkinter.mainloop()

# uloha 9

# print("zadavaj vysky ziakov")
# n1 = input("\tvyska 1. ziaka: ")
# n2 = "abc"
# count = 2
# control = True
# if n1 == "":
#     print("neboli zadany ziadny ziaci")
#
# while True:
#     n2 = input(f"\tvyska {count}. ziaka: ")
#     if n2 == "":
#         break
#     count += 1
#     if int(n1) > int(n2):
#         control = False
#     n1 = n2
#
# if control:
#     print("vsetci ziaci su zoradeni spravne")
# else:
#     print("ziaci nie su zoradeni spravne")

# uloha 10

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# x, y = 190, 130
# r = 120
# k = 6
# count = 1
#
# while r >= 15:
#     farba = "black"
#     if count%k == 0:
#         farba = "grey"
#
#     c.create_oval(x-r/2, y-r/2, x+r/2, y+r/2, outline = farba)
#     r -= 3
#     count += 1
#
# mainloop()

# uloha 11

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# y = 20
# k = 21
#
# for i in range(10):
#     x = 20
#     sum = 0
#     while sum < k:
#         no = randint(1, 4)
#         sum += no
#         c.create_oval(x-11, y-11, x+11, y+11, fill = "white")
#         c.create_text(x, y, text = f"{no}", font = "arial 15")
#         x += 25
#
#     if sum == k:
#         c.create_text(350, y, text = "HURA", fill = "green", font = "arial 12")
#     else:
#         c.create_text(350, y, text = "SKODA", fill = "red", font = "arial 12")
#     y += 25
#
# mainloop()

# uloha 12

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas(width = 300, height = 300)
# c.pack()
#
# for i in range(12000):
#     x = randint(0, 300)
#     y = randint(0, 300)
#
#     if (x >= 75+2 and x <= 225-3) and (y >= 75+2 and y <= 225-3):
#         farba = "red"
#     else:
#         farba = "blue"
#
#     c.create_oval(x-2, y-2, x+3, y+3, fill = farba, width = 0)
#
# mainloop()

# uloha 13

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas(width = 300, height = 300)
# c.pack()
#
# for i in range(12000):
#     x = randint(0, 300)
#     y = randint(0, 300)
#
#     if x > y:
#         if 300 - x < y:
#             farba = "yellow"
#         else:
#             farba = "blue"
#     else:
#         if 300 - y < x:
#             farba = "green"
#         else:
#             farba = "red"
#
#     c.create_oval(x-2, y-2, x+3, y+3, fill = farba, width = 0)
#
# mainloop()

# uloha 14

# from random import randint
# from math import sqrt
# from tkinter import Canvas, mainloop
# c = Canvas(width = 300, height = 300)
# c.pack()
#
# x0, y0 = 180, 130
# r = 110
#
# for i in range(12000):
#     x = randint(0, 300)
#     y = randint(0, 300)
#
#     if (sqrt((x0 - x)**2 + (y0 - y)**2) < r):
#         farba = "red"
#     else:
#         farba = "blue"
#
#     c.create_oval(x-2, y-2, x+3, y+3, fill = farba, width = 0)
#
# mainloop()

# uloha 15

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas(width = 300, height = 300)
# c.pack()
#
# red = 0
# all = 0
#
# for i in range(30000):
#     x = randint(0, 300)
#     y = randint(0, 300)
#
#     if (x*x + y*y <= 300*300):
#         farba = "red"
#         red += 1
#         all += 1
#     else:
#         farba = "blue"
#         all += 1
#
#     c.create_oval(x-1, y-1, x+1, y+1, fill = farba, width = 0)
#
# print(f"{(red/all*4):.4f}")
#
# mainloop()

# uloha 16

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = 7
# xMin, yMin = 380, 260
# xMax, yMax = 0, 0
#
# for i in range(n):
#     x = randint(10, 380)
#     y = randint(10, 260)
#
#     c.create_oval(x-3, y-3, x+3, y+3, fill = "red")
#
#     if x < xMin:
#         xMin = x
#     if y < yMin:
#         yMin = y
#     if x > xMax:
#         xMax = x
#     if y > yMax:
#         yMax = y
#
# c.create_rectangle(xMin, yMin, xMax, yMax, outline = "blue")
#
# mainloop()

# uloha 17

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# for i in range(20000):
#     x = randint(10, 350)
#     y = randint(10, 250)
#
#     if y < 90:
#         farba = "black"
#     elif y < 170:
#         farba = "red"
#     else:
#         farba = "gold"
#
#     c.create_oval(x-2, y-2, x+3, y+3, width = 0, fill = farba)
#
# mainloop()

# uloha 18

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# for i in range(30000):
#     x = randint(10, 350)
#     y = randint(10, 250)
#
#     if x < y and 260 - y > x:
#         farba = "blue"
#     elif y < 130:
#         farba = "white"
#     else:
#         farba = "red"
#
#     c.create_oval(x-2, y-2, x+3, y+3, width = 0, fill = farba)
#
# mainloop()

# uloha 19

# from random import randint
#
# eur = int(input("zacinam so sumou: "))
# print("start")
#
# for i in range(1000):
#     if eur == 0:
#         print()
#         break
#
#     a = randint(1, 20)
#     b = randint(1, 20)
#     c = randint(1, 20)
#
#     if a == b == c:
#         eur += 100
#         print("+100", end = "")
#     elif a == b or a == c or b == c:
#         eur += 5
#         print("+5", end = "")
#     else:
#         eur -= 1
#         print("-1", end = "")
#
#     if (i+1) % 35 == 0:
#         print()
#
# print(f"zostalo mi {eur} eur")

# uloha 20

# n = int(input("zadaj cislo: "))
#
# for i in (100, 50, 20, 10, 5, 2, 1):
#     if n >= i:
#         print(f"{n//i}-krat hodnota {i}")
#         n %= i

# uloha 21

# from math import log2
#
# n = int(input("zadaj cislo: "))
# od = 0
# do = n
# x = (od + do) / 2
#
# while abs(2**x - n) > 0.001:
#     if 2**x > n:
#         do = x
#     else:
#         od = x
#
#     x = (od + do) / 2
#
# print("mnou zisteny log2:", x)
# print("log2 pomocou funkcie z kniznice:", log2(n))

# TODO uloha 22

from random import randrange
from tkinter import Canvas, mainloop
can = Canvas()
can.pack()

a = 10, 100
b = 250, 10
c = 300, 250
color = f"#{randrange(256**3):06x}"

can.create_polygon(a, b, c, fill = color)

mainloop()
