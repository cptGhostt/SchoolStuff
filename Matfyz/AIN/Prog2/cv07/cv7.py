import tkinter
from math import inf


class BVS:
    canvas = None

    class Vrchol:
        def __init__(self, data, left=None, right=None):
            self.data, self.left, self.right = data, left, right

    def __init__(self, postupnost=None):
        self.root = None
        for i in postupnost:
            self.vloz(i)

    def hladaj(self, hodnota):
        vrch = self.root
        while vrch is not None:
            if vrch.data == hodnota:
                return True
            if vrch.data > hodnota:
                vrch = vrch.left
            else:
                vrch = vrch.right
        return False

    def vloz(self, hodnota):
        if self.root is None:
            self.root = self.Vrchol(hodnota)
        else:
            vrch = self.root
            while vrch.data != hodnota:
                if vrch.data > hodnota:
                    if vrch.left is None:
                        vrch.left = self.Vrchol(hodnota)
                        return
                    vrch = vrch.left
                else:
                    if vrch.right is None:
                        vrch.right = self.Vrchol(hodnota)
                        return
                    vrch = vrch.right

    def kresli(self):

        # ---- vnorená rekurzívna funkcia ----

        def kresli_rek(vrch, sirka, x, y):
            if vrch.left is not None:
                self.canvas.create_line(x, y, x - sirka / 2, y + 50)
                kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
            if vrch.right is not None:
                self.canvas.create_line(x, y, x + sirka / 2, y + 50)
                kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
            self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
            self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')

        if self.canvas is None:
            self.canvas = tkinter.Canvas(width=600, height=300, bg='white')
            self.canvas.pack()
        else:
            self.canvas.delete('all')
        kresli_rek(self.root, 300, 300, 30)

        self.canvas.mainloop()

    def kontrola(self):
        def rek(vrch, min, max):
            if vrch is None:
                return True
            if vrch.data < min or vrch.data > max:
                return False
            return rek(vrch.left, min, vrch.data) and rek(vrch.right, vrch.data, max)

        return rek(self.root, -inf, inf)

    def min(self):
        vrch = self.root
        while True:
            if vrch.left is None:
                return vrch.data
            else:
                vrch = vrch.left

    def max(self):
        vrch = self.root
        while True:
            if vrch.right is None:
                return vrch.data
            else:
                vrch = vrch.right

    def inorder(self):
        def rek(vrch):
            if vrch is None:
                return
            yield from rek(vrch.left)
            yield vrch.data
            yield from rek(vrch.right)
        yield from rek(self.root)

    def preorder(self):
        def rek(vrch):
            if vrch is None:
                return
            yield vrch.data
            yield from rek(vrch.left)
            yield from rek(vrch.right)

        yield from rek(self.root)

    def vyhod_pom(self, pred, vrch):
        if vrch.left is not None and vrch.right is not None:
            raise TypeError

        if pred is None:
            if vrch.left is not None:
                self.root = vrch.left
            elif vrch.right is not None:
                self.root = vrch.right
            else:
                self.root = None
            return

        if vrch == pred.left:
            if vrch.left is not None:
                pred.left = vrch.left
            elif vrch.right is not None:
                pred.left = vrch.right
            else:
                pred.left = None
        elif vrch == pred.right:
            if vrch.left is not None:
                pred.right = vrch.left
            elif vrch.right is not None:
                pred.right = vrch.right
            else:
                pred.right = None

    def vyhod(self, hodnota):
        if not self.hladaj(hodnota):
            raise KeyError(hodnota)

        pred = None
        vrch = self.root

        while vrch.data != hodnota:
            if vrch.data > hodnota:
                pred = vrch
                vrch = vrch.left
            else:
                pred = vrch
                vrch = vrch.right

        if vrch.left is not None and vrch.right is not None:
            pom = vrch.left
            pred = vrch
            while pom.right is not None:
                pred = pom
                pom = pom.right
            vrch.data = pom.data
            self.vyhod_pom(pred, pom)
        else:
            self.vyhod_pom(pred, vrch)


