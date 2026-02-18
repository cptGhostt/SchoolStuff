import tkinter, random
canvas = tkinter.Canvas(width=500, height=500)
canvas.pack()


class Vrchol:
    def __init__(self, data, left=None, right=None):
        self.data, self.left, self.right = data, left, right

    def __repr__(self):
        return f'Vrchol({self.data!r}, {self.left}, {self.right})'.replace(", None, None", "").replace(", None)", ")")


def pridaj_vrchol(vrch, hodnota):
    while True:
        if random.randrange(2):
            if vrch.left is None:
                vrch.left = Vrchol(hodnota)
                return
            vrch = vrch.left
        else:
            if vrch.right is None:
                vrch.right = Vrchol(hodnota)
                return
            vrch = vrch.right


def pocet(vrch):
    if vrch is None:
        return 0
    return 1 + pocet(vrch.left) + pocet(vrch.right)


# uloha 4*

def kresli(v, sir, x, y):
    if v.left is not None:
        canvas.create_line(x, y, x-sir/2, y+40)
        kresli(v.left, sir/2, x-sir/2, y+40)
    if v.right is not None:
        canvas.create_line(x, y, x+sir/2, y+40)
        kresli(v.right, sir/2, x+sir/2, y+40)
    if (v.left is None) and (v.right is None):
        canvas.create_oval(x - 15, y - 15, x + 15, y + 15, fill='lightgreen')
    else:
        canvas.create_oval(x-15, y-15, x+15, y+15, fill='lightblue')
    canvas.create_text(x, y, text=v.data, font='consolas 12')


# strom = Vrchol('p')
# for i in 'rogramovanie':
#     pridaj_vrchol(strom, i)
#
# kresli(strom, 200, 250, 40)


# TODO uloha 7*

# def vyrob_strom(postupnost):
#     to_ret = Vrchol(postupnost[0])
#     vrch = to_ret
#     tmp = postupnost[1:]
#     for hodnota in tmp:
#         if random.randrange(2):
#             if vrch.left is None:
#                 vrch.left = Vrchol(hodnota)
#                 return
#             vrch = vrch.left
#         else:
#             if vrch.right is None:
#                 vrch.right = Vrchol(hodnota)
#                 return
#             vrch = vrch.right
#
#     return to_ret
#
#
# strom = vyrob_strom('Python')
# kresli(strom, 200, 250, 40)

# uloha 8*

def pocet_listov(vrch):
    if vrch is None:
        return 0
    if vrch.left is None and vrch.right is None:
        return 1
    return pocet_listov(vrch.left) + pocet_listov(vrch.right)


# strom = Vrchol(7,Vrchol(13,None,Vrchol(5,Vrchol(8))),Vrchol(2,Vrchol(11,Vrchol(19)),Vrchol(3)))
# print(pocet(strom))
# print(pocet_listov(strom))
# strom = Vrchol(1, Vrchol(2, Vrchol(3, Vrchol(4, Vrchol(5)))))
# print(pocet_listov(strom))
# strom = None
# print(pocet_listov(strom))

# uloha 9*

# s = Vrchol('a', Vrchol('b', right=Vrchol('c')), Vrchol('d', Vrchol('f'), Vrchol('e')))
# print(s)
# print(Vrchol('a', Vrchol('a', Vrchol('a')), Vrchol('a', Vrchol('a'))))

# uloha 12*

def pocet2(vrch: Vrchol) -> int:
    

canvas.mainloop()
