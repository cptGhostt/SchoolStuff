# uloha 5*

# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None  # triedny atribút
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definicie vnorenej triedy ------
#
#     def __init__(self):
#         self.root = self.Vrchol('P',self.Vrchol('R',self.Vrchol('O'),self.Vrchol('G',self.Vrchol('R'))),self.Vrchol('A',self.Vrchol('M',self.Vrchol('O'),self.Vrchol('V',self.Vrchol('A'))),self.Vrchol('N',self.Vrchol('I'),self.Vrchol('E'))))
#
#     def kresli(self):
#
#         # ---- vnorená rekurzívna funkcia ----
#
#         def kresli_rek(vrch, sirka, x, y):
#             if vrch.left is not None:
#                 self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                 kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#             if vrch.right is not None:
#                 self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                 kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#             self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#             self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#         # ----
#
#         if self.canvas is None:
#             BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#             self.canvas.pack()
#         else:
#             self.canvas.delete('all')
#         kresli_rek(self.root, 300, 300, 30)
#
#         self.canvas.mainloop()
#
#     def preorder_str(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return ''
#             return str(vrch.data) + ' ' + rek(vrch.left) + rek(vrch.right)
#
#         # ----
#         return rek(self.root)
#
#     def preorder_list(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return []
#             return [vrch.data] + rek(vrch.left) + rek(vrch.right)
#
#         # ----
#         return rek(self.root)
#
#
# a = BinarnyStrom()
# print(a.preorder_str())
# a.kresli()

# uloha 6*

# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None  # triedny atribút
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definicie vnorenej triedy ------
#
#     def __init__(self):
#         self.root = self.Vrchol('9',self.Vrchol('3',self.Vrchol('2',None,self.Vrchol('8')),self.Vrchol('5')),self.Vrchol('4',self.Vrchol('1',None,self.Vrchol('7')),self.Vrchol('6',self.Vrchol('10'))))
#
#     def kresli(self):
#
#         # ---- vnorená rekurzívna funkcia ----
#
#         def kresli_rek(vrch, sirka, x, y):
#             if vrch.left is not None:
#                 self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                 kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#             if vrch.right is not None:
#                 self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                 kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#             self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#             self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#         # ----
#
#         if self.canvas is None:
#             BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#             self.canvas.pack()
#         else:
#             self.canvas.delete('all')
#         kresli_rek(self.root, 300, 300, 30)
#
#         self.canvas.mainloop()
#
#     def preorder_str(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return ''
#             return str(vrch.data) + ' ' + rek(vrch.left) + rek(vrch.right)
#
#         # ----
#         return rek(self.root)
#
#     def inorder_vypis(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return
#             rek(vrch.left)
#             # spracuj samotný vrchol vrch
#             print(vrch.data, end=' ')
#             rek(vrch.right)
#
#         # ----
#         rek(self.root)
#         print()
#
#     def postorder_vypis(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return
#             rek(vrch.left)
#             rek(vrch.right)
#             # spracuj samotný vrchol vrch
#             print(vrch.data, end=' ')
#
#         # ----
#         rek(self.root)
#         print()
#
#
# a = BinarnyStrom()
# print(a.preorder_str())
# a.inorder_vypis()
# a.postorder_vypis()
# a.kresli()

# uloha 8*

# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None  # triedny atribút
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definicie vnorenej triedy ------
#
#     def __init__(self):
#         self.root = self.Vrchol('9',self.Vrchol('3',self.Vrchol('2',None,self.Vrchol('8')),self.Vrchol('5')),self.Vrchol('4',self.Vrchol('1',None,self.Vrchol('7')),self.Vrchol('6',self.Vrchol('10'))))
#
#     def kresli(self):
#
#         # ---- vnorená rekurzívna funkcia ----
#
#         def kresli_rek(vrch, sirka, x, y):
#             if vrch.left is not None:
#                 self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                 kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#             if vrch.right is not None:
#                 self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                 kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#             self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#             self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#         # ----
#
#         if self.canvas is None:
#             BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#             self.canvas.pack()
#         else:
#             self.canvas.delete('all')
#         kresli_rek(self.root, 300, 300, 30)
#
#         self.canvas.mainloop()
#
#     def preorder_str(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return ''
#             return str(vrch.data) + ' ' + rek(vrch.left) + rek(vrch.right)
#
#         # ----
#         return rek(self.root)
#
#     def inorder_vypis(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return
#             rek(vrch.left)
#             # spracuj samotný vrchol vrch
#             print(vrch.data, end=' ')
#             rek(vrch.right)
#
#         # ----
#         rek(self.root)
#         print()
#
#     def postorder_vypis(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return
#             rek(vrch.left)
#             rek(vrch.right)
#             # spracuj samotný vrchol vrch
#             print(vrch.data, end=' ')
#
#         # ----
#         rek(self.root)
#         print()
#
#     def mapuj(self, funkcia):
#
#         def mapuj_rek(vrch):
#             if vrch is None:
#                 return
#             vrch.data = funkcia(vrch.data)
#             mapuj_rek(vrch.left)
#             mapuj_rek(vrch.right)
#         mapuj_rek(self.root)
#
#
# a = BinarnyStrom()
# print(a.preorder_str())
# a.mapuj(lambda x: x*11)
# print(a.preorder_str())

# uloha 9*

# import random
#
# class BinarnyStrom:
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def inorder_vypis(self):
#
#         # ---- vnorená rekurzívna funkcia ----
#         def rek(vrch):
#             if vrch is None:
#                 return
#             rek(vrch.left)
#             # spracuj samotný vrchol vrch
#             print(vrch.data, end=' ')
#             rek(vrch.right)
#
#     def inorder(self):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             yield from rek(vrch.left)
#             yield vrch.data
#             yield from rek(vrch.right)
#
#         yield from rek(self.root)
#
#     def inorder_ocisluj(self, start=0, krok=1):
#         def ocisluj_rek(vrch):
#             if vrch is None:
#                 return
#             ocisluj_rek(vrch.left)
#             vrch.data = self.cislo
#             self.cislo += krok
#             ocisluj_rek(vrch.right)
#         self.cislo = start
#         ocisluj_rek(self.root)
#
#
# a = BinarnyStrom("Python")
# a.inorder_ocisluj(3, 5)
# print(*a.inorder())

# uloha 10*

# import random
#
# class BinarnyStrom:
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def preorder(self):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             yield vrch.data
#             yield from rek(vrch.left)
#             yield from rek(vrch.right)
#
#         yield from rek(self.root)
#
#
#     def prirad(self, postupnost):
#         def rek_p(vrch, arr):
#             if len(arr) == 0 or vrch is None:
#                 return
#             vrch.data = arr[0]
#             arr.pop(0)
#             rek_p(vrch.left, arr)
#             rek_p(vrch.right, arr)
#         rek_p(self.root, postupnost)
#
#
# a = BinarnyStrom("x" * 10)
# a.prirad([2, 3, 5, 7, 11, 13])
# print(*a.preorder())

# uloha 11*

# import random
# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def kresli(self):
#
#
#             # ---- vnorená rekurzívna funkcia ----
#
#             def kresli_rek(vrch, sirka, x, y):
#                 if vrch.left is not None:
#                     self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                     kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#                 if vrch.right is not None:
#                     self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                     kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#                 self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#                 self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#             # ----
#
#             if self.canvas is None:
#                 BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#                 self.canvas.pack()
#             else:
#                 self.canvas.delete('all')
#             kresli_rek(self.root, 300, 300, 30)
#
#             self.canvas.mainloop()
#
#     def preorder(self):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             yield vrch.data
#             yield from rek(vrch.left)
#             yield from rek(vrch.right)
#
#         yield from rek(self.root)
#
#
#     def surodenec(self, vrchol):
#         if vrchol is None:
#             return None
#
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             if vrch.left == vrchol:
#                 return vrch.right
#             elif vrch.right == vrchol:
#                 return vrch.left
#             rek(vrch.left)
#             rek(vrch.right)
#         return rek(self.root)
#
#
# a = BinarnyStrom("python")
# b = a.surodenec(a.root.right)
# a.kresli()
# print(b.data)

