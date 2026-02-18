# 9. zadanie: graf
# autor: Peter Kendra
# datum: 29.04.2024

class Graph:
    def __init__(self, file_name):
        self.graph = set()

        with open(file_name, 'r', encoding="utf8") as f:
            typ = f.readline()[:2]

            if typ == "#1":
                line = f.readline()
                while line != "":
                    line = line.split()
                    var = line[0]
                    line = line[1:]

                    for i in line:
                        self.add_edge(var, i)

                    line = f.readline()

            elif typ == "#2":
                line = f.readline()
                while line != "":
                    line = line.split()
                    self.graph.add((line[0], line[1]))
                    line = f.readline()

            elif typ == "#3":
                line = f.readline().split()
                vars = line

                for i in vars:
                    line = f.readline().split()
                    for j in range(len(line)):
                        if line[j] == "1":
                            self.graph.add((i, vars[j]))

    def add_edge(self, v1, v2):          # pridá hranu
        self.graph.add((v1, v2))

    def adjacent(self, v1, v2):          # zisti, či je hrana
        return (v1, v2) in self.graph

    def vertices(self):                  # vráti množinu mien vrcholov
        vertices = set()

        for i in self.graph:
            vertices.add(i[0])
            vertices.add(i[1])

        return vertices

    def edges(self):                     # vráti množinu dvojíc mien vrcholov
        return self.graph

    def save1(self, file_name):
        tmp = {}
        for i in self.graph:
            if i[0] in tmp:
                tmp[i[0]].add(i[1])
            else:
                tmp[i[0]] = {i[1]}

        with open(file_name, 'w', encoding="utf8") as f:
            print("#1", file=f)
            vertices = set()
            for i in tmp:
                vertices.add(i)
                print(i, file=f, end="")
                for j in tmp[i]:
                    print(f" {j}", file=f, end="")
                print(file=f)

            vertices = self.vertices() - vertices
            for i in vertices:
                print(i, file=f)

    def save2(self, file_name):
        with open(file_name, 'w', encoding="utf8") as f:
            print("#2", file=f)
            for i in self.graph:
                print(i[0], i[1], file=f)

    def save3(self, file_name):
        vertices = self.vertices()
        with open(file_name, 'w', encoding="utf8") as f:
            print("#3", file=f)
            print(" ".join(vertices), file=f)

            for i in vertices:
                tmp = []
                for j in vertices:
                    if (i, j) in self.graph:
                        tmp.append("1")
                    else:
                        tmp.append("0")
                print(" ".join(tmp), file=f)


if __name__ == '__main__':
    g1 = Graph('subor1.txt')
    g2 = Graph('subor2.txt')
    g3 = Graph('subor3.txt')

    g2.add_edge("e", "d")
    g2.add_edge("e", "f")
    g2.add_edge("e", "i")
    print(g2.vertices())
    g2.save3('kontorla.txt')
