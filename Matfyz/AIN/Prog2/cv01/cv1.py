from struktury import *

# uloha 1

# s = Stack()
# print(s.push(8))
# s.push(9)
# s.push(10)
# print(s.pop())
# s.push(7)
# s.push(6)
# print(s.pop())
# print(s.pop())
# s.push(2)
# s.push(3)
# print(s.pop())
# print(s.pop())
# print(s.pop())
# print(s.pop())

# uloha 2

# s = Stack()
# for i in 7, 2, 0, 4:
#     s.push(i)
#     s.push(i + 1)
# while not s.is_empty():
#     print(s.pop(), end=' ')

# uloha 3

# print(Stack(range(5)))
# print(Stack("Python"))
# print(Stack([123]))

# uloha 4


# def pocet_cisel(stack:Stack):
#     count = 0
#     while not stack.is_empty():
#         a = stack.pop()
#         if type(a) is int or type(a) is float:
#             count += 1
#     return count
#
#
# s = Stack((5, "7", 3.14, [8]))
# print(pocet_cisel(s))
# print(s.is_empty())

# uloha 5


# def druhy(stack:Stack):
#     mem = []
#
#     while not stack.is_empty():
#         mem.append(stack.pop())
#
#     if len(mem) <= 1:
#         for i in reversed(mem):
#             stack.push(i)
#         raise EmptyError()
#
#     to_ret = mem[-2]
#     mem.pop(-2)
#
#     for i in reversed(mem):
#         stack.push(i)
#
#     return to_ret
#
#
# z = Stack("python")
# print(druhy(z))
# print(z)
#
# s = Stack(["python"])
# print(druhy(s))
# print(s)

# uloha 6

# def prevrat(stack:Stack):
#     mem = []
#
#     while not stack.is_empty():
#         mem.append(stack.pop())
#
#     for i in mem:
#         stack.push(i)
#
#
# s = Stack(range(5))
# print(s)
# prevrat(s)
# print(s)

# uloha 7

# print(2 * (2 + 1) * (2 + 1 + 1) * (2 + 1 + 1 + 1))
# print(postfix("2 2 1 + * 2 1 + 1 + * 2 1 + 1 + 1 + *"))
# print(prefix("* * * + 2 1 2 + + 2 1 1 + + + 2 1 1 1"))
#
# # x % 10 * 100 + x // 10 % 10 * 10 + x // 100
# # x 10 % 100 * x 10 // 10 % 10 * x 180 // + +   --> postfix
# # + + * % x 10 100 * % // x 10 10 10 // x 100   --> prefix
#
# print(5 * 'a' + 'b' * 4)
# # "b" 4 * 5 "a" * +     --> postfix
# # + * "b" 4 * 5 "a"     --> prefix
#
#
# print(5 * ('a' + 'b') * 4)
# # "a" "b" + 5 * 4 *    --> postfix
# # * * 5 4 + "a" "b"    --> prefix

# uloha 8

print(prefix("+ 8 * / - 14 6 3 - 8 * 2 3"))  # (14 - 6) // 3 - (2 * 3 - 8) + 8
print(postfix("14 6 - 3 / 2 3 * 8 - - 8 +"))

print(postfix("1 2 3 * + 4 5 * + 6 7 * +"))  # (2 * 3 + 1) + 4 * 5 + 6 * 7
print(prefix("+ + + * 2 3 1 * 4 5 * 6 7"))

# uloha 9

# def test(n):
#     if n > 0:
#         test(n - 2)
#         print(n, end='')
#         test(n - 1)
#         print(n, end='')
#
#
# test(1)
# print()
# test(2)
# print()
# test(3)
# print()
# test(4)

# uloha 10

# def test(n):
#
#     if n > 0:
#         test(n - 2)
#
#         print(n, end='')
#         test(n - 1)
#
#         print(n, end='')
#
#
# def test_nerek(n):
#     tmp = Stack()
#     tmp.push((1, n))
#
#     while not tmp.is_empty():
#         adresa, n = tmp.pop()
#
#         if n > 0:
#             if adresa == 1:
#                 # test(n - 2)
#                 tmp.push((2, n))
#                 tmp.push((1, n-2))
#             elif adresa == 2:
#                 print(n, end='')
#                 # test(n - 1)
#                 tmp.push((3, n))
#                 tmp.push((1, n - 1))
#             elif adresa == 3:
#                 print(n, end='')
#
#
# test(5)
# print()
# test_nerek(5)

# uloha 11

# import turtle
#
#
# def strom(n):
#     tmp = Stack()
#     tmp.push((1, n))
#
#     # t.fd(5 * n)
#     # if n > 3:
#     #     t.lt(40)
#     #     strom(n - 1)
#     #     t.rt(75)
#     #     strom(n - 1)
#     #     t.lt(35)
#     # t.bk(5 * n)
#
#     while not tmp.is_empty():
#         adresa, n = tmp.pop()
#
#         if adresa == 1:
#             t.fd(5 * n)
#             if n > 3:
#                 t.lt(40)
#                 # strom(n - 1)
#                 tmp.push((2, n))
#                 tmp.push((1, n-1))
#         elif adresa == 2:
#             t.rt(75)
#             # strom(n - 1)
#             tmp.push((3, n))
#             tmp.push((1, n - 1))
#         elif adresa == 3:
#             t.lt(35)
#         if adresa == 3 or n <= 3:
#             t.bk(5 * n)
#
#
# t = turtle.Turtle()
# t.speed(0)
# t.lt(90)
# strom(8)
# turtle.mainloop()

