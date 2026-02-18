# uloha 1

# n = int(input("zadaj n: "))
#
# for i in range(n):
#     print('*'*(i+1))

# uloha 2

# slovo = input("zadaj slovo: ")
# i = 1
#
# for pismeno in slovo:
#     print(pismeno*i)
#     i += 1

# uloha 3

# slovo = input("Zadaj slovo: ")
# s = ""
#
# for pismeno in slovo:
#     s += pismeno
#     print(s)

# uloha 4

# slovo = input("Zadaj slovo: ")
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     print("    "*(i%4) + slovo)

# uloha 5

# n = int(input("zadaj n: "))
#
# for i in range(7):
#     print(" "*(n-(i+1)) + "*"*(2*i+1))

# uloha 6

# n = int(input("Zadaj n: "))
#
# print(" "*(n-1) + "*")
# for i in range(n-2):
#     print(" "*(n-2-i) + "*" + "-"*(2*i+1) + "*")
# print("*"*(2*n-1))

# uloha 7

# cislo = input("zadaj cislo: ")
# sucet = 0
# i = 1
#
# for cifra in cislo:
#     print(str(i) + ". cifra: " + cifra)
#     i += 1
#     sucet += int(cifra)
# print("ciferny sucet je:", sucet)

# uloha 8

# n = int(input("zadaj n: "))
# retazec = ""
#
# for i in range(n):
#     retazec += '*'*(i+1) + ' '
#
# print(retazec)

# uloha 9

# od = int(input("zadaj od: "))
# do = int(input("zadaj do: "))
# retazec = ""
#
# for i in range(od, do+1):
#     retazec += '<' + str(i) + "> "
#
# print(retazec)

# uloha 10

# od = int(input("zadaj od: "))
# do = int(input("zadaj do: "))
#
# for i in range(od, do+1):
#     print(f"{i:3} {i**2:5} {i**3:7} {i**4:9}")

# uloha 11

# n = int(input("zadaj pocet: "))
# pi = 0
#
# for i in range(n):
#     pi += ((4/(2*i+1)) * ((-1)**i))
#
#
# print("pi =", pi)

# uloha 12

# samohlasky = input("zadaj samohlasky: ")
#
# for i in samohlasky:
#     print(f"S{i}d{i} m{i}ch{i} n{i} st{i}n{i}, s{i}d{i} {i} sp{i}")

# uloha 13

# od = int(input("zadaj od: "))
# do = int(input("zadaj do: "))
#
# print("     | ", end = '')
# for i in range(od, do+1):
#     print(f"{i:4}", end=' ')
# print()
#
# print("=====|=", end = '')
# for i in range(od, do+1):
#     print("====", end = '=')
# print()
#
# for i in range(od, do+1):
#     print(f"{i:4} |", end = ' ')
#     for j in range(od, do+1):
#         print(f"{i*j:4}", end = ' ')
#     print()

# uloha 14

# from math import sin, cos, radians
#
# od = int(input("zadaj od: "))
# do = int(input("zadaj do: "))
# krok = int(input("zadaj krok: "))
#
# for i in range(od, do+1, krok):
#     a = radians(i)
#     b = sin(a) ** 2
#     c = cos(a) ** 2
#     print(f"{i:3} sin**2={b:6.4f} cos**2={c:6.4f} sucet={b + c}")

# uloha 15

# from random import randint
#
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     a = randint(0, 100)
#     b = randint(0, 100)
#     print(f"Prvy bod na priamke je {a}, druhy bod {b}. Ich vzdialenost je {abs(a - b)}")

# uloha 16

# from random import randint
#
# ludia = 100
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     a = randint(0, 9)
#     b = randint(0, 9)
#     print(f"Vo vlaku bolo {ludia} ludi, {a} nastupila, {b} vystupilo. Zostalo {ludia + a - b}.")
#     ludia += (a-b)

# uloha 17

# from random import choice
#
# riadky = int(input("zadaj pocet riadkov: "))
# stlpce = int(input("zadaj pocet stlpcov: "))
#
# for i in range(riadky):
#     for j in range(stlpce):
#         print(choice("O-"), end = '')
#     print()

# uloha 18

# from random import randint
#
# n = int(input("zadaj n: "))
#
# for i in range(n):
#     a = randint(1, 6)
#     b = randint(1, 6)
#     print("na 1. kocke padla", a)
#     print("na 2. kocke padla", b)
#     print(f"ich sucet je {a+b}")
#     print("======================")

# uloha 19

# from random import randint
#
# n = int(input("zadaj n: "))
# kocky = int(input("zadaj pocet kociek: "))
#
# for i in range(n):
#     sucet = 0
#     for j in range(kocky):
#         a = randint(1, 6)
#         print(f"na {j+1}. kocke padla {a}")
#         sucet += a
#     print("ich sucet je", sucet)
#     print("======================")

# uloha 20

# n = int(input('zadaj n: '))
# for i in range(n):
#     for u in range(3):
#         for j in range(n):
#             print(f'{i*n + j + 1:2}', end=' ')
#         print("   ", end = '')
#     print()
