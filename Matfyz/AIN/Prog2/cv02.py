class Vrchol:
    def __init__(self, data, next=None):
        self.data, self.next = data, next


def vypis(zoznam):
    while zoznam is not None:
        print(repr(zoznam.data), end=' -> ')
        zoznam = zoznam.next
    print(None)


def vyrob(postupnost):
    zoz = None
    for hodnota in reversed(postupnost):
        zoz = Vrchol(hodnota, zoz)
    return zoz


# uloha 1

# v1 = Vrchol('v')
# v2 = Vrchol('s')
# v3 = Vrchol('o')
# v4 = Vrchol('a')
# v3.next = v1
# v1.next = v2
# v2.next = v3
# v1.next = v4
# zoz = v2
# vypis(zoz)
#
# v1 = None
# v2 = Vrchol('S', v1)
# v2 = Vrchol('U', v2)
# v3 = Vrchol('I', v1)
# v3 = Vrchol('V', v3)
# v2 = Vrchol('R', v2)
# v3.next.next = v2
# vypis(v3)

# uloha 2

# zoz = Vrchol(3.14, Vrchol(6.28, Vrchol(9.42, Vrchol(None, Vrchol(15.7)))))
# vypis(zoz)
#
# zoz2 = vyrob((3.14, 6.28, 9.42, None, 15.7))
# vypis(zoz2)

# uloha 3

# zoz = vyrob((4, 11, 18, 25))
# vypis(zoz)
# zoz.next.data = (10, 12)
# vypis(zoz)

# uloha 4

# zoz = vyrob("strc prst skrz krk".split())
# vypis(zoz)
# zoz.next.next = Vrchol({1: 2}, zoz.next.next)
# vypis(zoz)

# uloha 5

# def zmen_parne(zoznam: Vrchol, hodnota=0) -> None:
#     while zoznam is not None:
#         try:
#             if zoznam.data % 2 == 0 and type(zoznam.data) == int:
#                 zoznam.data = hodnota
#         except TypeError:
#             pass
#         zoznam = zoznam.next
#
#
# zoz = vyrob((5, 0, 2.12, "2", 18, 4.0, 4))
# vypis(zoz)
# zmen_parne(zoz, 42)
# vypis(zoz)
# zmen_parne(zoz.next.next)
# vypis(zoz)

# uloha 6

# def pocty(zoznam: Vrchol, hodnota=0) -> tuple:
#     viac = 0
#     menej = 0
#
#     while zoznam is not None:
#         try:
#             if zoznam.data > hodnota:
#                 viac += 1
#             elif zoznam.data < hodnota:
#                 menej += 1
#         except TypeError:
#             pass
#         zoznam = zoznam.next
#
#     return viac, menej
#
#
# zoz = vyrob(("prvy", -7, 0.0, 2, "druhy", -3.14, [3]))
# vypis(zoz)
# print(pocty(zoz))
# print(pocty(zoz, "python"))
# vypis(zoz)

# uloha 7

# def zdvoj(zoznam: Vrchol) -> None:
#     while zoznam is not None:
#         try:
#             zoznam.data = zoznam.data * 2
#         except TypeError:
#             pass
#         zoznam = zoznam.next
#
#
# zoz = vyrob((3.14, "6.28", {1, 2}, (9, 42), None, [15.7]))
# vypis(zoz)
# zdvoj(zoz)
# vypis(zoz)

# uloha 8

# def to_str(zoznam: Vrchol) -> str:
#     if type(zoznam.data) is str:
#         to_ret = "'" + zoznam.data + "'"
#     else:
#         to_ret = str(zoznam.data)
#
#     while zoznam is not None:
#         zoznam = zoznam.next
#         if zoznam is not None:
#             if type(zoznam.data) is str:
#                 to_ret += " -> '" + zoznam.data + "'"
#             else:
#                 to_ret += " -> " + str(zoznam.data)
#         else:
#             to_ret += " -> None"
#
#     return to_ret
#
#
# vypis(vyrob(range(10)))
# print(to_str(vyrob(range(10))))
# vypis(vyrob("Python"))
# print(to_str(vyrob('Python')))

# uloha 9

# zoz = vyrob((1, 3, 5, 7, 9, 11, 13))
# v = zoz.next.next
# v1 = v.next.next
# v.next.next = v1.next
# v1.next = v.next
# v.next = v1
# vypis(zoz)

# uloha 10

# def vyhod_prvy(zoznam: Vrchol):
#     if zoznam is None:
#         return None
#     return zoznam.next
#
#
# x = vyrob("py")
# vypis(x)
# x = vyhod_prvy(x)
# vypis(x)
# x = vyhod_prvy(x)
# vypis(x)
# x = vyhod_prvy(x)
# vypis(x)

# uloha 11

# def vyhod_druhy(zoznam: Vrchol) -> None:
#     if zoznam.next is not None:
#         zoznam.next = zoznam.next.next
#
#
# x = vyrob("pyt")
# vypis(x)
# vyhod_druhy(x)
# vypis(x)
# vyhod_druhy(x)
# vypis(x)
# vyhod_druhy(x)
# vypis(x)