class AritmetickyStrom:
    canvas = None

    class Vrchol:
        def __init__(self, data, left=None, right=None):
            self.data, self.left, self.right = data, left, right

    def __init__(self, postfix=None):
        self.root = None
        if postfix is not None:
            stack = []
            for i in postfix.split():
                if i.isdigit():
                    stack.append(self.Vrchol(int(i)))
                else:
                    stack.append(self.Vrchol(i, stack.pop(), stack.pop()))
            self.root = stack.pop()

    def vyhodnot(self):

        def hodnota(vrch):
            if vrch is None:
                raise SyntaxError
            if vrch.left is None and vrch.right is None:
                return vrch.data
            hodn1 = hodnota(vrch.left)
            hodn2 = hodnota(vrch.right)
            if vrch.data == '+':
                return hodn1 + hodn2
            if vrch.data == '-':
                return hodn1 - hodn2
            if vrch.data == '*':
                return hodn1 * hodn2
            if vrch.data == '/':
                return hodn1 // hodn2
            raise SyntaxError

        return hodnota(self.root)

    def kresli(self):

        # ---- vnorená rekurzívna funkcia ----

        def kresli_rek(vrch, sirka, x, y):
            if vrch.left is not None:
                self.canvas.create_line(x, y, x - sirka / 2, y + 50)
                kresli_rek(vrch.left, sirka / 2, x - sirka / 2, y + 50)
            if vrch.right is not None:
                self.canvas.create_line(x, y, x + sirka / 2, y + 50)
                kresli_rek(vrch.right, sirka / 2, x + sirka / 2, y + 50)
            self.canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightblue', width=0)
            self.canvas.create_text(x, y, text=vrch.data, font='consolas 15 bold')

        if self.canvas is None:
            self.canvas = tkinter.Canvas(width=600, height=300, bg='white')
            self.canvas.pack()
        else:
            self.canvas.delete('all')
        kresli_rek(self.root, 300, 300, 30)

        self.canvas.mainloop()

    def prefix(self):
        def rek(vrch, text):
            if vrch is None:
                return
            text.append(str(vrch.data))
            rek(vrch.left, text)
            rek(vrch.right, text)
        to_ret = []
        rek(self.root, to_ret)
        return " ".join(to_ret)

    def infix(self):
        def rek(vrch, text):
            if vrch is None:
                return
            if type(vrch.data) is not int and type(vrch.data) is not float:
                text.append("(")
            rek(vrch.left, text)
            text.append(str(vrch.data))
            rek(vrch.right, text)
            if type(vrch.data) is not int and type(vrch.data) is not float:
                text.append(")")
        to_ret = []
        rek(self.root, to_ret)
        return "".join(to_ret)

    def postfix(self):
        def rek(vrch, text):
            if vrch is None:
                return
            rek(vrch.left, text)
            rek(vrch.right, text)
            text.append(str(vrch.data))
        to_ret = []
        rek(self.root, to_ret)
        return " ".join(to_ret)


