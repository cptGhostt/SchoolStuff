class EmptyError(Exception):
    pass


class SpajanyZoznam:
    class Vrchol:
        def __init__(self, data, next=None):
            self.data, self.next = data, next

    def __init__(self, postupnost=None):
        self.pocitadlo = 0
        self.zac = self.kon = None
        if postupnost is not None:
            for hodnota in postupnost:
                self.append(hodnota)

    def __repr__(self):
        vysl, zoz = [], self.zac
        while zoz is not None:
            vysl.append(repr(zoz.data))
            zoz = zoz.next
        vysl.append('None')
        return ' -> '.join(vysl)

    def __len__(self):
        return self.pocitadlo

    def __contains__(self, hodnota):
        zoz = self.zac
        while zoz is not None:
            if zoz.data == hodnota:
                return True
            zoz = zoz.next
        return False

    def _ity(self, index):
        if index < 0:
            raise IndexError
        zoz = self.zac
        while zoz is not None and index > 0:
            zoz = zoz.next
            index -= 1
        if zoz is None:
            raise IndexError
        return zoz

    def __getitem__(self, index):
        return self._ity(index).data

    def __setitem__(self, index, hodnota):
        self._ity(index).data = hodnota

    def __delitem__(self, index):
        self._ity(index - 1).next = self._ity(index).next

    def __add__(self, druhy):
        to_ret = SpajanyZoznam()
        zoz1 = self.zac
        zoz2 = druhy.zac

        while zoz1 is not None:
            to_ret.append(zoz1.data)
            zoz1 = zoz1.next
        while zoz2 is not None:
            to_ret.append(zoz2.data)
            zoz2 = zoz2.next

        return to_ret


    def insert0(self, hodnota):
        self.pocitadlo += 1
        self.zac = self.Vrchol(hodnota, self.zac)
        if self.kon is None:
            self.kon = self.zac

    def append(self, hodnota):
        if self.zac is None:
            self.kon = self.zac = self.Vrchol(hodnota)
            self.pocitadlo += 1
        else:
            self.kon.next = self.Vrchol(hodnota)
            self.kon = self.kon.next
            self.pocitadlo += 1

    def pop0(self):
        if self.zac is None:
            raise EmptyError
        self.pocitadlo -= 1
        vysl = self.zac.data
        self.zac = self.zac.next
        if self.zac is None:
            self.kon = None
        return vysl

    def pop(self):
        if self.zac is None:
            raise EmptyError
        self.pocitadlo -= 1
        if self.zac.next is None:
            vysl = self.zac.data
            self.zac = self.kon = None
            return vysl
        self.kon = self.zac
        while self.kon.next.next is not None:
            self.kon = self.kon.next
        vysl = self.kon.next.data
        self.kon.next = None
        return vysl

    def copy(self):
        zoz = self.zac
        to_ret = SpajanyZoznam()

        while zoz is not None:
            to_ret.append(zoz.data)
            zoz = zoz.next

        return to_ret

    def reversed(self):
        to_ret = SpajanyZoznam()
        zoz = self.zac
        last = self.kon

        for i in range(len(self) - 1):
            while zoz.next != last:
                zoz = zoz.next

            to_ret.append(zoz.next.data)
            last = zoz
            zoz = self.zac

        to_ret.append(self.zac.data)
        return to_ret

    def filter(self, podmienka):
        to_ret = SpajanyZoznam()
        zoz = self.zac

        while zoz is not None:
            if podmienka(zoz.data):
                to_ret.append(zoz.data)
            zoz = zoz.next

        return to_ret

    def map(self, funkcia):
        to_ret = SpajanyZoznam()
        zoz = self.zac

        while zoz is not None:
            to_ret.append(funkcia(zoz.data))
            zoz = zoz.next

        return to_ret

    def enumerate(self):
        to_ret = SpajanyZoznam()
        zoz = self.zac
        poc = 0

        while zoz is not None:
            to_ret.append((poc, zoz.data))
            poc += 1
            zoz = zoz.next

        return to_ret

    def opakuje_sa(self):
        zoz = self.zac

        while zoz is not None:
            tmp = zoz.next
            val = zoz.data
            while tmp is not None:
                if tmp.data == val:
                    return val
                tmp = tmp.next
            zoz = zoz.next

        return None


