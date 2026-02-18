import tkinter, random


class Graf:

    class Vrchol:
        canvas = None
        def __init__(self, meno, x, y):
            self.meno = meno
            self.xy = x, y
            self.sus = set()

        def kresli(self):
            x, y = self.xy
            self.id = self.canvas.create_oval(x-10, y-10, x+10, y+10, fill='lightgray')
            self.canvas.create_text(x, y, text=self.meno)

        def zafarbi(self, farba):
            self.canvas.itemconfig(self.id, outline=farba, width=2)

    # ----------------------------------------------

    def __init__(self, n):
        self.vrcholy = []
        for i in range(n):
            for j in range(n):
                k = len(self.vrcholy)
                self.pridaj_vrchol(k, j * 40 + 20, i * 40 + 20)
                if j > 0 and random.randrange(3):
                    self.pridaj_hranu(k, k - 1)
                if i > 0 and random.randrange(3):
                    self.pridaj_hranu(k, k - n)
        self.canvas = tkinter.Canvas(bg='white', width=600, height=600)
        self.canvas.pack()
        self.Vrchol.canvas = self.canvas
        self.kresli()

    def pridaj_vrchol(self, meno, x, y):
        self.vrcholy.append(self.Vrchol(meno, x, y))

    def pridaj_hranu(self, v1, v2):
        self.vrcholy[v1].sus.add(v2)
        self.vrcholy[v2].sus.add(v1)

    def je_hrana(self, v1, v2):
        return v2 in self.vrcholy[v1].sus

    def kresli_hranu(self, v1, v2):
        self.canvas.create_line(self.vrcholy[v1].xy, self.vrcholy[v2].xy, width=3, fill='gray')

    def kresli(self):
        for v1 in range(len(self.vrcholy)):
            for v2 in range(v1+1, len(self.vrcholy)):
                if self.je_hrana(v1, v2):
                    self.kresli_hranu(v1, v2)
        for vrch in self.vrcholy:
            vrch.kresli()

    def zafarbi_komponent(self, v1, farba="red"):
        # rekurzívna verzia

        # def rek(v, f):
        #     self.vrcholy[v].zafarbi(f)
        #     visited.add(v)
        #
        #     for i in self.vrcholy[v].sus:
        #         if i not in visited:
        #             rek(i, f)
        #
        # visited = set()
        # rek(v1, farba)

        # nerekurzívna verzia

        stack = [v1]
        visited = set()
        while stack:
            v = stack.pop()
            visited.add(v)
            self.vrcholy[v].zafarbi(farba)
            for i in self.vrcholy[v].sus:
                if i not in visited:
                    stack.append(i)

    def max_komponent(self):
        # rekurzívna verzia

        # def rek(v):
        #     visited.add(v)
        #     curr.add(v)
        #
        #     for i in self.vrcholy[v].sus:
        #         if i not in curr:
        #             rek(i)
        #
        # visited = set()
        # to_ret = 0
        # for i in self.vrcholy:
        #     curr = set()
        #     if i.meno not in visited:
        #         rek(i.meno)
        #         if len(curr) > to_ret:
        #             to_ret = len(curr)
        #
        # return to_ret

        # nerekurzívna verzia

        visited = set()
        to_ret = 0
        for i in self.vrcholy:
            if i.meno not in visited:
                stack = [i.meno]
                curr = set()
                while stack:
                    v = stack.pop()
                    visited.add(v)
                    curr.add(v)

                    for i in self.vrcholy[v].sus:
                        if i not in curr:
                            stack.append(i)

                if len(curr) > to_ret:
                    to_ret = len(curr)

        return to_ret

    def vsetky_komponenty(self):
        # rekurzívna verzia

        # def rek(v):
        #     visited.add(v)
        #     curr.add(v)
        #
        #     for i in self.vrcholy[v].sus:
        #         if i not in curr:
        #             rek(i)
        #
        # visited = set()
        # to_ret = []
        # for i in self.vrcholy:
        #     curr = set()
        #     if i.meno not in visited:
        #         rek(i.meno)
        #         to_ret.append(len(curr))
        #
        # return to_ret

        # nerekurzívna verzia

        visited = set()
        to_ret = []
        for i in self.vrcholy:
            if i.meno not in visited:
                curr = set()
                stack = [i.meno]
                while stack:
                    v = stack.pop()
                    visited.add(v)
                    curr.add(v)

                    for i in self.vrcholy[v].sus:
                        if i not in curr:
                            stack.append(i)

                to_ret.append(len(curr))

        return to_ret

    def v_komponente(self, v1, v2):
        # rekurzívna verzia

        # def rek(v):
        #     visited.add(v)
        #
        #     for i in self.vrcholy[v].sus:
        #         if i not in visited:
        #             rek(i)
        #
        # visited = set()
        # rek(v1)
        # return v2 in visited

        # nerekurzívna verzia

        visited = set()
        stack = [v1]
        while stack:
            v = stack.pop()
            visited.add(v)

            for i in self.vrcholy[v].sus:
                if i not in visited:
                    stack.append(i)

        return v2 in visited

    def vypis_dosirky(self, v1):
        queue = [v1]
        visited = set()
        while queue:
            v1 = queue.pop(0)
            if v1 not in visited:
                visited.add(v1)
                print(self.vrcholy[v1].meno, end=' ')
                for v2 in sorted(self.vrcholy[v1].sus):
                    if v2 not in visited:
                        queue.append(v2)

    def vzdialenost(self, v1, ciel):
        visited = set()
        queue = [(v1, 0)]
        while queue:
            v1, uroven = queue.pop(0)
            if v1 not in visited:
                visited.add(v1)
                if v1 == ciel:
                    return uroven
                for v2 in self.vrcholy[v1].sus:
                    if v2 not in visited:
                        queue.append((v2, uroven + 1))
        return -1

    def cesta(self, v1, ciel):
        visited = set()
        queue = [(v1, None)]
        while queue:
            v1, predchodca = queue.pop(0)
            if v1 not in visited:
                visited.add(v1)
                self.vrcholy[v1].pred = predchodca
                if v1 == ciel:
                    vysl = []
                    while v1 is not None:
                        vysl.append(v1)
                        v1 = self.vrcholy[v1].pred
                    return vysl[::-1]
                for v2 in self.vrcholy[v1].sus:
                    if v2 not in visited:
                        queue.append((v2, v1))
        return []

    def kresli_cestu(self, v1, ciel, farba="red"):
        cesta = self.cesta(v1, ciel)
        if cesta:
            for v1 in range(len(cesta) - 1):
                self.vrcholy[cesta[v1]].zafarbi(farba)
                # self.zafarbi_hranu(cesta[v1], cesta[v1 + 1], farba)
            self.vrcholy[cesta[-1]].zafarbi(farba)
        else:
            print('cesta neexistuje')

    def vypis_urovne(self, v1):
        queue = [(v1, 0)]
        visited = set()
        to_ret = {}

        while queue:
            v, uroven = queue.pop(0)
            if v not in visited:
                visited.add(v)
                try:
                    to_ret[uroven].add(v)
                except KeyError:
                    to_ret[uroven] = {v}
                for i in self.vrcholy[v].sus:
                    queue.append((i, uroven+1))

        for i in range(len(to_ret)):
            print(f"uroven {i}: {to_ret[i]}")

    def uroven(self, v1, k):
        queue = [(v1, 0)]
        to_ret = set()
        visited = set()

        while queue:
            v, uroven = queue.pop(0)
            if v not in visited:
                visited.add(v)
                if uroven == k:
                    to_ret.add(v)
                for i in self.vrcholy[v].sus:
                    if i not in visited:
                        queue.append((i, uroven+1))

        return to_ret

    def naj_vzdialenost(self, v1):
        queue = [(v1, 0)]
        to_ret = 0
        visited = set()

        while queue:
            v, uroven = queue.pop(0)
            if v not in visited:
                visited.add(v)
                if uroven > to_ret:
                    to_ret = uroven
                for i in self.vrcholy[v].sus:
                    if i not in visited:
                        queue.append((i, uroven + 1))

        return to_ret

    def premenuj_dohlbky(self, v1, zoznam_mien):
        stack = [v1]
        visited = set()
        index = 0
        while stack:
            v = stack.pop()
            if v not in visited:
                visited.add(v)
                self.vrcholy[v].meno = zoznam_mien[index]
                index += 1
                for i in self.vrcholy[v].sus:
                    if i not in visited:
                        stack.append(i)

    def premenuj_dosirky(self, v1, zoznam_mien):
        queue = [v1]
        visited = set()
        index = 0
        while queue:
            v = queue.pop(0)
            if v not in visited:
                visited.add(v)
                self.vrcholy[v].meno = zoznam_mien[index]
                index += 1
                for i in sorted(self.vrcholy[v].sus):
                    if i not in visited:
                        queue.append(i)

    def poradie(self, v1):

        def dohlbky(v1):
            vysledok.append(v1)
            for v2 in sorted(self.vrcholy[v1].sus):  # usporiadaný zoznam susedov
                if v2 not in vysledok:
                    dohlbky(v2)

        vysledok = []  # zoznam vysledok namiesto množiny visited
        dohlbky(v1)
        return [self.vrcholy[x].meno for x in vysledok]

    def poradie2(self, v1):
        vysledok = []  # zoznam namiesto množiny visited
        queue = [v1]
        while queue:
            v1 = queue.pop(0)
            if v1 not in vysledok:
                vysledok.append(v1)
                for v2 in sorted(self.vrcholy[v1].sus):  # usporiadaný zoznam susedov
                    if v2 not in vysledok:
                        queue.append(v2)
        return [self.vrcholy[x].meno for x in vysledok]


