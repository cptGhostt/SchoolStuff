# uloha 1

# zoo = {}
#
# with open("zvierata.txt", "r", encoding="utf8") as f:
#     for i in f:
#         tmp = i.split()
#         zoo[tmp[0]] = int(tmp[1])
#
# print(sorted(zoo.items()))
#
# priemer = 0
# for i in zoo:
#     priemer += zoo[i]
# print(priemer / len(zoo))
#
# def najtazsie():
#     zver = ""
#     vaha = 0
#
#     for i in zoo:
#         if zoo[i] > vaha:
#             zver = i
#             vaha = zoo[i]
#
#     return zver, vaha
#
#
# def tazsie_ako(zviera):
#     vaha = zoo[zviera]
#
#     for i in zoo:
#         if zoo[i] > vaha:
#             print(i)
#
#
# def vyber_lahsie(zviera):
#     to_ret = {}
#     vaha = zoo[zviera]
#
#     for i in zoo:
#         if vaha > zoo[i]:
#             to_ret[i] = zoo[i]
#
#     return to_ret
#
#
# print(najtazsie())
# tazsie_ako('zirafa')
# print(vyber_lahsie("jazvec"))

# uloha 2

# skladatel = {}
#
# with open("skladatelia.txt", "r", encoding="utf8") as f:
#     for i in f:
#         tmp = i.split()
#         skladatel[tmp[0]] = int(tmp[1])
#
#
# def najstarsi():
#     rok = float("inf")
#     comp = ""
#     for i in skladatel:
#         if skladatel[i] < rok:
#             comp = i
#             rok = skladatel[i]
#
#     print(f"najstarsi: {comp} {rok}")
#
#
# def najmladsi():
#     rok = 0
#     comp = ""
#     for i in skladatel:
#         if skladatel[i] > rok:
#             comp = i
#             rok = skladatel[i]
#
#     print(f"najmladsi: {comp} {rok}")
#
#
# def medzi(rok1, rok2):
#     to_ret = []
#
#     for i in skladatel:
#         if rok1 <= skladatel[i] <= rok2:
#             to_ret.append(i)
#
#     return to_ret
#
#
# najstarsi()
# najmladsi()
# print(medzi(1720, 1730))
# print(medzi(1820, 1830))

# uloha 3

# skladatel = {}
# cs = {}
#
# with open("skladatelia.txt", "r", encoding="utf8") as f:
#     for i in f:
#         tmp = i.split()
#         skladatel[tmp[0]] = int(tmp[1])
#
# with open("cs.txt", "r", encoding="utf8") as f:
#     for i in f:
#         tmp = i.split()
#         cs[tmp[0] + " " + tmp[1]] = int(tmp[2])
#
#
# def otoc(slovnik):
#     to_ret = {}
#
#     for i in slovnik:
#         if slovnik[i] in to_ret:
#             to_ret[slovnik[i]].add(i)
#         else:
#             to_ret[slovnik[i]] = {i}
#
#     return to_ret
#
#
# print(otoc(skladatel))
# rok = otoc(skladatel)
# for i in sorted(rok.items()):
#     print(i)
#
# for i in rok:
#     if len(rok[i]) > 1:
#         print(i)
#
# print(cs)
# print(otoc(cs))

# uloha 4

# slova = {}
# with open("twain.txt", "r", encoding="utf8") as f:
#     tmp = f.read().split()
#
#     for i in tmp:
#         if len(i) in slova:
#             slova[len(i)].add(i)
#         else:
#             slova[len(i)] = {i}
#
# najviac = 0
# najcastejsie = 0
# for i in slova:
#     if len(slova[i]) > najviac:
#         najviac = len(slova[i])
#         najcastejsie = i
#
# print(f"najcastejsia dlzka je {najcastejsie}\nslov dlzky {najcastejsie} je {najviac}")
# print(f"mnozina slov dlzky {najcastejsie}: {slova[najcastejsie]}")
#
# print(f"najdlhsie slova: {slova[sorted(slova)[len(slova) - 1]]}")

# uloha 5

