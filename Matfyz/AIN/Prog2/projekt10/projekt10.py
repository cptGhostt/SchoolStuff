# 10. zadanie: do_sirky
# autor: Peter Kendra
# datum: 16.05.2024

class Graph:
    def __init__(self, file_name):
        self.graph = {}

        with open(file_name, 'rb') as f:
            b1 = None
            b2 = f.read(1)
            name = ""

            while b1 != b2:
                b1 = b2
                b2 = f.read(1)

                while b1 != b"\x00":
                    name += b1.decode("utf-8")
                    b1 = b2
                    b2 = f.read(1)

                self.graph[name] = set()
                name = ""

            name1 = ""
            name2 = ""
            b1 = None
            b2 = f.read(1)

            while b2 != b"":
                b1 = b2
                b2 = f.read(1)

                while b1 != b"\x00":
                    name1 += b1.decode("utf-8")
                    b1 = b2
                    b2 = f.read(1)

                b1 = b2
                b2 = f.read(1)

                while b1 != b"\x00":
                    name2 += b1.decode("utf-8")
                    b1 = b2
                    b2 = f.read(1)

                self.graph[name1].add(name2)
                self.graph[name2].add(name1)
                name1 = ""
                name2 = ""

    def in_distance(self, v1, start, end=None):
        if end is None:
            end = start

        to_ret = set()
        visited = set()
        queue = [(v1, 0)]

        while queue:
            v1, uroven = queue.pop(0)
            if v1 not in visited:
                visited.add(v1)
                if start <= uroven <= end:
                    to_ret.add(v1)

                for v2 in self.graph[v1]:
                    if v2 not in visited:
                        queue.append((v2, uroven + 1))

        return to_ret
    
    def max(self, v1):
        max_uroven = 0
        max_uroven_vrcholy = set()
        visited = set()
        queue = [(v1, 0)]

        while queue:
            v1, uroven = queue.pop(0)

            if v1 not in visited:
                visited.add(v1)

                if uroven > max_uroven:
                    max_uroven = uroven
                    max_uroven_vrcholy = set()
                if uroven == max_uroven:
                    max_uroven_vrcholy.add(v1)

                for v2 in self.graph[v1]:
                    if v2 not in visited:
                        queue.append((v2, uroven + 1))

        return max_uroven, max_uroven_vrcholy

    def for_all(self, v1):
        to_ret = []
        visited = set()
        queue = [(v1, 0)]

        while queue:
            v1, uroven = queue.pop(0)
            if v1 not in visited:
                visited.add(v1)

                try:
                    to_ret[uroven].add(v1)
                except IndexError:
                    to_ret.append({v1})

                for v2 in self.graph[v1]:
                    if v2 not in visited:
                        queue.append((v2, uroven + 1))

        return to_ret

    def in_middle(self, v1, v2):
        to_ret = set()
        fa1 = self.for_all(v1)
        fa2 = self.for_all(v2)

        for i in range(min(len(fa1), len(fa2))):
            for j in fa1[i] & fa2[i]:
                to_ret.add(j)

        return to_ret


if __name__ == '__main__':
    g = Graph('subor1.dat')
    for v1, i, j in ('4', 1, 3), ('2', 4, 4), ('1', 5, 7), ('7', 1, 3):
        print(f'in_distance({v1!r}, {i}, {j}) =', g.in_distance(v1, i, j))
    print("max('3') =", g.max('3'))
    print("for_all('5') = ", g.for_all('5'))
    for v1, v2 in ('6', '8'), ('3', '7'):
        print(f'in_middle({v1!r}, {v2!r}) =', g.in_middle(v1, v2))