# uloha 2* + uloha 3*

# g = Graf(5)
# g.zafarbi_komponent(0, "blue")
# print(g.max_komponent())
# print(g.vsetky_komponenty())
# print(g.v_komponente(0, 24))
# tkinter.mainloop()

# uloha 5*

# g = Graf(0)
# g.pridaj_vrchol("t", 50, 50)
# g.pridaj_vrchol("u", 100, 50)
# g.pridaj_vrchol("h", 150, 50)
# g.pridaj_vrchol("n", 200, 50)
#
# g.pridaj_vrchol("j", 50, 100)
# g.pridaj_vrchol("g", 100, 100)
# g.pridaj_vrchol("e", 150, 100)
# g.pridaj_vrchol("a", 200, 100)
#
# g.pridaj_vrchol("o", 50, 150)
# g.pridaj_vrchol("r", 100, 150)
# g.pridaj_vrchol("p", 150, 150)
# g.pridaj_vrchol("o", 200, 150)
#
# g.pridaj_vrchol("p", 50, 200)
# g.pridaj_vrchol("r", 100, 200)
# g.pridaj_vrchol("y", 150, 200)
# g.pridaj_vrchol("m", 200, 200)
#
# g.pridaj_hranu(0, 1)
# g.pridaj_hranu(1, 2)
# g.pridaj_hranu(2, 3)
# g.pridaj_hranu(4, 5)
# g.pridaj_hranu(5, 6)
# g.pridaj_hranu(9, 10)
# g.pridaj_hranu(10, 11)
# g.pridaj_hranu(12, 13)
# g.pridaj_hranu(13, 14)
# g.pridaj_hranu(14, 15)
#
# g.pridaj_hranu(4, 8)
# g.pridaj_hranu(8, 12)
# g.pridaj_hranu(1, 5)
# g.pridaj_hranu(5, 9)
# g.pridaj_hranu(9, 13)
# g.pridaj_hranu(11, 15)
# g.pridaj_hranu(7, 11)
#
# g.vypis_dosirky(10)
#
# g.kresli()
# tkinter.mainloop()