class Paska:
    def __init__(self, obsah=''):
        self.paska = list(obsah or '_')
        self.poz = 0

    def symbol(self):
        return self.paska[self.poz]

    def zmen_symbol(self, znak):
        self.paska[self.poz] = znak

    def __str__(self):
        return ''.join(self.paska) + '\n' + ' '*self.poz + '^'

    def vpravo(self):
        self.poz += 1
        if self.poz == len(self.paska):
            self.paska.append('_')

    def vlavo(self):
        if self.poz > 0:
            self.poz -= 1
        else:
            self.paska.insert(0, '_')

    def text(self):
        return ''.join(self.paska).strip('_')

    symbol = property(symbol, zmen_symbol)
    text = property(text)


class Turing:
    def __init__(self, program, obsah='', start=None, koniec={'end', 'stop'}):
        self.program = {}
        self.stav = start
        for riadok in program.split('\n'):
            riadok = riadok.split()
            if len(riadok) == 5:
                stav1, znak1, znak2, smer, stav2 = riadok
                self.program[stav1, znak1] = znak2, smer, stav2
                if self.stav is None:
                    self.stav = stav1
        self.paska = Paska(obsah)
        self.koniec = koniec

    def __str__(self):
        return str(self.paska) + ' ' + self.stav

    def krok(self):
        stav1, znak1 = self.stav, self.paska.symbol
        try:
            znak2, smer, stav2 = self.program[stav1, znak1]
        except KeyError:
            return False
        self.paska.symbol = znak2
        self.stav = stav2
        if smer == '>':
            self.paska.vpravo()
        elif smer == '<':
            self.paska.vlavo()
        return True

    def rob(self, vypis=True):
        if vypis:
            print(self)
        while self.stav not in self.koniec:
            if not self.krok():
                return False
            if vypis:
                print(self)
        return True


# uloha 1*

# z = SpajanyZoznam(range(1000))
# for i in range(495):
#     z.pop(); z.pop0()
# for i in range(5):
#     z.append(i); z.insert0(i)
# print(len(z))
#
# z = SpajanyZoznam()
# pocet = 0
# for i in range(30000):
#     z.insert0(i)
#     pocet += len(z)
# print(pocet)

# TODO uloha 2

# TODO uloha 3

# TODO uloha 4

# uloha 5*

# z = SpajanyZoznam("Python")
# print(z)
# z1 = z.copy()
# print(z1)
# z2 = z.reversed()
# print(z2)
# z3 = z.filter(lambda x: x in "aeiouy")
# print(z3)
# z4 = z.map(lambda x: x.upper() + "!")
# print(z4)
# z5 = z.enumerate()
# print(z5)
# print(z)

# uloha 6*

# a = SpajanyZoznam((*range(100), *range(90, 200)))
# print(a.opakuje_sa())
# b = SpajanyZoznam('mama ma emu a ema Ma mamu'.split())
# print(b.opakuje_sa())
# c = SpajanyZoznam(range(10))
# print(c.opakuje_sa())
# d = SpajanyZoznam((*range(10), 9))
# print(d.opakuje_sa())

# TODO uloha 7

# uloha 8*

# import time
#
# zoz1 = SpajanyZoznam(range(10000))
# start = time.time()
# z = zoz1.zac
# while z is not None:
#     # tu prejem celý zoznam iba raz
#     z.data += 1
#     z = z.next
# finalny = time.time() - start
# print('čas1 =', finalny)
#
# zoz2 = SpajanyZoznam(range(10000))
# start = time.time()
# for i in range(len(zoz2)):
#     # tu každou iteráciou for cyklu, prechádzam zoznam odznova, a to dokonca dvakrát
#     # obe metódy, __getitem__ aj __setitem__, zakaždým prechádzajú zoznamom pomocou while cyklu
#     zoz2[i] = zoz2[i] + 1
# finalny = time.time() - start
# print('čas2 =', finalny)
#
# start = time.time()
# # zakaždým keď idem pridať prvok do listu, musím prejsť zoznam pomocou metódy __getitem__
# list1 = list(SpajanyZoznam(range(10000)))
# finalny = time.time() - start
# print('list1 hotovo', finalny)
#
# start = time.time()
# # do listu sa prvky pridávajú priamo počas toho ako sa prechádza cez zoznam vo while cykle nižšie
# zoz = SpajanyZoznam(range(10000))
# list2 = []
# z = zoz.zac
# while z:
#     list2.append(z.data)
#     z = z.next
# finalny = time.time() - start
# print('list2 hotovo', finalny)
# print(list1 == list2)

