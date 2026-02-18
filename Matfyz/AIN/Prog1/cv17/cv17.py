# uloha 1

# a = "7 3"
#
# # print(int(a))   # ValueError
# # print(a < 0)    # TypeError
# # open(a, "r")    # FileNotFoundError
# # int(a[:1])/0    # ZeroDivisionError
# # a.append(x)     # AtributeError
# # a = x()         # NameError
# # assert a == 0   # AssertionError
# # int(a[:1]) ** 10000 / 1   # OverflowError

# uloha 2

# def cele(hodnota):
#     try:
#         return int(hodnota)
#     except (TypeError, ValueError):
#         return 0
#
#
# print(cele(12.3))
# print(cele("13"))
# print(cele([]))
# print(cele("12.3"))

# uloha 3

# def desatinne(retazec):
#     try:
#         return type(float(retazec)) is float
#     except ValueError:
#         return False
#
#
# print(desatinne('123'))
# print(desatinne('  22.7 '))
# print(desatinne('22/7'))

# uloha 4

# def zoznam(retazec):
#     to_ret = []
#     try:
#         tmp = ""
#         tmp += retazec
#         tmp = tmp[1:len(tmp)-1]
#         tmp = tmp.replace(",", " ")
#         tmp = tmp.split()
#
#         for i in tmp:
#             try:
#                 if i.find(".") == -1:
#                     to_ret.append(int(i))
#                 else:
#                     to_ret.append(float(i))
#             except (TypeError, ValueError):
#                 continue
#
#         return to_ret
#     except TypeError:
#         return []
#
#
# print(zoznam('[0, 1., 2, 3.14]'))
# print(zoznam('[0, -.1, None, +2, [7], a5, -3.14, "8"]'))

# uloha 5

# def sucet(post):
#     try:
#         to_ret = post[0]
#
#         for i in range(1, len(post)):
#             try:
#                 to_ret += type(to_ret)(post[i])
#             except (ValueError, TypeError):
#                 continue
#
#         return to_ret
#
#     except IndexError:
#         return None
#
#
# print(sucet([2, '3', 4.0, 'päť']))
# print(sucet(['1', 2, 0.3, 'abc']))
# print(sucet([[1, 2], 3, '4x']))
# print(sucet([(1, 2), (3, 4), [5]]))
# print(sucet([]))

# uloha 6

# def iba_cisla(meno_suboru):
#     try:
#         with open(meno_suboru, "r", encoding="utf8") as f:
#             tmp = f.read()
#             tmp = tmp.replace("\n", " ")
#             tmp = tmp.split()
#
#             to_ret = []
#             for i in tmp:
#                 try:
#                     to_ret.append(int(i))
#                 except ValueError:
#                     continue
#
#             return to_ret
#     except FileNotFoundError:
#         return []
#
#
# print(iba_cisla('subor.txt'))

# TODO uloha 7

#

# uloha 8

# def rgb(r, g, b):
#     assert type(r) is int and 0 <= r <= 255, "chybny prvy parameter r"
#     assert type(g) is int and 0 <= g <= 255, "chybny prvy parameter g"
#     assert type(b) is int and 0 <= b <= 255, "chybny prvy parameter b"
#
#     to_ret = f"#{r:02x}{g:02x}{b:02x}"
#
#     return to_ret
#
#
# # print(rgb(100, 150, 20.0))
# # print(rgb(100, 350, 20.0))
# # print(rgb('100', 350, 20.0))
# print(rgb(100, 150, 200))

# uloha 9

# def sustavy(retazec):
#     to_ret = []
#
#     for i in range(17):
#         try:
#             to_ret.append(int(retazec, i))
#         except ValueError:
#             to_ret.append(None)
#
#     return to_ret
#
#
# print(sustavy('11'))
# print(sustavy('1a1'))
# print(sustavy('FF'))
# print(sustavy('x'))

# uloha 10

class TelefonnyZoznam:
    def __init__(self, meno_suboru=None):
        self.zoznam = []
        self.citaj(meno_suboru)

    def pridaj(self, meno, telefon):
        if type(meno) is not str or type(telefon) is not str:
            raise TypeError

        for i in range(len(self.zoznam)):
            if meno == self.zoznam[i][0]:
                self.zoznam.insert(i, (meno, telefon))
                self.zoznam.pop(i+1)
                return

        self.zoznam.append((meno, telefon))

    def zisti(self, meno):
        for i in self.zoznam:
            if i[0] == meno:
                return i[1]

        raise KeyError

    def citaj(self, meno_suboru):
        try:
            with open(meno_suboru, "r", encoding="utf8") as f:
                for i in f:
                    tmp = i.split(" ")
                    if len(tmp) != 2 or type(tmp[0]) is not str or type(tmp[1]) is not str:
                        raise ValueError
        except FileNotFoundError:
            pass

    def zapis(self, meno_suboru):
        try:
            with open(meno_suboru, "w", encoding="utf8") as f:
                for i in self.zoznam:
                    print(i[0], i[1], file=f)
        except FileNotFoundError:
            pass

    def vypis(self):
        for i in self.zoznam:
            print(i[0], i[1])


t = TelefonnyZoznam("zoznam.txt")
t.pridaj("Jozef", "0123456789")
print(t.zisti("Jozef"))
t.citaj("zoznam.txt")
t.zapis("zoznam.txt")
t.citaj("zoznam.txt")
t.vypis()