# uloha 6*

# g = Graf(15)
# print(g.vzdialenost(0, 14))
# print(g.cesta(0, 14))
# g.kresli_cestu(0, 14)
# tkinter.mainloop()

# uloha 7*

# g = Graf(5)
# g.vypis_urovne(12)
# print(g.uroven(12, 4))
# print(g.naj_vzdialenost(12))
# tkinter.mainloop()

# uloha 8* + uloha 9*

g = Graf(0)
g.pridaj_vrchol(0, 50, 50)
g.pridaj_vrchol(1, 100, 50)
g.pridaj_vrchol(2, 150, 50)

g.pridaj_vrchol(3, 50, 100)
g.pridaj_vrchol(4, 100, 100)
g.pridaj_vrchol(5, 150, 100)

g.pridaj_vrchol(6, 50, 150)
g.pridaj_vrchol(7, 100, 150)
g.pridaj_vrchol(8, 150, 150)

g.pridaj_hranu(0, 1)
g.pridaj_hranu(1, 2)
g.pridaj_hranu(4, 5)
g.pridaj_hranu(6, 7)
g.pridaj_hranu(7, 8)

g.pridaj_hranu(1, 4)
g.pridaj_hranu(2, 5)
g.pridaj_hranu(3, 6)
g.pridaj_hranu(4, 7)

# g.premenuj_dohlbky(4, list('programuj'))
# print(g.poradie(4))
g.premenuj_dosirky(7, list('programuj'))
print(g.poradie2(7))

g.kresli()
tkinter.mainloop()
