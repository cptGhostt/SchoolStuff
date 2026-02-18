# uloha 1

# from tkinter import Canvas, mainloop, Button
# c = Canvas()
# c.pack()
#
#
# def kresli(event):
#     c.create_line(event.x, event.y, event.x+100, event.y)
#
#
# def zmaz():
#     c.delete("all")
#
#
# c.bind("<B1-Motion>", kresli)
# # c.bind("<ButtonPress-3>", zmaz)
# Button(text="zmaz", command=zmaz).pack()
#
# mainloop()

# uloha 2

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
# r = 1
# farba = "yellow"
#
# def kresli(event):
#     global r, farba
#     c.create_oval(event.x-r, event.y-r, event.x+r, event.y+r, fill=farba)
#     r += 0.1
#
#
# def zmaz():
#     global r
#     r = 1
#     c.delete("all")
#
#
# def zmen():
#     global farba
#     farba = f"#{randrange(256**3):06x}"
#
#
# c.bind("<B1-Motion>", kresli)
# Button(text="zmaz", command=zmaz).pack()
# Button(text="zmen farbu", command=zmen).pack()
#
# mainloop()

# uloha 3

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
# x, y = 0, 0
# control = 0
#
#
# def klik(event):
#     global x, y, control
#     if control % 2 == 0:
#         x, y = event.x, event.y
#         control += 1
#     else:
#         c.create_rectangle(x, y, event.x, event.y, fill=f"#{randrange(256**3):06x}")
#         control += 1
#
#
# c.bind("<ButtonPress-1>", klik)
#
# mainloop()

# uloha 4

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
# xy = [(0, 0), (0, 0), (0, 0)]
# control = 0
#
#
# def klik(event):
#     global xy, control
#
#     if control == 0:
#         control += 1
#         xy[0] = (event.x, event.y)
#         c.create_text(xy[0], text="+")
#     elif control == 1:
#         control += 1
#         xy[1] = (event.x, event.y)
#         c.create_text(xy[1], text="+")
#     else:
#         xy[2] = (event.x, event.y)
#         c.create_text(xy[2], text="+")
#         c.create_polygon(xy, fill=f"#{randrange(256**3):06x}")
#         xy[0], xy[1] = xy[1], xy[2]
#
#
# c.bind("<ButtonPress-1>", klik)
#
# mainloop()

# uloha 5

# from random import randrange
# from math import sqrt
# from tkinter import *
# c = Canvas()
# c.pack()
#
# x, y = [], []
# control = 0
#
#
# def klik(event):
#     global x, y, control
#
#     if control < 3:
#         control += 1
#         x.append(event.x)
#         y.append(event.y)
#         c.create_text(event.x, event.y, text="+")
#     else:
#         x.append(event.x)
#         y.append(event.y)
#
#         if sqrt(((x[0] - x[len(x)-1])**2) + ((y[0] - y[len(y)-1])**2)) < 5:
#             suradnice = []
#             for i in range(len(x)):
#                 suradnice.append((x[i], y[i]))
#
#             c.create_polygon(suradnice, fill=f"#{randrange(256**3):06x}")
#             x.clear()
#             y.clear()
#             control = 0
#         else:
#             c.create_text(event.x, event.y, text="+")
#
#
# c.bind("<ButtonPress-1>", klik)
#
# mainloop()

# uloha 6

# from random import randrange
# from math import sqrt
# from tkinter import *
# c = Canvas()
# c.pack()
#
# x, y, last = [], [], []
# control = 0
# polygon = None
#
#
# def klik(event):
#     global x, y, control, polygon, last
#
#     if control < 3:
#         control += 1
#         x.append(event.x)
#         y.append(event.y)
#         c.create_text(event.x, event.y, text="+", tag="+")
#     else:
#         x.append(event.x)
#         y.append(event.y)
#
#         if sqrt(((x[0] - x[len(x)-1])**2) + ((y[0] - y[len(y)-1])**2)) < 5:
#             suradnice = []
#             for i in range(len(x)):
#                 suradnice.append((x[i], y[i]))
#
#             c.delete("+")
#             polygon = c.create_polygon(suradnice, fill=f"#{randrange(256**3):06x}", tag="poly")
#             x.clear()
#             y.clear()
#             control = 0
#             last = suradnice
#         else:
#             c.create_text(event.x, event.y, text="+", tag="+")
#
#
# def zmaz():
#     global x, y, control
#     c.delete("all")
#     x = []
#     y = []
#     control = 0
#
# def zmen_farbu():
#     global polygon
#     c.itemconfig(polygon, fill=f"#{randrange(256**3):06x}")
#
#
# def spat():
#     global polygon, last
#     c.delete(polygon)
#
#
# c.bind("<ButtonPress-1>", klik)
# Button(text="zmaz", command=zmaz).pack()
# Button(text="zmen farbu", command=zmen_farbu).pack()
# Button(text="spat", command=spat).pack()
#
# mainloop()

# uloha 7

