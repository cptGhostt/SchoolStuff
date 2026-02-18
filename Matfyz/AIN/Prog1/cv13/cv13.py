# uloha 1

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# vypis([[1, 6, 3.14], [0.5, 1.5, 2.5]], 5)
# print()
# vypis([[1, 2, 3], [None, None], ['4', '5', '6'], ['Python', 3.9]], 4)
# print()
# vypis([[1, 2], [3, 4, 5, 6], [7, 8, 9]])
# print()
# vypis([[1, 2], [3, 4, 555, 6], [7, 8, 9]])
# print()
# vypis([[1, 2], [3, '4', 5, 6], [7, 8, -9]], 1)

# uloha 2

# def max2(tab):
#     to_return = -float("inf")
#     for i in tab:
#         if max(i) > to_return:
#             to_return = max(i)
#     return to_return
#
#
# def min2(tab):
#     to_return = float("inf")
#     for i in tab:
#         if min(i) < to_return:
#             to_return = min(i)
#
#     return to_return
#
#
# def sum2(tab):
#     to_return = 0
#     for i in tab:
#         to_return += sum(i)
#
#     return to_return
#
#
# p = [[1, 6, 3.14], [0.5, 1.5, 2.5]]
# q = [[0.5, 1.5, 2.5], [1, 6, 3.14]]
# print(max2(p), max2(q))
# print(min2(p), min2(q))
# print(sum2(p), sum2(q))
# r = [[-1, -2], [-3, -4]]
# print(max2(r))
# print(min2(r))
# print(sum2(r))

# uloha 3

# def zoznam_suctov(tab):
#     to_ret = []
#     index = 0
#     for i in tab:
#         if len(i) == 0:
#             to_ret.append(None)
#             index += 1
#             continue
#         elif type(i[0]) is str:
#             to_ret.append("")
#         elif type(i[0]) is tuple:
#             to_ret.append(tuple())
#         elif type(i(0)) is list:
#             to_ret.append(list())
#         else:
#             to_ret.append(0)
#         for j in i:
#             to_ret[index] += j
#
#         index += 1
#
#     return to_ret
#
#
# print(type("asd") is str)
# print(zoznam_suctov([[1, 2, 3], [4], [], [5, 6]]))
# print(zoznam_suctov([['1', 'x', '2'], [], [5, 6], [3.1, 4], [(5, 6), (7,)]]))

# uloha 4

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         if len(i) == 0:
#             print(None)
#             continue
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# def pridaj_sucty(tab):
#     for i in tab:
#         if len(i) == 0:
#             i = None
#             continue
#         elif type(i[0]) is str:
#             tmp = ""
#             for j in i:
#                 tmp += j
#             i.append(tmp)
#         elif type(i[0]) is tuple:
#             tmp = ()
#             for j in i:
#                 tmp += j
#             i.append(tmp)
#         elif type(i[0]) is list:
#             tmp = []
#             for j in i:
#                 tmp += j
#             i.append(tmp)
#         else:
#             i.append(sum(i))
#
#
# a = [[1, 2, 3], [4], [5, 6]]
# vypis(a)
# print()
# pridaj_sucty(a)
# vypis(a)
# print()
#
# t = [['1', 'x', '2'], [], [5, 6], [3.1, 4], [(5, 6), (7,)]]
# vypis(t)
# print()
# pridaj_sucty(t)
# vypis(t)
# print()

# uloha 5

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         if len(i) == 0:
#             print(None)
#             continue
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# def preklop(tab):
#     to_ret = []
#
#     for i in range(len(tab[0])):
#         to_ret.append([])
#
#     for i in range(len(to_ret)):
#         for j in tab:
#             to_ret[i].append(j[i])
#
#     return to_ret
#
#
# p = [[1, 2], [5, 6], [3, 4]]
# vypis(preklop(p), 2)
# print()
# vypis(p, 2)

# uloha 6

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# def ocisluj2(tab, start=0):
#     najdlhsi = 0
#     for i in tab:
#         if len(i) > najdlhsi:
#             najdlhsi = len(i)
#
#     index = 0
#     curr = start
#     while index < najdlhsi:
#         for i in tab:
#             if index < len(i):
#                 i[index] = curr
#                 curr += 1
#         index += 1
#
#
# ab = [[1, 1, 1], [], [1, 1, 1, 1], [1], [1, 1, 1, 1, 1]]
# vypis(ab)
# print()
# ocisluj2(ab)
# vypis(ab)

