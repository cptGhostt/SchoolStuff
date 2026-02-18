import heapq

n = int(input())
heap_d = []
heap_v = [(1, "nic")]
vybusnosti = {}
to_delete = set()
number_of_days = 0
final = []

for i in range(n):
    tmp = input().split()
    if number_of_days < int(tmp[2])+1:
        number_of_days = int(tmp[2])+1
    vybusnosti[tmp[0]] = int(tmp[3])
    heapq.heappush(heap_d, (int(tmp[1]), True, tmp[0]))
    heapq.heappush(heap_d, (int(tmp[2])+1, False, tmp[0]))

for i in range(number_of_days):
    while heap_d[0][0] == i:
        if heap_d[0][1]:
            heapq.heappush(heap_v, (-vybusnosti[heap_d[0][2]], heap_d[0][2]))
            heapq.heappop(heap_d)
        else:
            to_delete.add(heap_d[0][2])
            heapq.heappop(heap_d)

    while heap_v[0][1] in to_delete:
        heapq.heappop(heap_v)

    final.append(heap_v[0][1])

start = 0
current = final[0]
end = 1
for i in range(len(final)):
    end = i
    if final[i] != current:
        print(current, start, i-1)
        current = final[i]
        start = i
print(current, start, end)
