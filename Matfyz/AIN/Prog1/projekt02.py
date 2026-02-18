# 2. zadanie: spirala
# autor: Peter Kendra
# datum: 16.10.2023

import tkinter
canvas = tkinter.Canvas()
canvas.pack()

values = input("")
acc = ""
count = 0
startova_dlzka, inkrement, sucet_dlzok = 0, 0, 0

for i in values:
    if i == " ":
        count += 1
        if count == 1:
            startova_dlzka = int(acc)
            acc = ""
            continue
        if count == 2:
            inkrement = int(acc)
            acc = ""
            continue

    acc += i

sucet_dlzok = int(acc)

a = startova_dlzka
b = sucet_dlzok
count = 0
while b > 0:
    b -= a
    a += inkrement
    count += 1

# x, y = 190, 130
# sucet = 0
# for i in range(count):
#     if i % 4 == 0:
#         if i == count-1:
#             canvas.create_line(x, y, x, y-(sucet_dlzok-sucet))
#             break
#         canvas.create_line(x, y, x, y-startova_dlzka)
#         y -= startova_dlzka
#         sucet += startova_dlzka
#         startova_dlzka += inkrement
#     elif i % 4 == 1:
#         if i == count-1:
#             canvas.create_line(x, y, x-(sucet_dlzok-sucet), y)
#             break
#         canvas.create_line(x, y, x-startova_dlzka, y)
#         x -= startova_dlzka
#         sucet += startova_dlzka
#         startova_dlzka += inkrement
#     elif i % 4 == 2:
#         if i == count-1:
#             canvas.create_line(x, y, x, y+(sucet_dlzok-sucet))
#             break
#         canvas.create_line(x, y, x, y+startova_dlzka)
#         y += startova_dlzka
#         sucet += startova_dlzka
#         startova_dlzka += inkrement
#     else:
#         if i == count-1:
#             canvas.create_line(x, y, x+(sucet_dlzok-sucet), y)
#             break
#         canvas.create_line(x, y, x+startova_dlzka, y)
#         x += startova_dlzka
#         sucet += startova_dlzka
#         startova_dlzka += inkrement

x, y = 190, 130
sucet = 0
for i in range(count):
    if i % 4 == 0:
        if i == count-1:
            canvas.create_line(x, y, x-(((sucet_dlzok-sucet)**2)/2)**(1/2), y-(((sucet_dlzok-sucet)**2)/2)**(1/2))
            break
        canvas.create_line(x, y, x-((startova_dlzka**2)/2)**(1/2), y-((startova_dlzka**2)/2)**(1/2))
        x -= ((startova_dlzka**2)/2)**(1/2)
        y -= ((startova_dlzka**2)/2)**(1/2)
        sucet += startova_dlzka
        startova_dlzka += inkrement
    elif i % 4 == 1:
        if i == count-1:
            canvas.create_line(x, y, x-(((sucet_dlzok-sucet)**2)/2)**(1/2), y+(((sucet_dlzok-sucet)**2)/2)**(1/2))
            break
        canvas.create_line(x, y, x-((startova_dlzka**2)/2)**(1/2), y+((startova_dlzka**2)/2)**(1/2))
        x -= ((startova_dlzka**2)/2)**(1/2)
        y += ((startova_dlzka**2)/2)**(1/2)
        sucet += startova_dlzka
        startova_dlzka += inkrement
    elif i % 4 == 2:
        if i == count-1:
            canvas.create_line(x, y, x+(((sucet_dlzok-sucet)**2)/2)**(1/2), y+(((sucet_dlzok-sucet)**2)/2)**(1/2))
            break
        canvas.create_line(x, y, x+((startova_dlzka**2)/2)**(1/2), y+((startova_dlzka**2)/2)**(1/2))
        x += ((startova_dlzka**2)/2)**(1/2)
        y += ((startova_dlzka**2)/2)**(1/2)
        sucet += startova_dlzka
        startova_dlzka += inkrement
    else:
        if i == count-1:
            canvas.create_line(x, y, x+(((sucet_dlzok-sucet)**2)/2)**(1/2), y-(((sucet_dlzok-sucet)**2)/2)**(1/2))
            break
        canvas.create_line(x, y, x+((startova_dlzka**2)/2)**(1/2), y-((startova_dlzka**2)/2)**(1/2))
        x += ((startova_dlzka**2)/2)**(1/2)
        y -= ((startova_dlzka**2)/2)**(1/2)
        sucet += startova_dlzka
        startova_dlzka += inkrement

tkinter.mainloop()
