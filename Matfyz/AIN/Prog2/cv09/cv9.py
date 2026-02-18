from tkinter import *


# class Graf:
#
#     def __init__(self, n):
#         self.matica = []
#         for i in range(n):
#             self.matica.append([0]*n)
#
#     def pridaj_hranu(self, v1, v2):
#         self.matica[v1][v2] = 1
#
#     def je_hrana(self, v1, v2):
#         try:
#             if self.matica[v1][v2] == 1:
#                 return True
#             return False
#         except IndexError:
#             return False
#
#     def daj_vrcholy(self):
#         return set(range(len(self.matica)))
#
#     def daj_hrany(self):
#         to_ret = set()
#
#         for i in range(len(self.matica)):
#             for j in range(len(self.matica[i])):
#                 if self.matica[i][j] == 1:
#                     to_ret.add((i, j))
#
#         return to_ret
#
#     def stupen(self, v1=None):
#         if v1 is not None:
#             return self.matica[v1].count(1)
#         return max([i.count(1) for i in self.matica])
#
#     def __str__(self):
#         return f'vrcholy: {self.daj_vrcholy()}\nhrany: {self.daj_hrany()}'
#
#     def je_neorientovany(self):
#         tmp = self.daj_hrany()
#         for i in tmp:
#             if (i[1], i[0]) not in tmp:
#                 return False
#
#         return True
#
#     def trojuholniky(self):
#         to_print = set()
#
#         if not self.je_neorientovany():
#             print(to_print)
#             return
#
#         hrany = self.daj_hrany()
#         for i in range(len(self.matica)):
#             for j in range(i+1, len(self.matica)):
#                 for u in range(j+1, len(self.matica)):
#                     if (i, j) in hrany and (j, i) in hrany and (i, u) in hrany and (u, i) in hrany and (j, u) in hrany and (u, j) in hrany:
#                         to_print.add((i, j, u))
#
#         print(to_print)


class Graf:
    canvas = None

    class Vrchol:
        def __init__(self, meno, x, y):
            self.meno = meno
            self.sus = set()
            self.x, self.y = x, y

        def pridaj_hranu(self, v2):
            self.sus.add(v2)

        def __contains__(self, v2):
            return v2 in self.sus

        def kresli(self):  # vykreslí vrchol ako kruh s textom self.meno
            Graf.canvas.create_oval(self.x-15, self.y-15, self.x+15, self.y+15, fill='white', outline='black')
            Graf.canvas.create_text(self.x, self.y, text=f'{self.meno}')

        def kresli_hranu(self, vrchol2):  # vykreslí hranu k vrchol2
            Graf.canvas.create_line(self.x, self.y, vrchol2.x, vrchol2.y)

    # -------

    def __init__(self, meno_suboru=None):
        self.zoz = {}

        if meno_suboru is not None:
            with open(meno_suboru, 'r', encoding="utf8") as f:
                vertices = []
                line = f.readline()

                while line != "":
                    line = line.split()
                    vertices.append(tuple(line))
                    line = f.readline()

            for i in vertices:
                self.pridaj_vrchol(int(i[0]), int(i[1]), int(i[2]))
                for j in range(3, len(i)):
                    self.pridaj_hranu(int(i[0]), int(i[j]))

    def pridaj_vrchol(self, meno, x, y):
        if meno not in self.zoz:
            self.zoz[meno] = self.Vrchol(meno, x, y)

    def pridaj_hranu(self, v1, v2):
        # self.pridaj_vrchol(v1)
        # self.pridaj_vrchol(v2)
        self.zoz[v1].pridaj_hranu(v2)

    def je_hrana(self, v1, v2):
        return v2 in self.zoz[v1]

    def daj_vrcholy(self):
        return list(self.zoz.keys())

    def daj_hrany(self):
        return [(v1, v2) for v1, v in self.zoz.items() for v2 in v.sus]

    def stupen(self, v=None):
        if v is not None:
            return len(self.zoz[v].sus)
        return max(len(v.sus) for v in self.zoz.values())

    def __str__(self):
        return f'vrcholy: {self.daj_vrcholy()}\nhrany: {self.daj_hrany()}'

    def kresli(self):  # vykreslí celý graf
        if Graf.canvas is None:
            Graf.canvas = Canvas(height=500, width=700)
            Graf.canvas.pack()

        vrcholy = self.daj_vrcholy()

        for i in vrcholy:
            for j in self.zoz[i].sus:
                self.zoz[i].kresli_hranu(self.zoz[j])

        for i in vrcholy:
            self.zoz[i].kresli()

        Graf.canvas.mainloop()


# uloha 1*

# vrcholy = {0, 1, 2, 3, 4, 5, 6, 7, 8}
# hrany = {(0, 1), (1, 5), (5, 2), (2, 5), (5, 4), (4, 7), (7, 8), (8, 5), (4, 6), (6, 3), (3, 1), (7, 0)}

