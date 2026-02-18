# uloha 1

# x, y = "Bratislava", "Kosice"
#
# print(y[1] + x[4] + y[3] + x[-4] + y[-5])
# print(x[5:8] + 3 * x[3] + y[2:])
# print(y[:2] + x[-2:])
# print(x[1::2] + y[2::2] + x[2::3])
# print(x.replace('a', 'e') + y.replace('ic', 'm'))
# print((y + x).replace('i', '').replace('a', 'xa'))

# uloha 2

# def sucet(retazec):
#     sep = retazec.find('+')
#     return (int(retazec[:sep]) + int(retazec[sep+1:]))
#
# print(sucet("12+9"))
# print(sucet("987654321+99999"))

# uloha 3

# def sucet(retazec):
#     count = retazec.count('+')
#     val = 0
#
#     if count == 0:
#         return int(retazec)
#
#     for i in range(count):
#         sep = retazec.find('+')
#         val += int(retazec[:sep])
#         retazec = retazec[sep+1:]
#
#     return val + int (retazec)
#
#
# print(sucet("12+9"))
# print(sucet("987654321+99999"))
# print(sucet("1+2+3+4"))
# print(sucet("1234"))

# uloha 4

# def postupnost(start, koniec, krok = 1):
#     retazec = str(start)
#
#     for i in range(start + krok, koniec, krok):
#         retazec += str(f" {i}")
#
#     return retazec
#
#
# print(postupnost(5, 13))
# print(postupnost(13, 5, -2))

# uloha 5

# def rozsekaj(text, sirka):
#     retText = ""
#
#     while text != "":
#         retText += text[:sirka] + '\n'
#         text = text[sirka:]
#     return retText[:len(retText)-1]
#
# print((rozsekaj('Anicka dusicka, kde si bola', 10)))

# uloha 6

# def stvorec(n, znak):
#     return n*znak+'\n' + (n-2)*(znak+(n-2)*' '+znak+'\n') + n*znak
#
#
# print(stvorec(5, '#'))

# uloha 7

# def vyhod_duplikaty(retazec):
#     retStr = ""
#
#     for i in range(len(retazec)-1):
#         if retazec[i] == retazec[i+1]:
#             continue
#         retStr += retazec[i]
#
#     if retStr[len(retStr)-1] != retazec[len(retazec)-1]:
#         retStr += retazec[len(retazec)-1]
#
#     return retStr
#
#
# print(vyhod_duplikaty("Braatisssllavaaaaa"))

# uloha 8

# def ozatvorkuj(retazec, podretazec):
#     return retazec.replace(podretazec, '('+podretazec+')')
#
#
# print(ozatvorkuj("Bratislava", 'a'))
# print((ozatvorkuj("prospešné programovanie v prologu", "pro")))

# uloha 9

# from random import randrange
# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
# a = 0x2654
# x, y = 50, 125
#
# for i in range(6):
#     c.create_text(x, y, text=chr(a), fill=f"#{randrange(256**3):06x}", font="arial 50")
#     a += 1
#     x += 60
#
# mainloop()

# uloha 10

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def stvorce(vel, retazec):
#     n = retazec.count(' ')
#     x, y = vel, 100
#
#     for i in range(n+1):
#         sep = retazec.find(' ')
#         if sep == -1:
#             c.create_rectangle(x - vel / 2, y - vel / 2, x + vel / 2, y + vel / 2, fill=retazec)
#             x += vel+5
#             continue
#
#         farba = retazec[:sep]
#         retazec = retazec[sep + 1:]
#         c.create_rectangle(x-vel/2, y-vel/2, x+vel/2, y+vel/2, fill=farba)
#         x += vel+5
#
#
# stvorce(40, "red blue purple red gold")
#
# mainloop()

# uloha 11

# sirka = 450
# from tkinter import Canvas, mainloop
# c = Canvas(width=sirka)
# c.pack()
#
#
# def stvorce(retazec):
#     text = retazec
#     x, y = 10, 150
#     vel = 0
#
#     while True:
#         if text == "":
#             text = retazec
#
#         sep = text.find(' ')
#         vel = int(text[:sep])
#         x += vel/2
#         if x+vel >= sirka:
#             break
#
#         text = text[sep+1:]
#         sep = text.find(' ')
#
#         if sep == -1:
#             color = text
#             c.create_rectangle(x-vel/2, y, x+vel/2, y-vel, fill=color)
#             x += vel/2 + 3
#             text = ""
#             continue
#
#         color = text[:sep]
#         text = text[sep+1:]
#
#         c.create_rectangle(x-vel/2, y, x+vel/2, y-vel, fill=color)
#         x += vel/2 + 3
#
#
# stvorce('40 red 20 blue 60 purple 40 red 30 gold')
#
# mainloop()


