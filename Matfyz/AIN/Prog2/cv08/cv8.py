import tkinter, random


class Vizualizuj:
    def __init__(self, zoz):
        self.zoz = zoz
        self.canvas = tkinter.Canvas(width=800, height=600, bg='white')
        self.canvas.pack()
        self.dx = 800 / len(zoz)
        self.id = {}
        for i in range(len(zoz)):
            self.id[i] = self.canvas.create_line(i*self.dx, 600, i*self.dx, 600-zoz[i])

    def __getitem__(self, index):
        return self.zoz[index]

    def __setitem__(self, index, hodnota):
        self.zoz[index] = hodnota
        self.canvas.coords(self.id[index], index*self.dx, 600, index*self.dx, 600-hodnota)
        self.canvas.update()

    def __len__(self):
        return len(self.zoz)


def vymen(zoz, i, j):
    zoz[i], zoz[j] = zoz[j], zoz[i]


def bubble_sort(zoz):
    for i in range(len(zoz)):
        for j in range(len(zoz)-1):
            if zoz[j] > zoz[j+1]:
                vymen(zoz, j, j+1)
        # print(*zoz)


def min_sort(zoz):
    for i in range(len(zoz)-1):
        for j in range(i+1, len(zoz)):
            if zoz[i] > zoz[j]:
                vymen(zoz, i, j)
        # print(*zoz)


def insert_sort(zoz):
    for i in range(1, len(zoz)):
        j = i
        while j > 0 and zoz[j-1] > zoz[j]:
            vymen(zoz, j-1, j)
            j -= 1
        # print(*zoz)


def quick_sort(zoz):
    def quick(z, k):
        if z < k:
            # rozdelenie na dve časti
            index = z
            pivot = zoz[index]
            for i in range(z+1, k+1):
                if zoz[i] < pivot:
                    index += 1
                    vymen(zoz, index, i)
            vymen(zoz, index, z)
            # v index je teraz pozícia pivota
            quick(z, index-1)
            quick(index+1, k)

    quick(0, len(zoz)-1)


def merge_sort(zoz):
    if len(zoz) < 2:
        return
    stred = len(zoz)//2
    zoz1 = zoz[:stred]
    zoz2 = zoz[stred:]
    merge_sort(zoz1)
    merge_sort(zoz2)
    # zlučovanie oboch častí do výsledného zoznamu:
    i = j = 0
    while i + j < len(zoz):
        if j == len(zoz2) or i < len(zoz1) and zoz1[i] < zoz2[j]:
            zoz[i+j] = zoz1[i]
            i += 1
        else:
            zoz[i+j] = zoz2[j]
            j += 1