"""
je tento graf orientovaný? áno
je tento graf súvislý? áno
je tento graf ohodnotený? nie
je tento graf acyklický? nie
"""

# 0 -> 1 -> 5 -> 4 -> 6 -> 3

"""
4 -> 7 -> 8 -> 5 -> 4
1 -> 5 -> 4 -> 6 -> 3 -> 1
0 -> 1 -> 5 -> 4 -> 7 -> 0
"""

# uloha 2*

# graf1 = [{1},           # 0
#          {5},           # 1
#          {5},           # 2
#          {1},           # 3
#          {6, 7},        # 4
#          {2, 4},        # 5
#          {3},           # 6
#          {0, 8},        # 7
#          {5}]           # 8
#
# graf2 = {0: {1},
#          1: {5},
#          2: {5},
#          3: {1},
#          4: {6, 7},
#          5: {2, 4},
#          6: {3},
#          7: {0, 8},
#          8: {5}}

# uloha 4*

# graf = {"A": {"B": 7, "C": 5, "F": 1},
#         "B": {"A": 2, "D": 7, "E": 3},
#         "C": {"B": 2, "F": 8},
#         "D": {"A": 1, "E": 2, "F": 4},
#         "E": {"A": 6, "D": 5},
#         "F": {"B": 1, "E": 8}}

# uloha 6*

# #        0  1  2  3  4  5
# graf = [[0, 0, 1, 1, 1, 0],     # 0
#         [0, 0, 0, 1, 1, 0],     # 1
#         [1, 0, 0, 1, 1, 0],     # 2
#         [1, 1, 1, 0, 0, 0],     # 3
#         [1, 1, 1, 0, 0, 1],     # 4
#         [0, 0, 0, 0, 1, 0]]     # 5

# uloha 7*

# graf = Graf(4)
# graf.pridaj_hranu(1, 2)
# print(graf.je_hrana(1, 2))
# print(graf.je_hrana(1, 1))
# print(graf.je_hrana(6, 6))
# graf.pridaj_hranu(3, 3)
# graf.pridaj_hranu(2, 0)
# graf.pridaj_hranu(1, 1)
# print(graf)
# print("stupeň vrcholu 0:", graf.stupen(0))
# print("stupeň vrcholu 1:", graf.stupen(1))
# print("stupeň vrcholu 2:", graf.stupen(2))
# print("stupeň vrcholu 3:", graf.stupen(3))
# print("stupeň grafu:", graf.stupen())

# uloha 8* + uloha 9*

# graf = Graf(6)
# graf.pridaj_hranu(0, 2)
# graf.pridaj_hranu(0, 3)
# graf.pridaj_hranu(0, 4)
# graf.pridaj_hranu(1, 3)
# graf.pridaj_hranu(1, 4)
# graf.pridaj_hranu(2, 0)
# graf.pridaj_hranu(2, 3)
# graf.pridaj_hranu(2, 4)
# graf.pridaj_hranu(3, 0)
# graf.pridaj_hranu(3, 1)
# graf.pridaj_hranu(3, 2)
# graf.pridaj_hranu(4, 0)
# graf.pridaj_hranu(4, 1)
# graf.pridaj_hranu(4, 2)
# graf.pridaj_hranu(4, 5)
# graf.pridaj_hranu(5, 4)
# print(graf)
# for i in graf.daj_vrcholy():
#     print('stupen vrcholu', i, 'je', graf.stupen(i))
#
# print(graf.je_neorientovany())
# graf.trojuholniky()

# uloha 10*

# graf = Graf()
# graf.pridaj_vrchol(0, 250, 350)
# graf.pridaj_vrchol(1, 150, 250)
# graf.pridaj_vrchol(2, 300, 400)
# graf.pridaj_vrchol(3, 125, 375)
# graf.pridaj_vrchol(4, 275, 250)
# graf.pridaj_vrchol(5, 325, 250)
# graf.pridaj_hranu(0, 2)
# graf.pridaj_hranu(0, 3)
# graf.pridaj_hranu(0, 4)
# graf.pridaj_hranu(1, 3)
# graf.pridaj_hranu(1, 4)
# graf.pridaj_hranu(2, 0)
# graf.pridaj_hranu(2, 3)
# graf.pridaj_hranu(2, 4)
# graf.pridaj_hranu(3, 0)
# graf.pridaj_hranu(3, 1)
# graf.pridaj_hranu(3, 2)
# graf.pridaj_hranu(4, 0)
# graf.pridaj_hranu(4, 1)
# graf.pridaj_hranu(4, 2)
# graf.pridaj_hranu(4, 5)
# graf.pridaj_hranu(5, 4)
# graf.kresli()

# uloha 11*

graf = Graf("graf_u5.txt")
print(graf)
graf.kresli()
