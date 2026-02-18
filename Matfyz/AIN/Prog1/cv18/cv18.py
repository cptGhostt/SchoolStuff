# uloha 1 + uloha 2

# import turtle
# from random import randint
#
#
# class MojaTurtle(turtle.Turtle):
#     def __init__(self):
#         super().__init__()
#         self.speed(0)
#         self.pu()
#         self.setpos(randint(-250, 250), randint(-250, 250))
#         self.pd()
#
#     def domcek(self, dlzka):
#         for uhol in 90, 90, 90, 30, 120, -60:
#             self.fd(dlzka)       # fd z triedy ??? Turtle
#             self.rt(uhol)        # rt z triedy Turtle
#
#
# class MojaTurtle0(MojaTurtle):
#     def lt(self, uhol):
#         super().lt(uhol + randint(-5, 5))
#
#     def rt(self, uhol):
#         super().rt(uhol + randint(-5, 5))
#
#
# class MojaTurtle1(MojaTurtle0):
#     def fd(self, dlzka):
#         while dlzka >= 5:
#             self.lt(60)
#             super().fd(5)        # fd z triedy Turtle
#             self.rt(120)
#             super().fd(5)        # fd z triedy Turtle
#             self.lt(60)
#             dlzka -= 5
#         super().fd(dlzka)        # fd z triedy Turtle
#
#
# class MojaTurtle2(MojaTurtle0):
#     def fd(self, dlzka):
#         super().fd(dlzka)        # fd z triedy Turtle
#         self.rt(180 - randint(-3, 3))
#         super().fd(dlzka)        # fd z triedy Turtle
#         self.rt(180 - randint(-3, 3))
#         super().fd(dlzka)        # fd z triedy Turtle
#
#
# turtle.delay(0)
# for i in range(30):
#     MojaTurtle0().domcek(50)
#     MojaTurtle1().domcek(30)
#     MojaTurtle2().domcek(40)
# turtle.done()

# uloha 3

# print((3 + 4) * 5 + 2 ** (100 // 5))
# print((((3).__add__(4)).__mul__(5)).__add__((2).__pow__((100).__floordiv__(5))))
#
# print((7).__pow__(8).__str__().__len__().__add__('xy'.__rmul__(8).__len__().__add__(1)).__mul__(13))
# print((len(str(7 ** 8)) + (len("xy" * 8) + 1)) * 13)

# uloha 4 + uloha 5 + uloha 6

# import time
#
#
# class Cas:
#
#     def __init__(self, hodiny=0, minuty=0, sekundy=0):
#         self.sek = abs(3600 * hodiny + 60 * minuty + sekundy)
#
#     def __str__(self):
#         return f'{self.sek // 3600}:{self.sek // 60 % 60:02}:{self.sek % 60:02}'
#
#     def __repr__(self):
#         return self.__str__()
#
#     def __add__(self, iny):
#         try:
#             return Cas(sekundy=self.sek + iny.sek)
#         except AttributeError:
#             try:
#                 return Cas(sekundy=self.sek + iny)
#             except TypeError:
#                 iny = list(iny)
#                 while len(iny) != 3:
#                     iny.append(0)
#
#                 tmp = iny[0]*3600 + iny[1]*60 + iny[2]
#                 return Cas(sekundy=self.sek + tmp)
#
#     def __sub__(self, iny):
#         try:
#             return Cas(sekundy=self.sek - iny.sek)
#         except AttributeError:
#             try:
#                 return Cas(sekundy=self.sek - iny)
#             except TypeError:
#                 iny = list(iny)
#                 while len(iny) != 3:
#                     iny.append(0)
#
#                 tmp = iny[0] * 3600 + iny[1] * 60 + iny[2]
#                 return Cas(sekundy=self.sek - tmp)
#
#     def __gt__(self, iny):
#         return self.sek > iny.sek
#
#     def __eq__(self, iny):
#         return self.sek == iny.sek
#
#
# def teraz():
#     a = time.localtime()[3:6][0]
#     b = time.localtime()[3:6][1]
#     c = time.localtime()[3:6][2]
#     return Cas(a, b, c)
#
#
# c = Cas(8, 10, 34)
# print(c)
# c += 640
# print(c)
# c += (1, 55)
# print(c)
# c -= 100
# print(c)
# print(teraz())
#
# zoznam = [Cas(20, 15), Cas(7), Cas(20, 10), Cas(20, 15, 20)]
# print(zoznam)
# print(sorted(zoznam))