# from tkinter import *
# c = Canvas()
# c.pack()
#
# x1, y1, x2, y2 = 100, 50, 200, 100
# farby = ['blue', 'red', 'green', 'yellow']
# c.create_rectangle(x1, y1, x2, y2, fill="yellow", tag="rectangle")
#
#
# def klik(event):
#     suradnice = c.coords("rectangle")
#     if suradnice[0] <= event.x <= suradnice[2] and suradnice[1] <= event.y <= suradnice[3]:
#         c.itemconfig("rectangle", fill=farby[0])
#         tmp = farby[0]
#         farby.pop(0)
#         farby.append(tmp)
#
#
# c.bind("<ButtonPress-1>", klik)
#
# mainloop()

# uloha 8

# from tkinter import *
# c = Canvas()
# c.pack()
#
# suradnice = []
#
#
# def klik(event):
#     tmp = len(suradnice)+1
#     c.create_text(event.x, event.y, text=str(tmp))
#     suradnice.append((event.x, event.y))
#
#
# def zmaz():
#     c.delete("all")
#     suradnice.clear()
#
#
# def kresli():
#     c.create_line(suradnice)
#
#
# c.bind("<ButtonPress-1>", klik)
# Button(text="zmaz", command=zmaz).pack()
# Button(text="nakresli ciaru", command=kresli).pack()
#
# mainloop()

# uloha 9

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
#
# def klik(event):
#     x_diff = event.x % 50
#     y_diff = event.y % 50
#     c.create_rectangle(event.x - x_diff, event.y - y_diff, event.x + (50 - x_diff), event.y + (50 - y_diff), fill=f"#{randrange(256**3):06x}")
#
#
# c.bind("<ButtonPress-1>", klik)
#
# mainloop()

# uloha 10

# from math import sqrt
# from tkinter import *
# c = Canvas()
# c.pack()
#
# r, x0, y0 = 120, 150, 130
# c.create_oval(x0-r, y0-r, x0+r, y0+r, fill="white", tag="kruh")
#
#
# def klik(event):
#     suradnice = c.coords("kruh")
#     if suradnice[0] <= event.x <= suradnice[2] and suradnice[1] <= event.y <= suradnice[3]:
#         r1 = abs(suradnice[0] - suradnice[2]) / 2
#         x1 = suradnice[0] + r
#         y1 = suradnice[1] + r
#         vzd = sqrt((x1 - event.x)**2 + (y1 - event.y)**2)
#         f = int(255 * vzd / r1)
#         c.itemconfig("kruh", fill=f"#{f:02x}{f:02x}{f:02x}")
#
#
#
# c.bind("<ButtonPress-1>", klik)
# c.bind("<B1-Motion>", klik)
#
# mainloop()

# uloha 11

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
# farba = "blue"
#
#
# def sprej(event):
#     global farba
#
#     for i in range(20):
#         x = randrange(event.x-30, event.x+31)
#         y = randrange(event.y-30, event.y+31)
#         c.create_oval(x-2, y-2, x+2, y+2, fill=farba, width=0)
#
#
# def zmen_farbu():
#     global farba
#     farba = f"#{randrange(256**3):06x}"
#     vypis["text"] = f"farba: {farba}"
#
#
# c.bind("<B1-Motion>", sprej)
# Button(text="zmen farbu", command=zmen_farbu).pack()
# vypis = Label(text='farba: blue')
# vypis.pack()
#
# mainloop()

# uloha 12

# from tkinter import *
# c = Canvas()
# c.pack()
#
# suradnice = [0, 0, 0, 0, 0]
#
#
# def start(event):
#     suradnice[0], suradnice[1] = event.x, event.y
#     suradnice[2], suradnice[3] = event.x, event.y
#     suradnice[4] = c.create_line(suradnice[:4], width=hrubka.get())
#
#
# def tahaj(event):
#     suradnice[2], suradnice[3] = event.x, event.y
#     c.coords(suradnice[4], suradnice[:4])
#
#
# c.bind("<ButtonPress-1>", start)
# c.bind("<B1-Motion>", tahaj)
# hrubka = Scale(orient='horizontal', from_=1, to=20)
# hrubka.pack()
#
# mainloop()

# uloha 13

# from random import randrange
# from tkinter import *
# c = Canvas()
# c.pack()
#
# suradnice = [0, 0, 0, 0]
# history = []
#
#
# def start(event):
#     suradnice[0], suradnice[1] = event.x, event.y
#     suradnice[2], suradnice[3] = event.x, event.y
#     history.append(c.create_rectangle(suradnice, fill=f"#{randrange(256**3):06x}"))
#     # history.append(c.create_oval(suradnice, fill=f"#{randrange(256 ** 3):06x}"))
#
#
# def tahaj(event):
#     suradnice[2], suradnice[3] = event.x, event.y
#     c.coords(history[len(history)-1], suradnice)
#
#
# def undo():
#     c.delete(history[len(history)-1])
#     history.pop()
#
#
# c.bind("<ButtonPress-1>", start)
# c.bind("<B1-Motion>", tahaj)
# Button(text="undo", command=undo).pack()
#
# mainloop()

# uloha 14

from math import sqrt
from tkinter import *
c = Canvas()
c.pack()

c.create_rectangle(100, 100, 150, 150, fill="red", tag="rectangle")


def drag(event):
    suradnice = c.coords("rectangle")


    if suradnice[0] <= event.x <= suradnice[2] and suradnice[1] <= event.y <= suradnice[3]:
        vzdialenost = sqrt((event.x - suradnice[0])**2 + (event.y - suradnice[1]))
        


c.bind("<B1-Motion>", drag)

mainloop()