# def dvojice(meno_suboru):
#     to_ret = {}
#
#     with open(meno_suboru, "r", encoding="utf8") as f:
#         tmp = f.read()
#         tmp = tmp.replace("\n", "")
#         tmp = tmp.replace(" ", "")
#
#     for i in range(1, len(tmp)):
#         a = tmp[i-1] + tmp[i]
#         if a in to_ret:
#             to_ret[a] += 1
#         else:
#             to_ret[a] = 1
#
#     return to_ret
#
#
# print(dvojice("twain.txt"))

# uloha 6

# from random import randint
#
#
# def dve_kocky(n):
#     to_ret = {}
#     for i in range(n):
#         a = randint(1, 6) + randint(1, 6)
#         if a in to_ret:
#             to_ret[a] += 1
#         else:
#             to_ret[a] = 1
#
#     return to_ret
#
#
# print(dve_kocky(10))
# print(dve_kocky(100))

# uloha 7

# def fib(n):
#     if n == 0:
#         return {0: 0}
#     elif n == 1:
#         return {0: 0, 1: 1}
#
#     to_ret = {0: 0, 1: 1}
#
#     for i in range(2, n+1):
#         to_ret[i] = to_ret[i-1] + to_ret[i-2]
#
#     return to_ret
#
#
# print(fib(10))

# uloha 8

# def zasifruj(sifra, text):
#     to_ret = ""
#
#     for i in text:
#         if i in sifra:
#             to_ret += sifra[i]
#         else:
#             to_ret += i
#
#     return to_ret
#
#
# def rozsifruj(sifra, text):
#     to_ret = ""
#
#     for i in text:
#         if i in sifra:
#             for j in sifra:
#                 if sifra[j] == i:
#                     to_ret += j
#                     break
#         else:
#             to_ret += i
#
#     return to_ret
#
#
# sifra = {'a': 'c', 'b': 'd', 'c': 'e', "d": "f",
#          "e": "g", "f": "h", "g": "i", "h": "j",
#          "i": "k", "j": "l", "k": "m", "l": "n",
#          "m": "o", "n": "p", "o": "q", "p": "r",
#          "q": "s", "r": "t", "s": "u", "t": "v",
#          "u": "w", "v": "x", "w": "y", "x": "z",
#          "y": "a", "z": "b"}
#
# print(zasifruj(sifra, 'programovanie v pythone je cool'))
# print(rozsifruj(sifra, "rtqitcoqxcpkg x ravjqpg lg eqqn"))

# uloha 9

# def pretypuj(nazov, hodnota):
#     types = {"int": int, "float": float, "list": list, "tuple": tuple,
#              "str": str, "set": set, "dict": dict}
#
#     return types[nazov](hodnota)
#
#
# print(pretypuj('str', 3.14))
# print(pretypuj('set', 'Python'))
# print(pretypuj('float', '1e5'))
# print(pretypuj('dict', [(1, 'a'), (2, 'b')]))
# print(pretypuj('novy', 123))

# uloha 10

# import json
#
#
# def fib(n):
#     if n == 0:
#         return {0: 0}
#     elif n == 1:
#         return {0: 0, 1: 1}
#
#     to_ret = {0: 0, 1: 1}
#
#     for i in range(2, n+1):
#         to_ret[i] = to_ret[i-1] + to_ret[i-2]
#
#     return to_ret
#
#
# f = fib(40)
#
# with open("subor.txt", "w", encoding="utf8") as file:
#     json.dump(f, file, indent=2)
#
# ff = json.load(open("subor.txt"))
#
# print(f)    # kluce su ako int
# print(ff)   # kluce su ako str

# uloha 11

from random import randrange
import time


def rozhadz(post):
    tmp = list(post)
    to_ret = []

    while len(tmp) > 0:
        to_ret.append(tmp.pop(randrange(0, len(tmp))))

    return to_ret


def test(n):
    a = time.time()
    rozhadz(range(n))
    a = round(time.time()-a, 3)
    return a


print(rozhadz('abcdefghujkl'))
print(rozhadz(range(10, 30)))

print(test(1000))
print(test(10000))
print(test(100000))
