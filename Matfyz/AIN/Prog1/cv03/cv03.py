# uloha 1

# import tkinter
# canvas = tkinter.Canvas()
# canvas.pack()
#
# x = int(input("zadaj x: "))
# y = int(input("zadaj y: "))
# canvas.create_rectangle(x, y, x+100, y+100, fill = "red")
# canvas.create_rectangle(x+110, y, x+210, y+100, fill = "blue")
# canvas.create_text(x+50, y+50, text = "cerveny", font = "arial 20", fill = "yellow")
# canvas.create_text(x+160, y+50, text = "modry", font = "arial 20", fill = "yellow")
#
# tkinter.mainloop()

# uloha 2

# from random import randint, randrange
# import tkinter
# w = int(input("zadaj sirku: "))
# h = int(input("zadaj vysku: "))
# canvas = tkinter.Canvas(bg = "navy", width = w, height = h)
# canvas.pack()
#
# n = int(input("zadaj n: "))
# for i in range(n):
#     size = randint(10, 20)
#     canvas.create_text(randrange(w+1), randrange(h+1), text = "*", font = f"arial {size}", fill = "yellow")
#
# tkinter.mainloop()

# uloha 3

# import tkinter
# canvas = tkinter.Canvas()
# canvas.pack()
#
# x = int(input("zadaj x: "))
# y = int(input("zadaj y: "))
# a1 = int(input("zadaj a1: "))
# a2 = int(input("zadaj a2: "))
#
# canvas.create_rectangle(x, y, x+a1, y+a1, fill = "indian red")
# canvas.create_rectangle(x+((a1-a2)/2), y+((a1-a2)/2), x+((a1-a2)/2)+a2, y+((a1-a2)/2)+a2, fill = "light blue")
# canvas.create_text(x-5, y-5, text = "A")
# canvas.create_text(x+a1+5, y-5, text = "B")
# canvas.create_text(x+a1+5, y+a1+5, text = "C")
# canvas.create_text(x-5, y+a1+5, text = "D")
# canvas.create_text(x+a1+10, y+(a1/2), text = f"{a1}")
# canvas.create_text(x+(a1/2), y+a1-((a1-a2)/2)-7, text = f"{a2}")
#
# tkinter.mainloop()

# uloha 4

# from tkinter import *
# canvas = Canvas()
# canvas.pack()
#
# n = int(input("zadaj n: "))
#
# size = 10*n
# x, y = 25, 25
# f1, f2, f3 = "red", "blue", "yellow"
# for i in range(n):
#     canvas.create_rectangle(x, y, x+size, y+size, fill = f1)
#     size -= 10
#     x += 5
#     y += 5
#     f1, f2, f3 = f2, f3, f1
#
# mainloop()

# uloha 5

# from tkinter import *
# canvas = Canvas()
# canvas.pack()
#
# x, y = 20, 20
# w, h = 135, 90
#
# canvas.create_polygon(x,y, x+w,y, x+w, y+h, x,y+h, fill = "yellow")
# canvas.create_polygon(x,y, x+w,y, x+w, y+(2*(h/3)), x,y+(2*(h/3)), fill = "red")
# canvas.create_polygon(x,y, x+w,y, x+w ,y+(h/3), x,y+(h/3), fill = "black")
# canvas.create_rectangle(x, y, x+w, y+h)
#
# canvas.create_polygon(x+w+50,y, x+w+50+w,y, x+w+50+w,y+h, x+w+50,y+h, fill = "red")
# canvas.create_polygon(x+w+50,y, x+w+50+(2*(w/3)),y, x+w+50+(2*(w/3)),y+h, x+w+50,y+h, fill = "white")
# canvas.create_polygon(x+w+50,y, x+w+50+(w/3),y, x+w+50+(w/3),y+h, x+w+50,y+h, fill = "green")
# canvas.create_rectangle(x+w+50, y, x+w+50+w, y+h)
#
# canvas.create_polygon(x,y+h+30, x+w,y+h+30, x+w,y+h+30+h, x,y+h+30+h, fill = "red")
# canvas.create_polygon(x,y+h+30, x+(2*(w/3)),y+h+30, x+(2*(w/3)),y+h+30+h, x,y+h+30+h, fill = "white")
# canvas.create_polygon(x,y+h+30, x+(w/3),y+h+30, x+(w/3),y+h+30+h, x,y+h+30+h, fill = "blue")
# canvas.create_rectangle(x, y+h+30, x+w, y+h+30+h)
#
# canvas.create_polygon(x+w+50,y+h+30, x+w+50+w,y+h+30, x+w+50+w,y+h+30+h, x+w+50,y+h+30+h, fill = "#FFD700")
# canvas.create_polygon(x+w+50,y+h+30, x+w+50+w,y+h+30, x+w+50+w,y+h+30+(h/2), x+w+50,y+h+30+(h/2), fill = "#0057B7")
# canvas.create_rectangle(x+w+50, y+h+30, x+w+50+w, y+h+30+h)
#
# mainloop()

