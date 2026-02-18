# uloha 1

# from cas import Cas
#
# # class Cas:
# #
# #     def __init__(self, hodiny, minuty):
# #         self.hodiny = hodiny
# #         self.minuty = minuty
# #
# #     def vypis(self):
# #         if __name__ == "__main__":
# #             print(f"cas je {self.hodiny:02}:{self.minuty:02}")
#
#
# c = Cas(9, 17)
# c.vypis()
# d = Cas(10, 5)
# d.vypis()

# uloha 2

# class Cas:
#
#     def __init__(self, hodiny, minuty):
#         self.hodiny = hodiny
#         self.minuty = minuty
#
#     def vypis(self):
#         if __name__ == "__main__":
#             print(f"cas je {self.hodiny:02}:{self.minuty:02}")
#
#     def str(self):
#         return f"{self.hodiny:02}:{self.minuty:02}"
#
#
# c = Cas(9,1)
# c.vypis()
# print("teraz je", c.str())

# uloha 3

# class Cas:
#
#     def __init__(self, hodiny, minuty):
#         self.hodiny = hodiny
#         self.minuty = minuty
#
#     def vypis(self):
#         if __name__ == "__main__":
#             print(f"cas je {self.hodiny:02}:{self.minuty:02}")
#
#     def str(self):
#         return f"{self.hodiny:02}:{self.minuty:02}"
#
#     def pridaj(self, hodiny, minuty):
#         self.hodiny += hodiny
#         self.minuty += minuty
#
#         if self.minuty > 59:
#             self.hodiny += self.minuty//60
#             self.minuty %= 60
#
#         if self.hodiny > 23:
#             self.hodiny %= 24
#
#
# cas = Cas(17, 40)
# print('teraz je', cas.str())
# cas.pridaj(1, 35)
# print('neskôr', cas.str())
# print()

# uloha 4

# class Cas:
#
#     def __init__(self, hodiny, minuty):
#         self.hodiny = hodiny
#         self.minuty = minuty
#
#     def vypis(self):
#         if __name__ == "__main__":
#             print(f"cas je {self.hodiny:02}:{self.minuty:02}")
#
#     def str(self):
#         return f"{self.hodiny:02}:{self.minuty:02}"
#
#     def pridaj(self, hodiny, minuty):
#         self.hodiny += hodiny
#         self.minuty += minuty
#
#         if self.minuty > 59:
#             self.hodiny += self.minuty//60
#             self.minuty %= 60
#
#         if self.hodiny > 23:
#             self.hodiny %= 24
#
#
# def neskor(cas, hodiny, minuty):
#     new = Cas(cas.hodiny, cas.minuty)
#     new.pridaj(hodiny, minuty)
#
#     return new
#
#
# c = Cas(17, 40)
# d = neskor(c, 2, 55)
# print(c.str())
# print(d.str())
#
# zoznam = [Cas(8, 10)]
# for i in range(14):
#     zoznam.append(neskor(zoznam[len(zoznam) - 1], 0, 50))
#
# for c in zoznam:
#     print(c.str(), end=' ')

# uloha 5

# from zlomky import Zlomok
#
#
# # class Zlomok:
# #     def __init__(self, citatel, menovatel):
# #         self.citatel = citatel
# #         self.menovatel = menovatel
# #
# #     def vypis(self):
# #         print(f"zlomok je {self.citatel}/{self.menovatel}")
#
#
# z1 = Zlomok(3, 8)
# z2 = Zlomok(2, 4)
# z1.vypis()
# z2.vypis()

# uloha 6

# class Zlomok:
#     def __init__(self, citatel, menovatel):
#         self.citatel = citatel
#         self.menovatel = menovatel
#
#     def vypis(self):
#         print(f"zlomok je {self.citatel}/{self.menovatel}")
#
#     def str(self):
#         return f"{self.citatel}/{self.menovatel}"
#
#     def float(self):
#         return self.citatel / self.menovatel
#
#
# z = Zlomok(3, 8)
# print('z je', z.str())
# print('z je', z.float())
# w = Zlomok(2, 4)
# print('w je', w.str())
# print('w je', w.float())

# uloha 7

# from body import Body
#
#
# # class Body:
# #     def __init__(self):
# #         self.body = 0
# #
# #     def pridaj(self):
# #         self.body += 1
# #
# #     def uber(self):
# #         self.body -= 1
# #
# #     def kolko(self):
# #         return self.body
#
#
# b = Body()
# for i in range(10):
#     b.pridaj()
# b.uber()
# b.uber()
# print('body =', b.kolko())

