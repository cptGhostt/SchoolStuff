# uloha 1

# def max(*param):
#     if len(param) == 0:
#         raise TypeError("max expected 1 arguments, got 0")
#
#     if len(param) == 1:
#         if type(param[0]) is list or type(param[0]) is tuple or type(param[0]) is set:
#             naj = param[0][0]
#             for i in param[0]:
#                 if i > naj:
#                     naj = i
#
#             return naj
#
#     naj = param[0]
#     for i in param:
#         if i > naj:
#             naj = i
#
#     return naj
#
#
# print(max(9, 13, 11))
# p = (9, 13, 11)
# print(max(p))
# print(max(*"python"))
# zoz = list('python')
# print(max(zoz))
# print(max((3, 'a'), (3, 'b'), (2, 'x')))
# print(max())

# uloha 2

# def spoj(*param):
#     for i in param:
#         if type(i) is not list:
#             return None
#
#     to_ret = []
#     for i in param:
#         to_ret += i
#
#     return to_ret
#
#
# print(spoj(['a', 1], [], [('b', 2)]))
# print(spoj())
# print(spoj(['a', 1], [], ('b', 2)))

# uloha 3

# def vypis(postupnost):
#     print(*postupnost, sep=", ")
#
#
# vypis([123, 'ahoj', (50, 120), 3.14])
# vypis(range(3, 10, 2))
# vypis('Python')

# uloha 4

# def retazec(postupnost):
#     return ", ".join(map(str, postupnost))
#
#
# print(retazec([123, 'ahoj', (50, 120), 3.14]))
# print(retazec(range(3, 10, 2)))

# uloha 5

# def aplikuj(*param):
#     vysledok = param[len(param) - 1]
#
#     for i in range(len(param)-1):
#         vysledok = param[i](vysledok)
#
#     # print(type(vysledok))
#     return vysledok
#
#
# print(aplikuj(float, int, str, '-314159e-3'))
# def rev(x): return x[::-1]
# print(aplikuj(str, rev, int, 1074))
# print(aplikuj(abs, lambda x: x+7, -17))

# uloha 6

# def max(*param, key=None):
#     if len(param) == 0:
#         raise TypeError("max expected 1 arguments, got 0")
#
#     if key is None:
#         if len(param) == 1:
#             if type(param[0]) is list or type(param[0]) is tuple or type(param[0]) is set:
#                 naj = param[0][0]
#                 for i in param[0]:
#                     if i > naj:
#                         naj = i
#
#                 return naj
#
#         naj = param[0]
#         for i in param:
#             if i > naj:
#                 naj = i
#
#         return naj
#     else:
#         if len(param) == 1:
#             if type(param[0]) is list or type(param[0]) is tuple or type(param[0]) is set:
#                 naj = param[0][0]
#                 after = key(param[0][0])
#                 for i in param[0]:
#                     if key(i) > after:
#                         naj = i
#                         after = key(i)
#
#                 return naj
#
#         naj = param[0]
#         after = key(param[0])
#         for i in param:
#             if key(i) > after:
#                 naj = i
#                 after = key(i)
#
#         return naj
#
#
# print(max(3, 7, 11, 4))
# print(max(3, 7, 11, 4, key=lambda x: -x))
# print(max([3, 7, 11, 4], key=str))

# uloha 7

# def najdlhsi(*retazec):
#     # to_ret = retazec[0]
#     # for i in retazec:
#     #     if len(i) > len(to_ret):
#     #         to_ret = i
#     #
#     # return to_ret
#
#     return max(retazec, key=len)
#
#
# print(najdlhsi('a', '', 'bc', 'd', 'ef'))
# print(najdlhsi(*'mam rad programovanie v pythone'.split()))

# uloha 8

# def map2(fun, param1, param2):
#     to_ret = []
#
#     if len(param1) < len(param2):
#         for i in range(len(param1)):
#             to_ret.append(fun(param1[i], param2[i]))
#     else:
#         for i in range(len(param2)):
#             to_ret.append(fun(param1[i], param2[i]))
#
#     return to_ret
#
#
# def f(x, y): return x * y
#
#
# print(map2(f, 'python', range(1, 6)))
# print(map2(f, ('a', 4, (1, 2)), [3, 5, 2]))

# uloha 9

# from tkinter import Canvas, mainloop
# c = Canvas()
# c.pack()
#
#
# def kruh(r, x, y, fill="red", **param):
#     c.create_oval(x - r, y - r, x + r, y + r, fill=fill, **param)
#
#
# kruh(100, 100, 100, outline='blue', width=1)
# kruh(30, 50, 100, width=3, fill='blue')
#
# mainloop()

# TODO uloha 10

# import turtle
#
#
# def vykonaj():
#     t = turtle.Turtle()
#     p = {'fd': t.fd, 'rt': t.rt, 'lt': t.lt}
#     while True:
#         prikaz, parameter = input('> ').split()
#         if p.get(prikaz) is None:
#             print(f"chybne meno prikazu '{prikaz}'")
#             continue
#         p[prikaz](int(parameter))
#
#
# vykonaj()
# turtle.done()

# uloha 11

# def mnozina(n):
#     # return {i**2 - 1 for i in range(1, n+1)}
#     return set(map(lambda x: x**2 - 1, range(1, n+1)))
#
#
# print(mnozina(4))

# uloha 12

# def prevrat_slova(veta):
#     return " ".join(map(lambda x: "".join([i for i in reversed(x)]), veta.split()))
#
#
# print(prevrat_slova('isiel macek do malacek'))

# uloha 13

# from random import randint
#
#
# def nahodne(n):
#     return [randint(0, 2*n-1) for i in range(n)]
#
#
# print(nahodne(4))

# uloha 14

# def matica(n, m, hodnota=0):
#     return [[hodnota] * m for i in range(n)]
#
#
# m = matica(3, 4, 1)
# print(m)
# m[0][2] = 7
# print(m)

# uloha 15

# from random import randrange
#
#
# def matica_nahodne(n, m, rozsah=2):
#     return [[randrange(rozsah) for j in range(m)] for i in range(n)]
#
#
# print(matica_nahodne(3, 4, 20))

# uloha 16

# def zadaj(text):
#     try:
#         return list(map(int, input(text).split()))
#     except ValueError:
#         return []
#
#
# print(zadaj('zadaj cisla: '))

# uloha 17

# def enumerate(postupnost):
#     return list(map(lambda x, y: (x, y), range(len(postupnost)), postupnost))
#
#
# print(enumerate('python'))

# TODO uloha 18

# def zip(*param):
#     return

# TODO uloha 19
