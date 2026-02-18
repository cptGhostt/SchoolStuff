r, c = map(int, input().split())
matrix = []

for i in range(r):
    matrix.append(list(map(int, input().split())))

max_len = 0
mem = [[-1] * c for i in range(r)]


def dfs(i, j, matrix):
    if mem[i][j] != -1:
        return mem[i][j]
    max_leng = 0

    next = []
    if i > 0 and matrix[i-1][j] < matrix[i][j]:
        next.append((i-1, j))
    if j > 0 and matrix[i][j-1] < matrix[i][j]:
        next.append((i, j-1))
    if i < len(matrix) - 1 and matrix[i+1][j] < matrix[i][j]:
        next.append((i+1, j))
    if j < len(matrix[0]) - 1 and matrix[i][j+1] < matrix[i][j]:
        next.append((i, j+1))

    for u in next:
        a = dfs(u[0], u[1], matrix) + 1
        if a > max_leng:
            max_leng = a

    mem[i][j] = max_leng
    return max_leng


for i in range(r):
    for j in range(c):
        a = dfs(i, j, matrix)
        if a > max_len:
            max_len = a

print(max_len)
# print(*mem, sep='\n')