# uloha 12*

# import random
# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def kresli(self):
#
#
#             # ---- vnorená rekurzívna funkcia ----
#
#             def kresli_rek(vrch, sirka, x, y):
#                 if vrch.left is not None:
#                     self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                     kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#                 if vrch.right is not None:
#                     self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                     kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#                 self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#                 self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#             # ----
#
#             if self.canvas is None:
#                 BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#                 self.canvas.pack()
#             else:
#                 self.canvas.delete('all')
#             kresli_rek(self.root, 300, 300, 30)
#
#             self.canvas.mainloop()
#
#     def __len__(self):
#         # ---- vnorená rekurzívna funkcia ----
#         def pocet(vrch):
#             if vrch is None:
#                 return 0
#             return 1 + pocet(vrch.left) + pocet(vrch.right)
#
#         # ----
#         return pocet(self.root)
#
#     def preorder(self):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             yield vrch.data
#             yield from rek(vrch.left)
#             yield from rek(vrch.right)
#
#         yield from rek(self.root)
#
#     def ity(self, i):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             if self.i == self.want:
#                 self.val = vrch.data
#             self.i += 1
#             rek(vrch.left)
#             rek(vrch.right)
#         self.i = 0
#         self.want = i
#         self.val = None
#         rek(self.root)
#         return self.val
#
#
# a = BinarnyStrom(range(10))
# print(*a.preorder())
# for i in range(len(a)):
#     print(a.ity(i), end=" ")

# uloha 13*

# import random
# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def kresli(self):
#
#
#             # ---- vnorená rekurzívna funkcia ----
#
#             def kresli_rek(vrch, sirka, x, y):
#                 if vrch.left is not None:
#                     self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                     kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#                 if vrch.right is not None:
#                     self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                     kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#                 self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#                 self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#             # ----
#
#             if self.canvas is None:
#                 BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#                 self.canvas.pack()
#             else:
#                 self.canvas.delete('all')
#             kresli_rek(self.root, 300, 300, 30)
#
#             self.canvas.mainloop()
#
#     def preorder(self):
#         def rek(vrch):
#             if vrch is None:
#                 return
#
#             yield vrch.data
#             yield from rek(vrch.left)
#             yield from rek(vrch.right)
#
#         yield from rek(self.root)
#
#
#     def kopia(self):
#         self.new = BinarnyStrom(self.root.data)
#         def rek(vrch1, vrch2):
#             if vrch1 is None:
#                 return
#
#             if vrch1.left is None:
#                 vrch2.left = None
#             else:
#                 vrch2.left = self.Vrchol(vrch1.left.data)
#             if vrch1.right is None:
#                 vrch2.right = None
#             else:
#                 vrch2.right = self.Vrchol(vrch1.right.data)
#             rek(vrch1.left, vrch2.left)
#             rek(vrch1.right, vrch2.right)
#         rek(self.root, self.new.root)
#         return self.new
#
#
# a = BinarnyStrom("programovanie")
# aa = a.kopia()
# print(*a.preorder())
# print(*aa.preorder())
# a.kresli()

# uloha 14*

