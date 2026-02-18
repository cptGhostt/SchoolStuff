# uloha 1*

# class Fib:
#     def __init__(self, n):
#         self.curr = 0
#         self.n = n
#         self.a = 0
#         self.b = 1
#
#     def __iter__(self):
#         return self
#
#     def __next__(self):
#         if self.curr == self.n:
#             raise StopIteration
#         self.curr += 1
#         tmp = self.a
#         self.a, self.b = self.b, self.a + self.b
#         return tmp
#
#
# for f in Fib(100):
#     print(f, end=' ')
#     if f > 20:
#         break

# uloha 2*

# class Sucty:
#     def __init__(self):
#         pass
#
#     def __getitem__(self, ix):
#         return sum(range(ix+2))
#
#
# sucty = iter(Sucty())
# for i in range(6):
#     print(next(sucty), end=' ')

# uloha 3*

# def test(m1, m2):
#     for i in m1:
#         for j in m2:
#             print(i, j, i+j)
#
#
# def test1(m1, m2):
#     i1 = iter(m1)
#     while True:
#         i2 = iter(m2)
#         try:
#             a = next(i1)
#             while True:
#                 try:
#                     b = next(i2)
#                     print(a, b, a+b)
#                 except StopIteration:
#                     break
#         except StopIteration:
#             break
#
#
# test({'a', 'b'}, {'x', 'y', 'z'})
# print()
# test1({'a', 'b'}, {'x', 'y', 'z'})

# uloha 5*

# def grange(start, stop, krok):
#     while start < stop:
#         yield start
#         start += krok
#
#
# print(tuple(grange(3, 50, 7)))
# print(tuple(grange(1, 5, 0.5)))

# uloha 6*

# def mocniny1(n):
#     to_ret = []
#     for i in range(1, n+1):
#         to_ret.append(i**2)
#     return to_ret
#
#
# def mocniny2(n):
#     return [i**2 for i in range(1, n+1)]
#
#
# def mocniny3(n):
#     def gmocniny(m):
#         for i in range(1, m+1):
#             yield i**2
#     return gmocniny(n)
#
#
# def mocniny4(n):
#     return (i**2 for i in range(1, n+1))
#
#
# print(mocniny1(5))
# print(mocniny2(5))
# print(mocniny3(5))
# print(mocniny4(5))

# uloha 9*

# def zdvoj(gen):
#     it = iter(gen)
#
#     while True:
#         try:
#             a = next(it)
#             yield a
#             yield a
#         except StopIteration:
#             break
#
#
# g = zdvoj(i**2 for i in range(1, 5))
# print(g)
# print(list(g))
# print("".join(zdvoj("Python")))
# print(list(zdvoj([2, 3, 5])))

# uloha 10*

# def spoj1(gen1, gen2):
#     it1 = iter(gen1)
#     it2 = iter(gen2)
#
#     while True:
#         try:
#             a = next(it1)
#             yield a
#         except StopIteration:
#             break
#
#     while True:
#         try:
#             a = next(it2)
#             yield a
#         except StopIteration:
#             break
#
#
# def spoj2(*gen):
#     for i in gen:
#         it = iter(i)
#         while True:
#             try:
#                 a = next(it)
#                 yield a
#             except StopIteration:
#                 break
#
#
# g = spoj1(iter(range(5)), iter(range(10, 0, -2)))
# print(g)
# print(*g)
#
# g = spoj2(iter(range(5)), iter('ahoj'), iter(range(10, 0, -2)))
# print(g)
# print(*g)

# uloha 11*

# def mix1(gen1, gen2):
#     tmp = list(gen1)
#     it = iter(gen2)
#
#     while True:
#         try:
#             try:
#                 yield tmp.pop(0)
#             except IndexError:
#                 pass
#             yield next(it)
#         except StopIteration:
#             break
#
#     while True:
#         try:
#             yield tmp.pop(0)
#         except IndexError:
#             break
#
# def mix2(gen1, gen2):
#     it1 = iter(gen1)
#     it2 = iter(gen2)
#
#     while True:
#         try:
#             try:
#                 yield next(it1)
#             except StopIteration:
#                 pass
#             yield next(it2)
#         except StopIteration:
#             break
#
#     while True:
#         try:
#             yield next(it1)
#         except StopIteration:
#             break
#
#
# def mix3(*gen):
#     iterators = []
#     for i in gen:
#         iterators.append(iter(i))
#
#     while True:
#         shutdown = True
#         for i in range(len(iterators)):
#             try:
#                 yield next(iterators[i])
#                 shutdown = False
#             except StopIteration:
#                 continue
#
#         if shutdown:
#             break
#
#
# print(*mix1(iter('PYTHON'), iter("ahoj")))
# print(*mix1(iter("ahoj"), iter('PYTHON')))
# print()
# print(*mix2(iter('PYTHON'), iter("ahoj")))
# print(*mix2(iter("ahoj"), iter('PYTHON')))
# print()
# print(*mix3(iter('PYTHON'), iter(range(4)), iter('ahoj')))

# uloha 12*

from random import randrange


def vyrob(meno_suboru, n, pocet):
    with open(meno_suboru, "wb") as f:
        for i in range(pocet):
            tmp = randrange(0, (256**n) + 1, 100)
            f.write(tmp.to_bytes(n, "big"))


def citaj(meno_suboru, n):
    with open(meno_suboru, "rb") as f:
        to_ret = []
        bajty = f.read(n)

        while bajty != b"":
            to_ret.append(int.from_bytes(bajty))
            bajty = f.read(n)

        return to_ret


vyrob("subor.dat", 3, 10)
print(citaj("subor.dat", 3))

# uloha 14*

# def pocet_bajtov(x:int) -> int:
#     bajty = 0
#
#     while x != 0:
#         bajty += 1
#         x //= 256
#
#     if bajty == 0:
#         return 1
#     return bajty
#
#
# print(pocet_bajtov(0))
# print(pocet_bajtov(200))
# print(pocet_bajtov(2000))