# uloha 7

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# def pascalov_trojuholnik(n):
#     to_ret = []
#
#     for i in range(n):
#         to_ret.append([])
#         for j in range(i+1):
#             to_ret[i].append(0)
#
#     for i in range(n):
#         for j in range(len(to_ret[i])):
#             if j == 0 or j == len(to_ret[i])-1:
#                 to_ret[i][j] = 1
#             else:
#                 to_ret[i][j] = to_ret[i-1][j-1] + to_ret[i-1][j]
#
#     return to_ret
#
#
# vypis(pascalov_trojuholnik(6))

# uloha 8 + uloha 9

# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# def citaj(meno_suboru):
#     with open(meno_suboru, "r", encoding="utf8") as file:
#         to_ret = []
#
#         for riadok in file:
#             to_ret.append(riadok.strip().split(" "))
#
#         return to_ret
#
#
# x = citaj("text.txt")
# print(x)
# vypis(x)
#
#
# def zapis(tab, meno_suboru):
#     with open(meno_suboru, "w", encoding="utf8") as file:
#         for i in tab:
#             for j in i:
#                 print(j, end=" ", file=file)
#             print(file=file)
#
#
# zapis(x, 'text1.txt')
# zapis([[1, 11, 21], [345], [-5, 10]], 'cisla.txt')

# uloha 10

# def citaj_cisla(meno_suboru):
#     with open(meno_suboru, "r", encoding="utf8") as file:
#         to_ret = []
#
#         for riadok in file:
#             to_ret.append(riadok.strip().split(" "))
#
#         for i in to_ret:
#             tmp = len(i)
#             for j in range(tmp):
#                 i.append(int(i[0]))
#                 i.pop(0)
#
#         return to_ret
#
#
# print(citaj_cisla("cisla.txt"))

# uloha 11

from tkinter import Canvas, mainloop
c = Canvas()
c.pack()


def kresli(tab, d=20, farby=('black', 'yellow', 'orange', 'blue', 'red', 'white')):
    c.delete('all')
    for r, riadok in enumerate(tab):
        for s, prvok in enumerate(riadok):
            if prvok is None:
                continue
            x, y = s * d + 5, r * d + 5
            farba = farby[prvok]
            c.create_rectangle(x, y, x + d, y + d,
                                    fill=farba, outline='light gray')
    c.update()


kresli([[0, 0, 0], [1, 1], [1, 1, 1, None, 2], [3, None, None, None, 2], [3, 3, 2, 2], [3, 3], [4, 4], [4, 4, 4], [4, None, 4, 4], [2, None, None, 2], [2, 2, None, 2, 2]])

mainloop()

# TODO uloha 12

#

# TODO uloha 13

#

# TODO uloha 14

#

# TODO uloha 15

#

# uloha 16 + uloha 17

# def do_radu(tab):
#     to_ret = []
#     for i in tab:
#         if len(i) > 0:
#             to_ret.extend(i)
#
#     return to_ret
#
#
# print(do_radu([[1], [2, 3, 4], [5, 6], [7]]))
# print(do_radu([['prvy'], [], ['druhy', 'treti']]))
#
#
# def do_dvojrozmernej(postupnost, sirka):
#     tmp = []
#     tmp.extend(postupnost)
#     to_ret = []
#
#     while len(tmp) != 0:
#         tmp2 = []
#         for i in range(sirka):
#             if len(tmp) == 0:
#                 break
#             tmp2.append(tmp[0])
#             tmp.pop(0)
#         to_ret.append(tmp2)
#
#     return to_ret
#
#
# def vypis(tab, sirka=None):
#     if sirka is None:
#         sirka = 0
#         for i in tab:
#             for j in i:
#                 if len(str(j)) > sirka:
#                     sirka = len(str(j))
#
#     for i in tab:
#         for j in i:
#             print(f'{repr(j):>{sirka}}', end=" ")
#         print()
#
#
# t1 = do_dvojrozmernej(range(10), 3)
# vypis(t1)
# t2 = do_dvojrozmernej(do_radu(t1), 5)
# vypis(t2)
# vypis(do_dvojrozmernej('programovanie', 5))