# import random
# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def kresli(self):
#
#
#             # ---- vnorená rekurzívna funkcia ----
#
#             def kresli_rek(vrch, sirka, x, y):
#                 if vrch.left is not None:
#                     self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                     kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#                 if vrch.right is not None:
#                     self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                     kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#                 self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#                 self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#             # ----
#
#             if self.canvas is None:
#                 BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#                 self.canvas.pack()
#             else:
#                 self.canvas.delete('all')
#             kresli_rek(self.root, 300, 300, 30)
#
#             self.canvas.mainloop()
#
#     def vyska(self):
#         def rek(vrch):
#             if vrch is None:
#                 return 0
#             vyska_vlavo = rek(vrch.left)
#             vyska_vpravo = rek(vrch.right)
#             return 1 + max(vyska_vlavo, vyska_vpravo)
#         return rek(self.root)
#
#     def po_urovniach(self):
#         if self.root is None:
#             return
#         uroven = [self.root]
#         while uroven:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#                 yield vrch.data
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#
#     def ocisluj_po_urovniach(self, start=0, krok=1):
#         if self.root is None:
#             return
#         uroven = [self.root]
#         while uroven:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#                 vrch.data = start
#                 start += krok
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#
#     def v_urovni(self, k):
#         if self.root is None:
#             return
#
#         lvl = 0
#         uroven = [self.root]
#         while uroven:
#             if lvl == k:
#                 break
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#             lvl += 1
#
#         for i in range(len(uroven)):
#             uroven[i] = uroven[i].data
#         return uroven
#
#     def sirka(self):
#         if self.root is None:
#             return
#         sirka = 1
#         uroven = [self.root]
#         while uroven:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#             if len(uroven) > sirka:
#                 sirka = len(uroven)
#
#         return sirka
#
#     def po_urovniach_gener(self):
#         if self.root is None:
#             return
#         uroven = [self.root]
#         while uroven:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#                 yield vrch.data
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#
#     __iter__ = po_urovniach_gener
#
#
# a = BinarnyStrom("programovanie")
# # a.ocisluj_po_urovniach(1)
# for k in range(a.vyska() + 1):
#         print('v urovni', k, '=', a.v_urovni(k))
# print('sirka =', a.sirka())
# for i in a:
#     print(i, end=" ")
#
# a.kresli()

# uloha 16*

# import random
# import tkinter
#
#
# class BinarnyStrom:
#     canvas = None
#
#     # ------ vnorená trieda ------
#
#     class Vrchol:
#         def __init__(self, data, left=None, right=None):     # inicializácia triedy Vrchol
#             self.data, self.left, self.right = data, left, right
#
#     # ------ koniec definície vnorenej triedy ------
#
#     def __init__(self, postupnost=None):
#         self.root = None
#         if postupnost is not None:
#             for hodnota in postupnost:
#                 self.pridaj_vrchol(hodnota)
#
#     def pridaj_vrchol(self, hodnota):
#         if self.root is None:
#             self.root = self.Vrchol(hodnota)
#         else:
#             vrch = self.root
#             while True:
#                 if random.randrange(2):
#                     if vrch.left is None:
#                         vrch.left = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.left
#                 else:
#                     if vrch.right is None:
#                         vrch.right = self.Vrchol(hodnota)
#                         return
#                     vrch = vrch.right
#
#     def kresli(self):
#
#
#             # ---- vnorená rekurzívna funkcia ----
#
#             def kresli_rek(vrch, sirka, x, y):
#                 if vrch.left is not None:
#                     self.canvas.create_line(x, y, x - sirka / 2, y + 50)
#                     kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
#                 if vrch.right is not None:
#                     self.canvas.create_line(x, y, x + sirka / 2, y + 50)
#                     kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
#                 self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
#                 self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')
#
#             # ----
#
#             if self.canvas is None:
#                 BinarnyStrom.canvas = tkinter.Canvas(width=600, height=300, bg='white')
#                 self.canvas.pack()
#             else:
#                 self.canvas.delete('all')
#             kresli_rek(self.root, 300, 300, 30)
#
#             self.canvas.mainloop()
#
#     def vyska(self):
#         def rek(vrch):
#             if vrch is None:
#                 return 0
#             vyska_vlavo = rek(vrch.left)
#             vyska_vpravo = rek(vrch.right)
#             return 1 + max(vyska_vlavo, vyska_vpravo)
#         return rek(self.root)
#
#     def po_urovniach(self):
#         if self.root is None:
#             return
#         uroven = [self.root]
#         while uroven:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#                 yield vrch.data
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#
#     def vyrob_uplny(self, n, hodnota="x"):
#         self.root = self.Vrchol(hodnota)
#         hi = 1
#
#         uroven = [self.root]
#         while hi < n:
#             dalsia_uroven = []
#             for vrch in uroven:
#                 # spracuj vrchol
#                 vrch.left = self.Vrchol(hodnota)
#                 vrch.right = self.Vrchol(hodnota)
#                 if vrch.left is not None:
#                     dalsia_uroven.append(vrch.left)
#                 if vrch.right is not None:
#                     dalsia_uroven.append(vrch.right)
#             uroven = dalsia_uroven
#             hi += 1
#
#
# strom = BinarnyStrom()
# strom.vyrob_uplny(4)
# print(strom.vyska())
# strom.kresli()

