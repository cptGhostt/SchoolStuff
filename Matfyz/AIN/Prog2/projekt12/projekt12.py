# 12. zadanie: labyrint
# autor: Peter Kendra
# datum: 23.05.2024

class Labyrinth:
    class Vertex:
        def __init__(self, row, column):  # riadok, stĺpec
            self.adjacent = []            # zoznam susedov, susedia sú typu Vertex
            self.row, self.column = row, column
            self.reward = False           # odmena

        def __repr__(self):
            return f'<{self.row},{self.column}>'

    def __init__(self, file_name):
        self.graph = {}                   # slovník vrcholov grafu – obsahuje objekty typu Vertex

        with open(file_name, 'r') as f:
            line = f.readline().strip().split()

            for i in range(int(line[0])):
                for j in range(int(line[1])):
                    self.graph[(i, j)] = self.Vertex(i, j)

            for i in range(int(line[0])):
                for j in range(int(line[1])):
                    vertex = self.graph[(i, j)]
                    if i != 0:
                        vertex.adjacent.append(self.graph[(i - 1, j)])
                    if j != 0:
                        vertex.adjacent.append(self.graph[(i, j - 1)])
                    if i != int(line[0]) - 1:
                        vertex.adjacent.append(self.graph[(i + 1, j)])
                    if j != int(line[1]) - 1:
                        vertex.adjacent.append(self.graph[(i, j + 1)])

            line = f.readline()
            while line:
                line = line.strip().split()
                if len(line) == 2:
                    self.graph[(int(line[0]), int(line[1]))].reward = True
                else:
                    v2 = (int(line.pop(0)), int(line.pop(0)))
                    while line:
                        v1 = v2
                        v2 = (int(line.pop(0)), int(line.pop(0)))
                        self.graph[v1].adjacent.remove(self.graph[v2])
                        self.graph[v2].adjacent.remove(self.graph[v1])
                line = f.readline()

    def get_vertex(self, row, column):
        return self.graph[(row, column)]

    def change_rewards(self, *seq):
        for i in seq:
            v = self.graph[i]
            v.reward = not v.reward

    def start(self, row, column):
        to_ret = []
        rewards = set()
        for i in self.graph.values():
            if i.reward:
                rewards.add((i.row, i.column))

        def rek(v: Labyrinth.Vertex, cesta: list, rew: set, ret: list, do):
            cesta.append((v.row, v.column))

            for i in rew:
                if i not in cesta:
                    break
            else:
                if do[0]:
                    do[0] = False
                    for j in cesta:
                        ret.append(j)

            for i in v.adjacent:
                if (i.row, i.column) not in cesta:
                    rek(i, cesta, rew, ret, do)
                    cesta.remove((i.row, i.column))
            return ret

        to_ret = rek(self.graph[(row, column)], [], rewards, [], [True])

        return to_ret


if __name__ == '__main__':
    lab = Labyrinth('subor1.txt')
    v = lab.get_vertex(1, 0)
    print('vrchol:', v, 'susedia:', v.adjacent, 'odmena:', v.reward)
    v = lab.get_vertex(0, 2)
    print('vrchol:', v, 'susedia:', v.adjacent, 'odmena:', v.reward)
    print(lab.start(0, 0))
    print(lab.start(0, 2))
    lab.change_rewards((2, 2))
    print(lab.start(0, 0))