# uloha 12 + uloha 13

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def kresli(retazec):
#     x, y = 100, 100
#     control = True
#     iterations = 1
#     for i in range(len(retazec)):
#         x1, y1 = x, y
#         if retazec[i] == '1':
#             continue
#         if (retazec[i] == '2' or retazec[i] == '3' or retazec[i] == '4' or retazec[i] == '5' or retazec[i] == '6' or
#                 retazec[i] == '7' or retazec[i] == '8' or retazec[i] == '9'):
#             iterations = int(retazec[i])
#             continue
#
#         if retazec[i] == 's':
#             y1 -= 10*iterations
#             iterations = 1
#         elif retazec[i] == 'v':
#             x1 += 10*iterations
#             iterations = 1
#         elif retazec[i] == 'j':
#             y1 += 10*iterations
#             iterations = 1
#         elif retazec[i] == 'z':
#             x1 -= 10*iterations
#             iterations = 1
#         elif retazec[i] == 'h':
#             control = False
#         elif retazec[i] == 'd':
#             control = True
#         else:
#             print('nerozumiem "' + retazec[i] + '"')
#             return
#         if control:
#             c.create_line(x, y, x1, y1)
#         x, y = x1, y1
#
#
# #kresli("ssvvssvvjjzzjjjjvvssssvvjjzzzzzz")  # uloha 12
# kresli('4v4j4z4sh5vd'*5)                    # uloha 13
#
# mainloop()

# uloha 14

# def prevrat(retazec):
#     n = len(retazec) - 1
#     retStr = ""
#
#     for i in range(n, -1, -1):
#         retStr += retazec[i]
#
#     return retStr
#
# print(prevrat('tseb eht si nohtyP'))

# uloha 15

# def male(retazec, i):
#     a = ""
#
#     for j in range(len(retazec)):
#         if j == i:
#             a += retazec[i].lower()
#         else:
#             a += retazec[j]
#
#     return a
#
#
# def velke(retazec, i):
#     a = ""
#
#     for j in range(len(retazec)):
#         if j == i:
#             a += retazec[i].upper()
#         else:
#             a += retazec[j]
#
#     return a
#
# print(male('PYTHON', 3))
# print(velke('python', 5))

# uloha 16

# def riadky(retazec):
#     n = retazec.count('\n')
#
#     for i in range(n+1):
#         sep = retazec.find('\n')
#         if sep == -1:
#             print(f"{i + 1}. " + retazec)
#             continue
#         print(f"{i+1}. " + retazec[:sep])
#         retazec = retazec[sep+1:]
#
# riadky('prvy riadok\n\ntreti je posledny')
# riadky('len \\n jeden riadok')

# uloha 17

# def posun_znak(znak, posun):
#     c = ord(znak)
#
#     if 97 <= c <= 122:
#         if c+posun > 122:
#             return chr(c+posun-26)
#         elif c+posun < 97:
#             return chr(c+posun+26)
#         else:
#             return chr(c+posun)
#     else:
#         return znak
#
#
# print(posun_znak('c', 4))
# print(posun_znak('g', -4))
# print(posun_znak('x', 10))
# print(posun_znak('A', 10))
#
# # uloha 18 (nadvazuje na ulohu 17)
#
# def zakoduj(text, posun):
#     retazec = ""
#
#     for znak in text:
#         retazec += posun_znak(znak, posun)
#
#     return retazec
#
#
# print(zakoduj("pyThon", 10))
# print(zakoduj("pyThon", -10))
# print(zakoduj("pyThon", 16))

# uloha 19

# def je_palindrom(retazec):
#     retazec = retazec.replace(" ", "").lower()
#     text = ""
#
#     for znak in reversed(retazec):
#         text += znak
#
#     return text == retazec
#
#
#
# print(str(je_palindrom("Python")))
# print(str(je_palindrom("tahat")))
# print(str(je_palindrom("Tahat")))
# print(str(je_palindrom("Jelenovi Pivo Nelej")))

# uloha 20

# def pocet(retazec, podretazec):
#     count = 0
#     control = True
#
#     for i in range(len(retazec) - len(podretazec) + 1):
#         for j in range(len(podretazec)):
#             if retazec[i+j] != podretazec[j]:
#                 control = False
#                 break
#
#         if control:
#             count += 1
#
#         control = True
#
#     return count
#
#
# print(pocet('mama ma emu a ema ma mamu', 'ma '))
# print(pocet('mama ma emu a ema ma mamu', 'am'))

# uloha 21

def usporiadaj(h1, h2, h3):
    x1 = str(h1).lower()
    x2 = str(h2).lower()
    x3 = str(h3).lower()

    for i in range(len(x1)):
        if x1[i] > x2[i]:
            x1, x2 = x2, x1
            h1, h2 = h2, h1
            break
        elif x1[i] < x2[i]:
            break

    for i in range(len(x1)):
        if x1[i] > x3[i]:
            x1, x3 = x3, x1
            h1, h3 = h3, h1
            break
        elif x1[i] < x3[i]:
            break

    for i in range(len(x2)):
        if x2[i] > x3[i]:
            x2, x3 = x3, x2
            h2, h3 = h3, h2
            break
        elif x2[i] < x3[i]:
            break

    return f"{h1} {h2} {h3}"


print(usporiadaj('python', 'pytliak', 'pytagoras'))
print(usporiadaj("beton", "Cesta", "Ahoj"))
print(usporiadaj(345, 123, 234))

# uloha 22

# from random import choice
#
#
# def nazov(n):
#     samohlaska = choice('a' 'e' 'i' 'o' 'u' 'y')
#     spoluhlaska = choice('q' 'w' 'r' 't' 'z' 'p' 's' 'd' 'f' 'g' 'h' 'j' 'k' 'l' 'x' 'c' 'v' 'b' 'n' 'm')
#     return samohlaska + n*spoluhlaska + samohlaska
#
#
# for i in range(5):
#     print(nazov(2))
#     print(nazov(3))