# uloha 17* + uloha 18*

import random
import tkinter


class VseobecnyStrom:
    canvas = None

    class Vrchol:
        def __init__(self, data, *child):
            self.data = data
            self.child = child

    def __init__(self):
        self.root = None

    def __len__(self):
        def rek(vrch):
            if vrch is None:
                return 0
            return 1 + sum(map(rek, vrch.child))

        return rek(self.root)

    def __repr__(self):
        def repr_rek(vrch):
            if vrch is None:
                return '()'
            vysl = [repr(vrch.data)]
            for child in vrch.child:
                vysl.append(repr_rek(child))
            if len(vysl) == 1:
                return vysl[0]
            return '(' + ','.join(vysl) + ')'
        return repr_rek(self.root)

    def pridaj_nahodne(self, *postupnost):
        for hodnota in postupnost:
            if self.root is None:
                self.root = self.Vrchol(hodnota)
            else:
                vrch = self.root
                while True:
                    n = len(vrch.child)
                    i = random.randrange(n + 1)
                    if i == n:
                        vrch.child.append(self.Vrchol(hodnota))
                        break
                    vrch = vrch.child[i]

    def kresli(self):
        def kresli_rek(vrch, sir, x, y):
            n = len(vrch.child)
            if n != 0:
                sir0 = sir // n
                x1, y1 = x - sir - sir0, y + 50
                for i in range(n):
                    x1 += 2 * sir0
                    self.canvas.create_line(x, y, x1, y1)
                    kresli_rek(vrch.child[i], sir0, x1, y1)
            self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
            self.canvas.create_text(x, y, text=vrch.data, font='consolas 14')

        if self.canvas is None:
            VseobecnyStrom.canvas = tkinter.Canvas(bg='white', width=600, height=400)
            self.canvas.pack()
        self.canvas.delete('all')
        kresli_rek(self.root, 290, 300, 30)
        self.canvas.mainloop()

    def preorder(self):
        def rek(vrch):
            if vrch is None:
                return

            yield vrch.data
            for i in vrch.child:
                yield from rek(i)

        yield from rek(self.root)

    def vyska(self):
        def rek(vrch):
            if not vrch.child:
                return 1
            hi = []
            for i in vrch.child:
                hi.append(rek(i))
            return 1 + max(hi)
        return rek(self.root)

    def pocet_listov(self):
        self.leaf = 0
        def rek(vrch):
            if not vrch.child:
                self.leaf += 1
            hi = []
            for i in vrch.child:
                hi.append(rek(i))
        rek(self.root)
        return self.leaf


v = VseobecnyStrom.Vrchol
s = VseobecnyStrom()
s.root = v('a', v('b', v('c'), v('d')), v('e', v('f', v('g')), v('h'), v('i'), v('j')))
print(s)
print(*s.preorder())
print(s.vyska())
print(s.pocet_listov())

s.kresli()