# uloha 9*

# z = SpajanyZoznam(range(3, 22, 4))
# print(z)
# del z[2]
# print(z)

# TODO uloha 10

# uloha 11*

# z1 = SpajanyZoznam('abc')
# z2 = SpajanyZoznam(range(2, 10, 2))
# z3 = z1 + z2
# print(z3)
# print(z1)
# print(z2)
# print(z2 + z1)

# TODO uloha 12

# TODO uloha 13

# uloha 14*

# for retazec in 'abcb', 'ccccca', 'cba'*10, 'cbxcba', 'aabbccAABBCC':
#     t = Turing('''
#     0 a a > 0
#     0 b b > 0
#     0 c c > 0
#     0 _ _ = end
#     ''', retazec)
#     print(retazec, t.rob(False))

# TODO uloha 15

# TODO uloha 16

# uloha 17*

# for pocet in 10, 9, 8, 7:
#     t = Turing(f'''
#     0 e e > 1
#     1 e e > 2
#     2 e e > 0
#     0 _ 0 = end
#     1 _ 1 = end
#     2 _ 2 = end
#     ''', 'e' * pocet)
#     print(t.rob(False), t.paska.text)

# uloha 18*

# cislo = 2**20 - 1
# retazec = f'{cislo:b}'
# t = Turing('''
# s1 0 0 > s1
# s1 1 1 > s1
# s1 _ _ < s2
#
# s2 1 0 < s2
# s2 0 1 = end
# s2 _ 1 = end
# ''', retazec) #zavolaj Turingov stroj s daným reťazcom
# t.rob(False)
# vysledok = t.paska.text
# print(cislo, retazec, vysledok, int(vysledok, 2))

# uloha 19*

# cislo = 16
# retazec = f'{cislo:b}'
# tu = Turing('''
# s1 0 0 > s1
# s1 1 1 > s1
# s1 _ _ < s2
#
# s2 0 1 < s2
# s2 1 0 = s3
#
# s3 0 0 < s3
# s3 1 1 < s3
# s3 _ _ > s4
#
# s4 1 1 = end
# s4 0 _ > s4
# s4 _ _ = s5
#
# s5 _ 0 = end
# ''', retazec)
# tu.rob(False)
# vysledok = tu.paska.text
# print(cislo, retazec, vysledok, int(vysledok, 2))

# uloha 20*

t = Turing('''
s0 1 0 > s0
s0 _ _ < s1
s1 1 1 < s1
s1 0 1 > s2
s1 _ _ = end
s2 1 1 > s2
s2 _ _ > s3
s3 1 1 > s3
s3 _ 1 < s4
s4 1 1 < s4
s4 _ _ < s1
''', '1111')
print(t.rob(False))
print(t.paska.text)

# TODO uloha 21

# ulohy 22* a 23*

# def bajty(cislo: int) -> list:
#     to_ret = []
#
#     while cislo != 0:
#         to_ret.insert(0, cislo % 256)
#         cislo //= 256
#
#     return to_ret
#
#
# print(bajty(100))
# print(bajty(1000))
# print(bajty(10000))
# print(bajty(2**16 - 1))
# print(bajty(3**33))
#
#
# def do_hex(post: list) -> None:
#     tmp = []
#     for i in post:
#         a = str(hex(i))[2:]
#         if len(a) == 1:
#             a = "0" + a
#         tmp.append(a)
#
#     to_print = " ".join(tmp)
#     print(to_print)
#
#
# do_hex(bajty(1000))
# print(f"{1000:04x}")
# do_hex(bajty(3 ** 33))
# print(f"{3 ** 33:x}")