# uloha 8

# from subor import Subor
#
#
# # class Subor:
# #     def __init__(self, meno_suboru):
# #         self.meno_suboru = meno_suboru
# #         with open(meno_suboru, "w") as f:
# #             pass
# #
# #     def pripis(self, text):
# #         with open(self.meno_suboru, "a") as file:
# #             file.write(text + "\n")
# #
# #     def vypis(self):
# #         with open(self.meno_suboru, "r") as file:
# #             print(file.read(), end="")
#
#
# s = Subor('text.txt')
# s.pripis('prvy riadok')
# s.pripis('druhy riadok')
# s.vypis()
# s.pripis('posledny riadok')
# print('***')
# s.vypis()

# uloha 9

# from kniha import Kniha
#
#
# # class Kniha:
# #     def __init__(self, autor, titul):
# #         self.autor = autor
# #         self.titul = titul
# #         self.vydavatel = None
# #         self.rok = None
# #
# #     def nastav_vydavatela(self, vydavatel):
# #         self.vydavatel = vydavatel
# #
# #     def nastav_rok(self, rok):
# #         self.rok = rok
# #
# #     def vypis(self):
# #         print(f"Kniha: {self.autor}: {self.titul}", end="")
# #         if self.vydavatel is not None:
# #             print(f", {self.vydavatel}", end="")
# #         if self.rok is not None:
# #             print(f", {self.rok}", end="")
# #         print()
#
#
# k1 = Kniha('Dobsinsky', 'Rozpravky')
# k1.nastav_vydavatela('Mlade Leta')
# k2 = Kniha('Lasica', 'Bodka')
# k2.nastav_rok(2007)
# k1.vypis()
# k2.vypis()

# uloha 10

# from zoznam import Zoznam
#
#
# # class Zoznam:
# #     def __init__(self):
# #         self.zoznam = []
# #
# #     def pridaj(self, prvok):
# #         if prvok not in self.zoznam:
# #             self.zoznam.append(prvok)
# #
# #     def vyhod(self, prvok):
# #         if prvok in self.zoznam:
# #             self.zoznam.pop(self.zoznam.index(prvok))
# #
# #     def je_v_zozname(self, prvok):
# #         return prvok in self.zoznam
# #
# #     def vypis(self):
# #         print("zoznam: ", end="")
# #         if len(self.zoznam) > 0:
# #             print(self.zoznam[0], end="")
# #         for i in range(1, len(self.zoznam)):
# #             print(",",self.zoznam[i], end="")
# #         print()
#
#
# moj = Zoznam()
# moj.pridaj('upratat')
# moj.pridaj('behat')
# moj.pridaj('ucit sa')
# if moj.je_v_zozname('behat'):
#     print('musis behat')
# else:
#     print('nebehaj')
# moj.pridaj('upratat')
# moj.vyhod('spievat')
# moj.vypis()

# uloha 11

# from telefony import TelefonnyZoznam
#
#
# # class TelefonnyZoznam:
# #     def __init__(self):
# #         self.zoznam = []
# #
# #     def pridaj(self, meno, telefon):
# #         for i in self.zoznam:
# #             if i[0] == meno:
# #                 self.zoznam.insert(self.zoznam.index(i), (meno, telefon))
# #                 self.zoznam.pop(self.zoznam.index(i))
# #                 return
# #         self.zoznam.append((meno, telefon))
# #
# #     def vypis(self):
# #         for i in self.zoznam:
# #             print(i[0], i[1])
#
#
#
# tz = TelefonnyZoznam()
# tz.pridaj('Jana', '0901020304')
# tz.pridaj('Juro', '0911111111')
# tz.pridaj('Jozo', '0212345678')
# tz.pridaj('Jana', '0999020304')
# tz.vypis()

# uloha 12

import tkinter
from okno import Okno


# class Okno:
#
#     def __init__(self, text):
#         self.c = tkinter.Canvas(height=100)
#         self.c.pack()
#         self.id = self.c.create_text(190, 50, text=text, font="Arial 50")
#
#     def zmen(self, text):
#         self.c.itemconfig(self.id, text=text)
#
#     def farba(self, farba):
#         self.c.itemconfig(self.id, fill=farba)


okno = Okno('ahoj')
okno.farba('red')
okno.zmen('Python')

tkinter.mainloop()