# uloha 12

# def vyhod_za(zoznam: Vrchol, hodnota) -> None:
#     while zoznam is not None:
#         if zoznam.data == hodnota and zoznam.next is not None:
#             zoznam.next = zoznam.next.next
#         zoznam = zoznam.next
#
#
# y = vyrob((3, 7, "a", "a", 11))
# vypis(y)
# vyhod_za(y, "a")
# vypis(y)
# vyhod_za(y, 11)
# vypis(y)

# uloha 13

# def vyhod_posledny(zoznam: Vrchol):
#     tmp = []
#
#     while zoznam is not None:
#         tmp.append(zoznam.data)
#         zoznam = zoznam.next
#
#     if len(tmp) > 1:
#         return vyrob(tmp[:-1])
#     else:
#         return None
#
#
# x = Vrchol(5, Vrchol(7))
# vypis(x)
# x = vyhod_posledny(x)
# vypis(x)
# x = vyhod_posledny(x)
# vypis(x)
# x = vyhod_posledny(x)
# vypis(x)

# uloha 14

# def vyhod_kazdy_druhy(zoznam: Vrchol) -> None:
#     while zoznam is not None:
#         if zoznam.next is not None:
#             zoznam.next = zoznam.next.next
#         zoznam = zoznam.next
#
#
# zoz = vyrob('abcdef')
# vypis(zoz)
# vyhod_kazdy_druhy(zoz)
# vypis(zoz)
# vyhod_kazdy_druhy(zoz)
# vypis(zoz)

# uloha 15

# def pocet(zoznam: Vrchol) -> int:
#     if zoznam is None:
#         return 0
#     else:
#         return 1 + pocet(zoznam.next)
#
#
# zoz = vyrob(range(10, 20))
# print(pocet(zoz))
# print(pocet(zoz.next))
# print(pocet(None))

# uloha 16

# def sucet(zoznam: Vrchol):
#     if zoznam is None:
#         return 0
#     else:
#         if type(zoznam.data) is int or type(zoznam.data) is float:
#             return zoznam.data + sucet(zoznam.next)
#         else:
#             return sucet(zoznam.next)
#
#
# zoz = vyrob((3.14, "6.28", -1, (9, 42), None, [15.7]))
# vypis(zoz)
# print(sucet(zoz))
# print(sucet(zoz.next))
# print(sucet(None))

# uloha 17

# def spoj(zoz1: Vrchol, zoz2: Vrchol) -> Vrchol:
#     if zoz1 is None:
#         return zoz2
#
#     tmp = zoz1
#
#     while zoz1.next is not None:
#         zoz1 = zoz1.next
#
#     zoz1.next = zoz2
#
#     return tmp
#
#
# z1 = vyrob("ABC")
# z2 = vyrob("prst")
# z = spoj(z1, z2)
# vypis(z)
# vypis(spoj(None, Vrchol(1234)))

# uloha 18

def prevratena_kopia(zoznam: Vrchol) -> Vrchol:
    first = zoznam
    reversed_zoznam = None
    last = None
    reversed_next = None

    while zoznam is not None:
        if zoznam.next is None:
            last = zoznam
            reversed_zoznam = Vrchol(zoznam.data)
            reversed_next = reversed_zoznam
        zoznam = zoznam.next

    zoznam = first

    while last != first:
        while True:
            if zoznam.next == last:
                last = zoznam
                reversed_next.next = Vrchol(zoznam.data)
                reversed_next = reversed_next.next
                break
            zoznam = zoznam.next
        zoznam = first

    return reversed_zoznam


z1 = vyrob("python")
vypis(z1)
z2 = prevratena_kopia(z1)
vypis(z2)
vypis(z1)

# uloha 19

# def mapuj(funkcia, zoznam: Vrchol) -> None:
#
#     while zoznam is not None:
#         try:
#             zoznam.data = funkcia(zoznam.data)
#         except TypeError:
#             pass
#         zoznam = zoznam.next
#
#
# zoz = vyrob((1, -2, 3, -4, 5, -6))
# mapuj(abs, zoz)
# vypis(zoz)
# mapuj(lambda x: x ** 2, zoz)
# vypis(zoz)

# uloha 20

# def filtruj(podmienka, zoznam: Vrchol) -> Vrchol:
#     start = None
#     curr = None
#
#     while zoznam is not None:
#         if podmienka(zoznam.data):
#             if start is None:
#                 start = Vrchol(zoznam.data)
#                 curr = start
#             else:
#                 curr.next = Vrchol(zoznam.data)
#                 curr = curr.next
#
#         zoznam = zoznam.next
#
#     return start
#
#
# zoz = vyrob(range(5, 12))
# vypis(zoz)
# zoz = filtruj(lambda x: x % 3 == 0, zoz)
# vypis(zoz)
