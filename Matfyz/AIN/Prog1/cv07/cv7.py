# uloha 1

# subor = open(input("zadaj meno suboru: "), "r")
# subor.readline()
# text = subor.readline()
#
# print(f"druhy riadok suboru: '{text[:len(text) - 1]}'")
# print(f"prve slovo: '{text[:text.find(' ')]}'")
# print(f"pocet medzier: {text.count(' ')}")
#
# subor.close()

# uloha 2

# def sirka(meno_suboru):
#     subor = open(meno_suboru, "r")
#
#     riadok = subor.readline()
#     count = len(riadok)
#
#     while riadok != "":
#         riadok = subor.readline()
#         if count < len(riadok):
#             count = len(riadok)
#
#     subor.close()
#     return count
#
#
# print(sirka("text1.txt"))
# print(sirka("text2.txt"))
# print(sirka("text3.txt"))

# uloha 3

# def najdlhsi_riadok(meno_suboru):
#     subor = open(meno_suboru, "r")
#     riadok = subor.readline()
#     count = len(riadok)
#     najdlhsi = riadok
#
#     while riadok != "":
#         riadok = subor.readline()
#         if count < len(riadok):
#             count = len(riadok)
#             najdlhsi = riadok
#
#     subor.close()
#     return najdlhsi
#
#
# print(najdlhsi_riadok('text1.txt'))
# print(najdlhsi_riadok('text2.txt'))
# print(najdlhsi_riadok('text3.txt'))

# uloha 4

# def tri_slova(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline()
#         slova = riadok.count(" ")
#
#         while riadok != "":
#             if slova == 2:
#                 print(riadok)
#             riadok = subor.readline()
#             slova = riadok.count(" ")
#
#
# tri_slova("text1.txt")
# tri_slova("text2.txt")
# tri_slova("text3.txt")

# TODO uloha 5

# def pocet_slov(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline().strip()
#         pocet = riadok.count(" ") + 1
#
#         while riadok != "":
#             riadok = subor.readline().strip()
#             pocet += riadok.count(" ") + 1
#
#         return pocet
#
#
# print(pocet_slov("text1.txt"))      #10
# print(pocet_slov("text2.txt"))      #62
# print(pocet_slov("text3.txt"))      #23

# uoha 6

# def zlomky(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline()
#         pocet = 0
#         sum = 0
#
#         while riadok != "":
#             if riadok.count("/") == 1:
#                 a = riadok[:riadok.find("/")]
#                 b = riadok[riadok.find("/")+1:]
#                 sum += (int(a)/int(b))
#             else:
#                 sum += int(riadok)
#             pocet += 1
#             riadok = subor.readline()
#
#         print(pocet)
#         print(f"{sum:.2f}")
#         print(f"{sum/pocet:.2f}")
#
#
# zlomky("cisla.txt")

# uloha 7

# def vypis_do_ramiku(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         longest = 0
#         riadok = subor.readline()
#         while riadok != "":
#             if longest < len(riadok):
#                 longest = len(riadok)
#             riadok = subor.readline()
#
#     with open(meno_suboru) as subor:
#         print("*" * (longest+3))
#         riadok = subor.readline()
#
#         while riadok != "":
#             print("* ", end="")
#             for znak in riadok:
#                 if znak == "\n":
#                     print(" ", end="")
#                 else:
#                     print(znak, end="")
#             print(" " * (longest-len(riadok)), end="")
#             print("*")
#             riadok = subor.readline()
#
#         print("*" * (longest+3))
#
#
# vypis_do_ramiku("text1.txt")
# vypis_do_ramiku("text2.txt")
# vypis_do_ramiku("text3.txt")

# uloha 8

# def posledny_riadok(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline()
#         to_print = ""
#
#         while riadok != "":
#             to_print = riadok
#             riadok = subor.readline()
#
#         return to_print
#
#
# def predposledny_riadok(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadky = 0
#         while subor.readline() != "":
#             riadky += 1
#
#     with open(meno_suboru) as subor:
#         riadok = subor.readline()
#         to_print = ""
#
#         while riadok != "":
#             if riadky % 2 == 1:
#                 riadok = subor.readline()
#                 if riadok == "":
#                     break
#                 to_print = riadok
#                 riadok = subor.readline()
#             else:
#                 riadok = subor.readline()
#                 riadok = subor.readline()
#                 if riadok == "":
#                     break
#                 to_print = riadok
#
#         return to_print
#
#
# print(posledny_riadok("text1.txt"))
# print(predposledny_riadok("text1.txt"))
# print(posledny_riadok("text2.txt"))
# print(predposledny_riadok("text2.txt"))
# print(posledny_riadok("text3.txt"))
# print(predposledny_riadok("text3.txt"))
# print(posledny_riadok("cisla.txt"))
# print(predposledny_riadok("cisla.txt"))

# uloha 9

# def ity_riadok(meno_suboru, index):
#     with open(meno_suboru, "r") as subor:
#         riadok = ""
#         for i in range(index+1):
#             riadok  = subor.readline()
#
#         return riadok
#
#
# print(ity_riadok("text3.txt", 3))
# print(ity_riadok("text1.txt", 100))

# uloha 10

# from tkinter import Canvas, mainloop
# c = Canvas()
# c. pack()
#
#
# def vykresli_text(meno_suboru, velkost = 16):
#     x, y = 10, 50
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline()
#         while riadok != "":
#             c.create_text(x, y, text=riadok, font=f"consolas {velkost}", anchor="nw")
#             y += velkost+2
#             riadok = subor.readline()
#
#
# vykresli_text("text3.txt")
# mainloop()

# uloha 11 + 12

