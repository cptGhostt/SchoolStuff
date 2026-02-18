n, m, j = map(int, input().split())
distances = []
for i in range(n):
    distances.append(1 + (i**2 % m))

low, high = max(distances), sum(distances)
last_good = high

while low <= high:
    mid = (low + high) // 2

    jumps = 0
    curr_lng = distances[0]

    for i in range(1, n):
        if curr_lng + distances[i] > mid:
            jumps += 1
            curr_lng = distances[i]
        else:
            curr_lng += distances[i]

    jumps += 1

    if jumps <= j:
        last_good = mid
        high = mid - 1
    else:
        low = mid + 1

print(last_good)