class Trie:
    canvas = None

    class Vrchol:
        def __init__(self):
            self.data = None
            self.child = []

    def __init__(self):
        self.root = self.Vrchol()

    def vloz(self, slovo, data=1):
        vrch = self.root
        for znak in slovo:
            for znak1, vrch1 in vrch.child:
                if znak1 == znak:
                    break
            else:
                vrch1 = self.Vrchol()
                vrch.child.append((znak, vrch1))
            vrch = vrch1
        vrch.data = data

    def all(self, vrch, slovo=''):
        if vrch.data is not None:
            yield slovo
        for znak1, vrch1 in vrch.child:
            yield from self.all(vrch1, slovo + znak1)

    def __iter__(self):
        return self.all(self.root)

    def __len__(self):
        slova = sorted(list(self.all(self.root)), key=len, reverse=True)
        return len(slova[0])

    def prefix(self, slovo):
        vrch = self.root
        for znak in slovo:
            for znak1, vrch1 in vrch.child:
                if znak1 == znak:
                    vrch = vrch1
                    break
            else:
                return None
        return self.all(vrch, slovo)

    def kresli(self, vrch=None, znak='"', width=None, x=None, y=None):

        def sipka(x1, y1, x2, y2, r=15, farba='black', hrubka=1):
            d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** .5
            xx, yy = (x2 - x1) * r / d, (y2 - y1) * r / d
            self.canvas.create_line(x1 + xx, y1 + yy, x2 - xx, y2 - yy, width=hrubka, fill=farba, arrow='last')

        if self.canvas is None:
            self.canvas = tkinter.Canvas(bg='white', width=1000, height=800)
            self.canvas.pack()
        if vrch is None:
            self.canvas.delete('all')
            vrch = self.root
            if width is None: width = int(self.canvas['width']) - 20
            if x is None: x = 10
            if y is None: y = 30
        n = len(vrch.child)
        x0 = x + width // 2
        if n > 0:
            width1 = width // n
            for i, (znak1, vrch1) in enumerate(sorted(vrch.child)):
                sipka(x0, y, x + i * width1 + width1 // 2, y + 50)
                self.kresli(vrch1, znak1, width1, x + i * width1, y + 50)
        f = 'white' if vrch.data is None else 'lightgray'
        self.canvas.create_oval(x0 - 15, y - 15, x0 + 15, y + 15, fill=f)
        self.canvas.create_text(x0, y, text=znak, font='courier 12 bold')
        if vrch is self.root:
            self.canvas.update()
            self.canvas.after(500)


# uloha 4*
# s = BVS()
# v = BVS.Vrchol
# # s.root = v(16, v(3, v(1, None, v(2)), v(5)), v(20, v(19, v(18, v(17)), v(21)), v(23)))
# s.root = v(16, v(3, v(1, None, v(2)), v(5)), v(21, v(19, v(18, v(17)), v(20)), v(23)))
# print(s.kontrola())
# s.kresli()

# uloha 5*
# # s = BVS('KE BS PO PE PK BA BL NI SC BB RK BR'.split())
# s = BVS((20, 10, 35, 3, 12, 33, 36, 7, 11, 21, 25, 34, 37, 5, 9, 14, 32))
# s = BVS((10, 5, 18, 2, 9, 13, 21, 1, 4, 6, 11, 15, 20, 22, 3, 8, 12, 14, 16, 19, 7, 17))
# s.kresli()

# uloha 6*
# s = BVS('KE BS PO PE PK BA BL NI SC BB RK BR'.split())
# print(s.min())
# print(s.max())

# uloha 7*
# zoz = [16, 20, 3, 21, 19, 5, 1, 23, 18, 2, 17]
# s = BVS(zoz)
# print(list(s.inorder()) == sorted(zoz))
# print(list(s.preorder()))
# # s.kresli()
# s2 = BVS(list(s.preorder()))
# s2.kresli()

# uloha 8*
# s = BVS('KE BS PO PE PK BA BL NI SC BB RK BR'.split())
# s.vyhod("BL")
# s.vyhod("SC")
# s.vyhod("KE")
# s.vyhod_pom(s.Vrchol(None), s.Vrchol(1, s.Vrchol(11), s.Vrchol(12)))
# s.vyhod("IA")
# s.kresli()

# uloha 9*

def vyrob_BVS(postupnost):
    postupnost = sorted(postupnost)
    final = []

    def rek(arr, final):
        if len(arr) == 1:
            final.append(arr[0])
            return
        final.append(arr[len(arr)//2])
        rek(arr[:len(arr)//2], final)
        rek(arr[len(arr)//2 + 1:], final)
    rek(postupnost, final)
    return BVS(final)


s = vyrob_BVS('KE BS PO PE PK BA BL NI SC BB RK BR SE NO SK'.split())
s.kresli()

# uloha 11*
# v = AritmetickyStrom.Vrchol
# s = AritmetickyStrom()
# s.root = v('+', v('*', v(5), v('+', v(1), v(3))), v('/', v(15), v(3)))
# print('vyhodnotenie =', s.vyhodnot())
# s.kresli()

# uloha 12*
# v = AritmetickyStrom.Vrchol
# s = AritmetickyStrom()
# s.root = v('+', v('*', v(5), v('+', v(1), v(3))), v('/', v(15), v(3)))
# print('prefix =', s.prefix())
# print('infix =', s.infix())
# print('postfix =', s.postfix())

# uloha 13*
# s = AritmetickyStrom('5 1 3 + * 15 3 / +')
# print(s.vyhodnot())
# s.kresli()

# uloha 15*
# t = Trie()
# with open('dobs.txt', encoding='utf-8') as file:
#     for slovo in file.read().split():
#         t.vloz(slovo)
# print(len(t))
# print(len(list(t)))
# print(list(t.prefix('boh')))

# t = Trie()
# for slovo in ("pes", "slon", "prasa", "tiger", "slak", "pero", "prak", "tuja", "tik", "slina", "tunel"):
#     t.vloz(slovo)
#     t.kresli()
# while slovo:
#     slovo = input('zadaj slovo: ')
#     t.vloz(slovo)
#     t.kresli()