# uloha 7,

# def mnozina1(n):
#     to_ret = set()
#     a = set(range(0, n+1, 3))
#     b = set(range(1, n+1, 5))
#     c = set(range(2, n+1, 5))
#
#     return a & (b | c)
#
#
# def mnozina2(n1, n2):
#     a = mnozina1(n1)
#     b = mnozina1(n2)
#
#     return b - a
#
#
# print(mnozina1(21))
# print(mnozina2(20, 100))

# uloha 8

# def len_v_jednom(retazec1, retazec2):
#     a = set(retazec1)
#     b = set(retazec2)
#     c = a | b
#
#     return c - (a & b)
#
#
# print(len_v_jednom('isiel macek do malaciek', 'sosovicku mlacit'))

# uloha 9

# def vsetky_rozne(postupnost):
#     return len(set(postupnost)) == len((postupnost))
#
#
# print(vsetky_rozne((1, 2)))
# print(vsetky_rozne((1, 2, 2)))

# uloha 10

# def rozdel(mnozina):
#     a = set()
#     b = set()
#     for i in mnozina:
#         if type(i) is str:
#             b.add(i)
#         else:
#             a.add(i)
#
#     return a, b
#
#
# m1, m2 = rozdel({7, 7.5, '12', 3, 'python'})
# print(m1)
# print(m2)

# uloha 11

# def bez_parnych(mnozina):
#     tmp = set()
#     for i in mnozina:
#         try:
#             if type(i) is int and i % 2 == 0:
#                 continue
#             else:
#                 tmp.add(i)
#         except TypeError:
#             tmp.add(i)
#
#     mnozina.clear()
#     for i in tmp:
#         mnozina.add(i)
#
#
# a = {7, 6.0, '12', 4, 'python', 124}
# print(a)
# bez_parnych(a)
# print(a)
#
# b = set(range(4, 100, 2))
# print(b)
# bez_parnych(b)
# print(b)

# uloha 12

# def len_raz(retazec):
#     # a = set(retazec)
#     # b = set()
#     # for i in retazec:
#     #     if retazec.count(i) > 1:
#     #         b.add(i)
#     #
#     # return a - b
#
#     a = set()
#     for i in retazec:
#         if retazec.count(i) == 1:
#             a.add(i)
#
#     return a
#
#
# print(len_raz('anicka dusicka kde si bola'))
# print(len_raz('mama ma emu a ema ma mamu'))

# uloha 13

# def opakuje_sa(meno_suboru):
#     a = set()
#     with open(meno_suboru, "r", encoding="utf8") as f:
#         tmp = f.read()
#         tmp = tmp.replace("\n", " ")
#         tmp = tmp.split()
#
#         for i in tmp:
#             if tmp.count(i) > 1:
#                 a.add(i)
#
#         return a
#
#
# print(opakuje_sa("text1.txt"))

# uloha 14

# def vsetky(a, b, c, d):
#     tmp = (a, b, c, d)
#     to_ret = []
#     for i in range(4):
#         for j in range(i+1, 4):
#             to_ret.append({tmp[i], tmp[j]})
#
#     return to_ret
#
#
# print(vsetky(1, 2, 3, 4))

# uloha 15

# def vsetky(zoznam):
#     tmp = tuple(zoznam)
#     to_ret = []
#     for i in range(len(zoznam)):
#         for j in range(i+1, len(zoznam)):
#             to_ret.append({tmp[i], tmp[j]})
#
#     return to_ret
#
#
# print(vsetky(set('java')))
# print(vsetky(set(range(5))))
# print(vsetky({3, 1, 'x', 4, 1, 2, 'x'}))
# print(vsetky({'python'}))

# uloha 16

def kartez_sucin(m1, m2):
    a = set()

    for i in m1:
        for j in m2:
            a.add((i, j))

    return a


print(kartez_sucin({1, 2, 3, 4}, {'a', 'b', 'c'}))