# uloha 12

# import turtle
#
#
# def ckrivka(n, s):
#     st = Stack()
#     st.push((1, n))
#
#     # if n == 0:
#     #     t.fd(s)
#     # else:
#     #     ckrivka(n - 1, s)
#     #     t.lt(90)
#     #     ckrivka(n - 1, s)
#     #     t.rt(90)
#
#     while not st.is_empty():
#         adresa, n = st.pop()
#
#         if adresa == 1:
#             if n == 0:
#                 t.fd(s)
#             else:
#                 # ckrivka(n - 1, s)
#                 st.push((2, n))
#                 st.push((1, n - 1))
#         elif adresa == 2:
#             t.lt(90)
#             # ckrivka(n - 1, s)
#             st.push((3, n))
#             st.push((1, n - 1))
#         elif adresa == 3:
#             t.rt(90)
#
#
# t = turtle.Turtle()
# t.speed(0)
# ckrivka(6, 20)
# turtle.mainloop()

# uloha 13

# def push_dno(stack: Stack, hodnota) -> None:
#     tmp = Stack()
#
#     while not stack.is_empty():
#         tmp.push(stack.pop())
#
#     stack.push(hodnota)
#
#     while not tmp.is_empty():
#         stack.push(tmp.pop())
#
#
# def inc(stack: Stack) -> None:
#     tmp = Stack()
#
#     while not stack.is_empty():
#         tmp.push(stack.pop())
#
#     while not tmp.is_empty():
#         a = tmp.pop()
#         try:
#             stack.push(a + 1)
#         except TypeError:
#             stack.push(a)
#
#
# def nechaj(stack: Stack, podmienka) -> None:
#     tmp = Stack()
#
#     while not stack.is_empty():
#         tmp.push(stack.pop())
#
#     while not tmp.is_empty():
#         a = tmp.pop()
#
#         try:
#             if podmienka(a):
#                 stack.push(a)
#         except TypeError:
#             continue
#
#
# z = Stack((3, 5, 7, 11))
# print(z)
# push_dno(z, "z")
# print(z)
# print()
#
# cisla = Stack([1, 2, 4, 6, 10])
# print(cisla)
# cisla.push("a")
# print(cisla)
# inc(cisla)
# print(cisla)
# print()
#
# st = Stack(range(3, 10))
# print(st)
# st.push("x")
# print(st)
# nechaj(st, lambda x: x % 3)
# print(st)

# uloha 14

# print(Queue(range(5)))
# print(Queue([123]))

# uloha 15

# def pocet_cisel(rad: Queue) -> int:
#     # tmp = Queue()
#     # count = 0
#     #
#     # while not rad.is_empty():
#     #     a = rad.dequeue()
#     #     tmp.enqueue(a)
#     #
#     #     if type(a) is float or type(a) is int:
#     #         count += 1
#     #
#     # while not tmp.is_empty():
#     #     rad.enqueue(tmp.dequeue())
#     #
#     # return count
#
#     count = 0
#     x = object()
#     rad.enqueue(x)
#
#     while True:
#         a = rad.dequeue()
#         if a == x:
#             break
#         elif type(a) is int or type(a) is float:
#             count += 1
#         rad.enqueue(a)
#
#     return count
#
#
# def druhy(rad: Queue):
#     # count = 0
#     # tmp = Queue()
#     # to_ret = None
#     #
#     # while not rad.is_empty():
#     #     count += 1
#     #     a = rad.dequeue()
#     #     tmp.enqueue(a)
#     #     if count == 2:
#     #         to_ret = a
#     #
#     # while not tmp.is_empty():
#     #     rad.enqueue(tmp.dequeue())
#     #
#     # return to_ret
#
#     count = 0
#     to_ret = None
#     x = object()
#     rad.enqueue(x)
#
#     while True:
#         a = rad.dequeue()
#         count += 1
#         if a == x:
#             break
#         if count == 2:
#             to_ret = a
#         rad.enqueue(a)
#
#     return to_ret
#
#
# def posledny(rad: Queue):
#     # tmp = Queue()
#     # to_ret = None
#     #
#     # while not rad.is_empty():
#     #     to_ret = rad.dequeue()
#     #     tmp.enqueue(to_ret)
#     #
#     # while not tmp.is_empty():
#     #     rad.enqueue(tmp.dequeue())
#     #
#     # return to_ret
#
#     to_ret = None
#     x = object()
#     rad.enqueue(x)
#
#     while True:
#         a = rad.dequeue()
#         if a == x:
#             break
#         else:
#             to_ret = a
#         rad.enqueue(a)
#
#     return to_ret
#
#
# q = Queue(['a', 27/10, '3', 37])
# print(q)
# print(pocet_cisel(q))
# print(druhy(q))
# print(posledny(q))
# print(q)
