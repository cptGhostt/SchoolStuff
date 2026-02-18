size = tuple(map(int, input().split()))
x = sorted(list(map(int, input().split())), reverse=True)
y = sorted(list(map(int, input().split())), reverse=True)

result = 0
xi, yi = 0, 0
vert, horz = 1, 1

while xi < len(x) or yi < len(y):
    if xi < len(x) and (yi >= len(y) or x[xi] >= y[yi]):
        result += x[xi] * horz
        xi += 1
        vert += 1

    else:
        result += y[yi] * vert
        yi += 1
        horz += 1

print(result % 1000000007)
