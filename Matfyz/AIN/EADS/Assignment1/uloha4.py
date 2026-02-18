import heapq

line = input().split()
n = int(line[0])
k = int(line[1])
values = input().split()

max_heap = []
max_heap_size = [0]
max_delete_size = [0]
min_heap = []
min_heap_size = [0]
min_delete_size = [0]
to_delete = set()
to_print = []


def lazy_delete():
    while max_heap and -max_heap[0] in to_delete:
        to_delete.remove(-max_heap[0])
        heapq.heappop(max_heap)
        max_delete_size[0] -= 1
        max_heap_size[0] -= 1

    while min_heap and min_heap[0] in to_delete:
        to_delete.remove(min_heap[0])
        heapq.heappop(min_heap)
        min_delete_size[0] -= 1
        min_heap_size[0] -= 1

    if not min_heap and max_heap:
        heapq.heappush(min_heap, -heapq.heappop(max_heap))
        min_heap_size[0] += 1
        max_heap_size[0] -= 1
    if not max_heap and min_heap:
        heapq.heappush(max_heap, -heapq.heappop(min_heap))
        max_heap_size[0] += 1
        min_heap_size[0] -= 1


def add_to_heap(height):
    if (not max_heap) or (-height >= max_heap[0]):
        heapq.heappush(max_heap, -height)
        max_heap_size[0] += 1
    else:
        heapq.heappush(min_heap, height)
        min_heap_size[0] += 1


def remove_oldest(height):
    to_delete.add(height)
    if height >= min_heap[0]:
        min_delete_size[0] += 1
    if -height >= max_heap[0]:
        max_delete_size[0] += 1


def balance_heaps():
    lazy_delete()

    while max_heap_size[0] - max_delete_size[0] > min_heap_size[0] - min_delete_size[0] + 1:
        heapq.heappush(min_heap, -heapq.heappop(max_heap))
        max_heap_size[0] -= 1
        min_heap_size[0] += 1

    while min_heap_size[0] - min_delete_size[0] > max_heap_size[0] - max_delete_size[0]:
        heapq.heappush(max_heap, -heapq.heappop(min_heap))
        min_heap_size[0] -= 1
        max_heap_size[0] += 1


for i in range(k):
    add_to_heap(int(values[i]))
balance_heaps()

to_print.append(-max_heap[0])

for i in range(k, n):
    remove_oldest(int(values[i - k]))
    balance_heaps()
    add_to_heap(int(values[i]))
    balance_heaps()
    lazy_delete()
    to_print.append(-max_heap[0])

print(*to_print)