# from tkinter import Canvas, mainloop
# c = Canvas()
# c. pack()
#
#
# def kresli(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         a = subor.readline()
#         b = ""
#
#         for riadok in subor:
#             if riadok == "\n":
#                 a = subor.readline()
#                 continue
#             b = riadok
#
#             c.create_line(int(a[:a.find(" ")]), int(a[a.find(" ")+1:]), int(b[:b.find(" ")]), int(b[b.find(" ")+1:]))
#             c.create_oval(int(a[:a.find(" ")])-3, int(a[a.find(" ")+1:])-3, int(a[:a.find(" ")])+3, int(a[a.find(" ")+1:])+3)
#             c.create_oval(int(b[:b.find(" ")])-3, int(b[b.find(" ")+1:])-3, int(b[:b.find(" ")])+3, int(b[b.find(" ")+1:])+3)
#             a = b
#
#
# kresli("body.txt")
# mainloop()

# uloha 13

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def vykresli_stvorce(meno_suboru, n=4):
#     count = 0
#     x, y = 22, 22
#
#
#     while True:
#         with open(meno_suboru, "r") as subor:
#             for farba in subor:
#                 if count == n*n:
#                     break
#
#                 c.create_rectangle(x-12, y-12, x+13, y+13, fill=farba.strip())
#                 x += 25
#                 count += 1
#                 if count % n == 0:
#                     x = 22
#                     y += 25
#
#         if count == n*n:
#             break
#
#
# vykresli_stvorce("farby.txt")
# mainloop()

# uloha 14

# from random import randint
#
#
# def nahodne_cisla(meno_suboru, pocet):
#     with open(meno_suboru, "w") as subor:
#         for i in range(pocet):
#             subor.write(f"{randint(100, 999)}\n")
#
#
# def zlomky(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         riadok = subor.readline()
#         pocet = 0
#         sum = 0
#
#         while riadok != "":
#             if riadok.count("/") == 1:
#                 a = riadok[:riadok.find("/")]
#                 b = riadok[riadok.find("/")+1:]
#                 sum += (int(a)/int(b))
#             else:
#                 sum += int(riadok)
#             pocet += 1
#             riadok = subor.readline()
#
#         print(pocet)
#         print(f"{sum:.2f}")
#         print(f"{sum/pocet:.2f}")
#
#
# nahodne_cisla("cisla1.txt", 5)
# zlomky("cisla1.txt")

# uloha 15

# def vyrob(meno_suboru, pocet, text):
#     with open(meno_suboru, "w") as skript:
#         skript.write("i = 0\n")
#         skript.write(f"while i < {pocet}:\n")
#         skript.write(f"\tprint('{text}')\n")
#         skript.write("\ti += 1\n")
#
#
# vyrob('skript.py', 20, 'Programujem v Pythone')

# uloha 16

# from random import randint
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def nahodne_body(meno_suboru, pocet):
#     with open(meno_suboru, "w") as subor:
#         for i in range(pocet):
#             subor.write(f"{randint(10, 370)} {randint(10, 250)}\n")
#
#
# def kresli(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         a = subor.readline()
#         b = ""
#
#         for riadok in subor:
#             if riadok == "\n":
#                 a = subor.readline()
#                 continue
#             b = riadok
#
#             c.create_line(int(a[:a.find(" ")]), int(a[a.find(" ")+1:]), int(b[:b.find(" ")]), int(b[b.find(" ")+1:]))
#             c.create_oval(int(a[:a.find(" ")])-3, int(a[a.find(" ")+1:])-3, int(a[:a.find(" ")])+3, int(a[a.find(" ")+1:])+3)
#             c.create_oval(int(b[:b.find(" ")])-3, int(b[b.find(" ")+1:])-3, int(b[:b.find(" ")])+3, int(b[b.find(" ")+1:])+3)
#             a = b
#
#
# nahodne_body("body3.txt", 20)
# kresli("body3.txt")
# mainloop()

# uloha 17

# from math import sin, cos, radians
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def body_na_kruznici(meno_suboru, n, r, x, y):
#     with open(meno_suboru, "w") as subor:
#         uhol = 360/n
#         for i in range(n+1):
#             x1 = x + r * cos(radians(uhol*(i+1)))
#             y1 = y + r * sin(radians(uhol*(i+1)))
#             subor.write(f"{x1} {y1}\n")
#
#
# def kresli(meno_suboru):
#     with open(meno_suboru, "r") as subor:
#         a = subor.readline()
#         b = ""
#
#         for riadok in subor:
#             if riadok == "\n":
#                 a = subor.readline()
#                 continue
#             b = riadok
#
#             c.create_line(float(a[:a.find(" ")]), float(a[a.find(" ")+1:]), float(b[:b.find(" ")]), float(b[b.find(" ")+1:]))
#             c.create_oval(float(a[:a.find(" ")])-3, float(a[a.find(" ")+1:])-3, float(a[:a.find(" ")])+3, float(a[a.find(" ")+1:])+3)
#             c.create_oval(float(b[:b.find(" ")])-3, float(b[b.find(" ")+1:])-3, float(b[:b.find(" ")])+3, float(b[b.find(" ")+1:])+3)
#             a = b
#
#
# body_na_kruznici("body4.txt", 20, 120, 250, 130)
# kresli("body4.txt")
# mainloop()

# uloha 18

# def pridaj(meno_suboru, text):
#     with open(meno_suboru, "a") as subor:
#         subor.write(f"\n{text}")
#
#
# pridaj("subor.txt", "predposledny")
# pridaj("subor.txt", "posledny")

# TODO uloha 19

def vyhod_riadok(meno_suboru, index):
    with open(meno_suboru, "r") as subor:
        i = 0
        text = ""
        for riadok in subor:
            if i == index:
                continue
            text += riadok