def heap_sort(zoz):

    def nadol(i):
        while True:
            lavy = i*2 + 1
            if lavy >= koniec:
                return
            vacsi = lavy
            pravy = i*2 + 2
            if pravy < koniec and zoz[pravy] > zoz[lavy]:
                vacsi = pravy
            if zoz[i] < zoz[vacsi]:
                zoz[vacsi], zoz[i] = zoz[i], zoz[vacsi]
                i = vacsi
            else:
                return

    koniec = len(zoz)
    for v in reversed(range(len(zoz)//2)):   # heapify
        nadol(v)
    #print('priprav haldu', *zoz)
    while koniec > 0:
        zoz[0], zoz[koniec-1] = zoz[koniec-1], zoz[0]
        koniec -= 1
        nadol(0)
        #print('prechod', *zoz[:koniec], '|', *zoz[koniec:])


# uloha 2*
# z = [1, 3, 5, 7, 9]
# bubble_sort(z)
# print()
# min_sort(z)
# print()
# insert_sort(z)

# uloha 4*
# zz = [random.randrange(300) for _ in range(300)]
# # bubble_sort(Vizualizuj(zz))
# # min_sort(Vizualizuj(zz))
# # insert_sort(Vizualizuj(zz))
# # quick_sort(Vizualizuj(zz))
# heap_sort(Vizualizuj(zz))
# tkinter.mainloop()

# uloha 5*

# def zisti(postupnost, vzost=True):
#     if vzost:
#         for i in range(1, len(postupnost)):
#             if postupnost[i] < postupnost[i-1]:
#                 return False
#     else:
#         for i in range(1, len(postupnost)):
#             if postupnost[i] > postupnost[i-1]:
#                 return False
#     return True
#
#
# print(zisti([1, 3, 3, 4]))
# print(zisti(range(10)))
# print(zisti(range(10), False))

# uloha 6*

# def bubble_sort2(zoz):
#     for i in range(len(zoz)):
#         for j in range(len(zoz) - 1):
#             if zoz[j].split()[1] == zoz[j + 1].split()[1]:
#                 if zoz[j] > zoz[j + 1]:
#                     vymen(zoz, j, j + 1)
#             elif zoz[j].split()[1] > zoz[j + 1].split()[1]:
#                 vymen(zoz, j, j + 1)
#
#
# z = ['Juraj Hrasko', 'Peter Botafogo', 'Juraj Janosik', 'Adam Sangala', 'Janko Hrasko']
# bubble_sort(z)
# print(*z, sep='\n')
#
# print()
#
# z = ['Juraj Hrasko', 'Peter Botafogo', 'Juraj Janosik', 'Adam Sangala', 'Janko Hrasko']
# bubble_sort2(z)
# print(*z, sep='\n')

# uloha 7*

# def min_sort_rev(zoz):
#     # for i in range(len(zoz) - 1):
#     #     for j in range(i + 1, len(zoz)):
#     #         if zoz[i] > zoz[j]:
#     #             vymen(zoz, i, j)
#
#     for i in range(len(zoz)-1, 0, -1):
#         for j in range(i-1, -1, -1):
#             if zoz[i] > zoz[j]:
#                 vymen(zoz, i, j)
#
#
# zz = [random.randrange(1000) for i in range(1000)]
# szz = sorted(zz, reverse=True)
# min_sort_rev(zz)
# print(zz == szz)

# uloha 12*

# halda = [4, 5, 6, 9, 7, 11, 8, 17, 13, 14, 10, 15, 18, 16, 12]
# # po odstránení najmenšieho
# halda = [5, 7, 6, 9, 10, 11, 8, 17, 13, 14, 12, 15, 18, 16]
# # po odstránení najmenšieho
# halda = [6, 7, 8, 9, 10, 11, 16, 17, 13, 14, 12, 15, 18]

# uloha 13*

# def kontrola_na_haldu(zoz):
#     for i in range(1, len(zoz)+1):
#         try:
#             if zoz[i-1] > zoz[2*i-1]:
#                 return False
#             if zoz[i-1] > zoz[2*i]:
#                 return False
#         except IndexError:
#             continue
#     return True
#
#
# halda = [4, 5, 6, 9, 7, 11, 8, 17, 13, 14, 10, 15, 18, 16, 12]
# zoz = [8, 13, 7, 10, 5, 15, 12, 17, 9, 14, 4, 11, 18, 16, 6]
# print(kontrola_na_haldu(halda))
# print(kontrola_na_haldu(zoz))

# uloha 14

# halda1 = [1, 2, 3, 7, 4, 5, 6, 8, 9, 10]
# halda2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# uloha 15*

# def utried1(veta):
#     return " ".join(sorted(veta.split()))
#
#
# def utried2(veta):
#     return " ".join(sorted(veta.split(), reverse=True))
#
#
# def utried3(veta):
#     return " ".join(sorted(sorted(veta.split()), key=(lambda x: len(x))))
#
#
# print(utried1('kohutik jaraby nechod do zahrady'))
# print(utried2('kohutik jaraby nechod do zahrady'))
# print(utried3('jano ide z blavy do brna'))

# uloha 17*

def najcastejsie(string):
    pom = "" + string
    pom = pom.replace("\n", " ").split()
    pocty = []
    pouzite = []
    for i in range(len(pom)):
        if pom[i] not in pouzite:
            pouzite.append(pom[i])
            pocty.append((pom[i], pom.count(pom[i])))

    pocty = sorted(pocty, key=lambda x: x[1], reverse=True)
    for i in range(10):
        print(pocty[i])


najcastejsie(open('dobs.txt').read())
