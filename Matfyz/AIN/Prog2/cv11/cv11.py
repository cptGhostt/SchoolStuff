# uloha 1*

# def vypis_rastuce(n: int) -> None:
#     def rek(j, s):
#         if len(s) == n:
#             print(*s, sep=" ")
#             return
#
#         for i in range(j, n):
#             rek(i, s+str(i))
#     rek(0, "")
#
#
# vypis_rastuce(2)
# print()
# vypis_rastuce(3)

# uloha 2*

# def vsetky(mnozina: set) -> None:
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             print(s)
#             return
#         for i in mnozina:
#             rek(s+i)
#     rek("")
#
#
# vsetky({"x", "y"})

# uloha 3*

# def vsetky_len_raz(mnozina: set) -> None:
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             print(s)
#             return
#         for i in mnozina:
#             if i not in s:
#                 rek(s+i)
#     rek("")
#
#
# vsetky_len_raz({'a', 'k', 'm'})

# uloha 4*

# def vsetky_mnozina(mnozina: set) -> set:
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             to_ret.add(s)
#             return
#         for i in mnozina:
#             rek(s+i)
#
#     to_ret = set()
#     rek("")
#     return to_ret
#
#
# def vsetky_len_raz_mnozina(mnozina: set) -> set:
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             to_ret.add(s)
#             return
#         for i in mnozina:
#             if i not in s:
#                 rek(s+i)
#
#     to_ret = set()
#     rek("")
#     return to_ret
#
#
# def vsetky_generator(mnozina: set):
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             to_ret.add(s)
#             return
#         for i in mnozina:
#             rek(s+i)
#
#     to_ret = set()
#     rek("")
#     yield from to_ret
#
#
# def vsetky_len_raz_generator(mnozina: set) -> set:
#     def rek(s: str) -> None:
#         if len(s) == len(mnozina):
#             to_ret.add(s)
#             return
#         for i in mnozina:
#             if i not in s:
#                 rek(s+i)
#
#     to_ret = set()
#     rek("")
#     yield from to_ret
#
#
# print(vsetky_mnozina({'x', 'y'}))
# print(vsetky_len_raz_mnozina(set('akm')))
# print(*vsetky_generator({'x', 'y'}))
# print(*vsetky_len_raz_generator(set('akm')))

# uloha 5*

# class Damy:
#     def __init__(self, n):
#         self.n = n
#         self.riesenie = [None] * n
#
#     def moze(self, i, j):         # či môže položiť dámu na pozíciu (i,j)
#         return (j not in self.stlpec and
#                 i + j not in self.u1 and
#                 i - j not in self.u2)
#
#     def vypis(self):
#         for k in range(self.n):
#             r = ['.'] * self.n
#             r[self.riesenie[k]] = 'o'
#             print(' '.join(r))
#         print('=' * 2 * self.n)
#
#     def hladaj(self, i):
#         for j in range(self.n):
#             if self.moze(i, j):
#                 # zaznač položenie dámy
#                 self.riesenie[i] = j
#                 self.stlpec.add(j)
#                 self.u1.add(i+j)
#                 self.u2.add(i-j)
#                 if i == self.n-1:
#                     if self.pocet < 3:
#                         self.vypis()
#                     self.pocet += 1
#                 else:
#                     self.hladaj(i+1)
#                 # odznač položenie dámy
#                 self.riesenie[i] = None
#                 self.stlpec.remove(j)
#                 self.u1.remove(i+j)
#                 self.u2.remove(i-j)
#
#     def ries(self):
#         self.stlpec = set()
#         self.u1 = set()
#         self.u2 = set()
#         self.pocet = 0
#         self.hladaj(0)
#         print('pocet rieseni:', self.pocet)
#         if self.pocet == 0:
#             print('ziadne riesenie')
#
#
# Damy(8).ries()

# uloha 7*

# class Uloha:
#     def __init__(self, meno_suboru, limit=3):
#         self.ziaci = {}
#         self.kruzky = {}
#         tmp = set()
#         self.limit = limit
#         self.pocet = 0
#
#         with open(meno_suboru, 'r', encoding="utf8") as f:
#             line = f.readline()
#             while line:
#                 line = line.split()
#                 self.ziaci[line[0]] = set(line[1:])
#                 for i in line[1:]:
#                     tmp.add(i)
#                 line = f.readline()
#
#         for i in tmp:
#             self.kruzky[i] = set()
#
#     def najdi(self):
#         self.pocet = 0
#
#         def rek(zoz):
#             if self.pocet:
#                 return
#
#             if not zoz:
#                 self.pocet += 1
#                 for i in self.kruzky:
#                     print(f"{i}: ", end="")
#                     print(*self.kruzky[i], sep=" ")
#                 print()
#                 return
#
#             for i in self.ziaci[zoz[0]]:
#                 if len(self.kruzky[i]) < self.limit:
#                     self.kruzky[i].add(zoz[0])
#                     tmp = zoz[1:]
#                     rek(tmp)
#                     self.kruzky[i].remove(zoz[0])
#
#         rek(list(self.ziaci.keys()))
#
#
# u = Uloha('ziaci.txt')
# u.najdi()

# uloha 8*


class Domcek:
    def __init__(self):
        # self.g = [{1, 2, 3}, {0, 2, 3}, {0, 1, 3, 4}, {0, 1, 2, 4}, {2, 3}]

        self.g = [{1, 2, 3},            # 0
                  {0, 2, 3, 5},         # 1
                  {0, 1, 3, 4, 5},      # 2
                  {0, 1, 2, 4},         # 3
                  {2, 3},               # 4
                  {1, 2}]               # 5

    def hladaj(self):
        v1 = self.riesenie[-1]
        for v2 in sorted(self.g[v1]):
            # zaznac tah
            self.riesenie.append(v2)
            self.g[v1].remove(v2)
            self.g[v2].remove(v1)
            if len(self.riesenie) == 11:  # zišlo by sa prepočítať
                print(*self.riesenie)
                self.pocet += 1
            else:
                self.hladaj()
            # odznac tah
            self.riesenie.pop()
            self.g[v1].add(v2)
            self.g[v2].add(v1)

    def ries(self):
        self.pocet = 0
        for i in range(len(self.g)):  # postupne vyskúša pre všetky vrcholy
            self.riesenie = [i]
            self.hladaj()
        print('pocet rieseni:', self.pocet)


Domcek().ries()

# uloha 11*


# class Uloha:
#     def __init__(self, s):
#         self.tab = [list(r) for r in s.split()]
#
#     def pocet(self):
#         self.to_ret = 0
#
#         def backtracking(r, s):
#             if 0 <= r < len(self.tab) and 0 <= s < len(self.tab[r]):
#                 if self.tab[r][s] == 'x':
#                     # yield '\n'.join(' '.join(r) for r in self.tab)
#                     self.to_ret += 1
#                 elif self.tab[r][s] == '.':
#                     self.tab[r][s] = '-'
#                     # yield from backtracking(r, s + 1)
#                     backtracking(r, s + 1)
#                     self.tab[r][s] = '|'
#                     # yield from backtracking(r + 1, s)
#                     backtracking(r + 1, s)
#                     self.tab[r][s] = '\\'  # '\\' označuje jeden znak \
#                     # yield from backtracking(r + 1, s + 1)
#                     backtracking(r + 1, s + 1)
#                     self.tab[r][s] = '.'
#
#         backtracking(0, 0)
#         return self.to_ret
#
#
# print(Uloha('... ..x').pocet())
# print(Uloha('... .m. ..x').pocet())
# print(Uloha('...m ..m. .m.. m..x').pocet())