# uloha 6

# from tkinter import *
# canvas = Canvas()
# canvas.pack()
#
# x, y = 80, 200
# width = 200
# for color in ("#006400", "#228B22", "#9ACD32", "#32CD32"):
#     canvas.create_rectangle(x, y, x + width, y + 50, fill = color)
#     y -= 50
#     x += 25
#     width -= 50
#
# mainloop()

# uloha 7

# from tkinter import *
# canvas = Canvas()
# canvas.pack()
#
# x, y = 10, 100
# d = 20
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     canvas.create_line(x, y, x+d, y+(d*((-1)**i)), fill = "blue", width = 3)
#     x += d
#     y += d*((-1)**i)
#
# mainloop()

# uloha 8

# from tkinter import *
# canvas = Canvas()
# canvas.pack()
#
# x, y = 70, 100
# r = 50
# dx, dy = 120, 60
# i = 1
#
# for color in ("blue", "yellow", "black", "lime green", "red"):
#     canvas.create_oval(x-r, y-r, x+r, y+r, outline = color, width = 15)
#     x += dx/2
#     y += dy*i
#     i *= -1
#
# mainloop()

# uloha 9

# from random import choice
# from tkinter import Canvas,mainloop
# canvas = Canvas()
# canvas.pack()
#
# n = int(input("zadaj n: "))
# spolu = 0
# x, y = 50, 20
# w, h = 50, 20
#
# for i in range(n):
#     hodnota = choice((1, 2, 5, 10, 20, 50))
#     spolu += hodnota
#     canvas.create_rectangle(x, y+(h*(i)), x+w, y+(h*(i+1)), fill = "white")
#     canvas.create_text(x+w/2, y+h/2+h*i, text = f"{hodnota} €", font = "arial 15")
#
# canvas.create_text(x+w*3, y+h*1.5, text = f"spolu = {spolu} €", font = "arial 15")
#
# mainloop()

# uloha 10

# from random import randint, randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj n: "))
# r = 20
#
# for i in range(n):
#     no = randint(1, 9)
#     x = randint(0, 340)
#     y = randint(0, 220)
#
#     c.create_oval(x, y, x+2*r, y+2*r, fill = f"#{randrange(256**3):06x}")
#     c.create_text(x+r, y+r, text = f"{no}",font = "arial 30", width = 5 )
#
# mainloop()

# uloha 11

# from random import randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# x, y = 5, 100
# text = input("zadaj text: ")
#
# for i in text:
#     c.create_rectangle(x, y, x+30, y+30, fill = f"#{randrange(256**3):06x}")
#     c.create_text(x+15, y+15, text = i, font = "arial 26", fill = f"#{randrange(256**3):06x}")
#     x += 30
#
# mainloop()

# uloha 12

# from random import randrange
# from tkinter import Canvas, mainloop
# c = Canvas(width = 380)
# c.pack()
#
# n = int(input("zadaj n: "))
# sirka = 370/n - 5
# x, y = 10, 50
#
# for i in range(n):
#     c.create_rectangle(x, y, x+sirka, y+sirka, fill = f"#{randrange(256**3):06x}")
#     x += (sirka+5)
#
# mainloop()

# uloha 13

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# x, y = 50, 250
# a = 280
# v = (a**2 - (a/2)**2)**(1/2)
#
# c.create_polygon(x,y, x+a,y, x+a/2,y-(v), fill = "blue")
#
# mainloop()

# uloha 14

# from random import randint, randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     x = randint(10, 320)
#     y = randint(50, 210)
#     a = randint(10, 50)
#     color = f"#{randrange(256**3):06x}"
#
#     c.create_rectangle(x, y, x+a, y+a, fill = color, outline = color)
#     color = f"#{randrange(256**3):06x}"
#     c.create_polygon(x,y, x+a,y, x+a/2,y-((a**2 - (a/2)**2)**(1/2)), fill = color)
#
# mainloop()

