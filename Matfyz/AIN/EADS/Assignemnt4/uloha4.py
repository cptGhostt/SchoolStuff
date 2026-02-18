n = int(input())
books = [0] * n
customers = [0] * n

tmp = list(map(int, input().split()))
for j in range(n-1, -1, -1):
        books[j] = tmp[n - j - 1]
tmp = list(map(int, input().split()))
for j in range(n-1, -1, -1):
        customers[j] = tmp[n - j - 1]

max_profit = [0]


def rek(books0, customers0, value):
    if not books0 or not customers0:
        if value > max_profit[0]:
            max_profit[0] = value
        return

    if len(books0) >= 3:
        b1, b2, b3, = books0[-1], books0[-2], books0[-3]
        books0.pop()
        books0.pop()
        books0.pop()
        c = customers0[-1]
        customers0.pop()

        books0.append(b3)
        books0.append(b2)
        rek(books0, customers0, value + (c * b1))

        books0.pop()
        books0.append(b1)
        rek(books0, customers0, value + (c * b2))

        books0.pop()
        books0.pop()
        books0.append(b2)
        books0.append(b1)
        rek(books0, customers0, value + (c * b3))

        books0.pop()
        books0.pop()
        books0.append(b3)
        books0.append(b2)
        books0.append(b1)
        customers0.append(c)
    elif len(books0) == 2:
        b1, b2 = books0[-1], books0[-2]
        books0.pop()
        books0.pop()
        c = customers0[-1]
        customers0.pop()

        books0.append(b2)
        rek(books0, customers0, value + (c * b1))

        books0.pop()
        books0.append(b1)
        rek(books0, customers0, value + (c * b2))

        books0.pop()
        books0.append(b2)
        books0.append(b1)
        customers0.append(c)
    elif len(books0) == 1:
        b = books0[0]
        c = customers0[-1]
        customers0.pop()
        books0.pop()
        rek(books0, customers0, value + (c * b))
        customers0.append(c)
        books0.append(b)
    else:
        return


rek(books, customers, 0)
print(max_profit[0])