# uloha 15

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# sirka, vyska = 300,200
# x, y = 40, 30
#
# c.create_polygon(x,y, x+sirka,y, x+sirka,y+vyska, x,y+vyska, fill = "red")
# c.create_polygon(x,y, x+sirka,y, x+sirka,y+vyska/2, x,y+vyska/2, fill = "white")
# c.create_polygon(x,y, x,y+vyska, x+sirka/2,y+vyska/2, fill = "darkblue")
# c.create_rectangle(x, y, x+sirka, y+vyska)
#
# mainloop()

# uloha 16

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# riadky = int(input("zadaj pocet riadkov: "))
# stlpce = int(input("zadaj pocet stlpcov: "))
# vel = 30
# farba1, farba2 = "maroon", "gold"
# x, y = 5, 5
#
# for i in range(riadky):
#     for j in range(stlpce):
#         c.create_rectangle(x+(j*(vel+5)), y+(i*(vel+5)), x+(j*(vel+5))+vel, y+(i*(vel+5))+vel, fill = farba1)
#         farba1, farba2 = farba2, farba1
#     farba1, farba2 = farba2, farba1
#
# mainloop()

# uloha 17

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# x, y = 5, 5
#
# for i in range(25):
#     color = f"#{(255-(i*10)):02x}00{(0+(i*10)):02x}"
#     c.create_rectangle(x, y, x+15, y+250, fill = color, outline = color)
#     x += 15
#
# mainloop()

# uloha 18

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj n: "))
# r = int(input("zadaj r: "))
# x0, y0 = 180, 130
# x, y = x0 + r, y0
# uhol = 360/n
#
# for i in range(n):
#     x1 = x0 + r * cos(radians((i + 1) * uhol))
#     y1 = y0 + r * sin(radians((i + 1) * uhol))
#     c.create_line(x, y, x1, y1, width = 3)
#     x, y = x1, y1
#
# mainloop()

# uloha 19 (pridat tento for loop k predchadzajucej ulohe)

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj n: "))
# r = int(input("zadaj r: "))
# x0, y0 = 180, 130
# x, y = x0 + r, y0
# uhol = 360/n
#
# for i in range(n):
#     for j in range(n):
#         x1 = x0 + r * cos(radians((j + 1) * uhol))
#         y1 = y0 + r * sin(radians((j + 1) * uhol))
#         c.create_line(x, y, x1, y1)
#     x1 = x0 + r * cos(radians((i + 1) * uhol))
#     y1 = y0 + r * sin(radians((i + 1) * uhol))
#     x, y = x1, y1
#
# mainloop()

# uloha 20

# from math import sin, cos, radians, sqrt
# from random import randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# n = int(input("zadaj n: "))
# r = 100
# x0, y0 = 180, 130
# x, y = x0 + r, y0
# uhol = 360/n
#
# for i in range(n):
#     x1 = x0 + r * cos(radians((i + 1) * uhol))
#     y1 = y0 + r * sin(radians((i + 1) * uhol))
#     r1 = sqrt((x - x1)**2 + (y-y1)**2)
#     c.create_oval(x-r1/2, y-r1/2, x+r1/2, y+r1/2, fill = f"#{randrange(256**3):06x}")
#     x = x0 + r * cos(radians((i + 1) * uhol))
#     y = y0 + r * sin(radians((i + 1) * uhol))
#
# mainloop()

# uloha 21

from tkinter import Canvas, mainloop, PhotoImage
c = Canvas()
c.pack()

x, y = 30, 30
sir, vys = 325, 216
modra, cervena = "#0b4ea2", "#ee1c25"
sk = PhotoImage(file = "sk.png")

c.create_polygon(x,y, x+sir,y, x+sir,y+vys, x,y+vys, fill = cervena)
c.create_polygon(x,y, x+sir,y, x+sir,y+(2*(vys/3)), x,y+(2*(vys/3)), fill = modra)
c.create_polygon(x,y, x+sir,y, x+sir,y+(vys/3), x,y+(vys/3), fill = "white")
c.create_rectangle(x, y, x+sir, y+vys)
c.create_image(x+100, y+108, image = sk)

mainloop()
