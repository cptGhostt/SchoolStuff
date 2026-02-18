# 13. zadanie: mravec
# autor: Peter Kendra
# datum: 01.01.2024

class Mravec:
    def __init__(self, meno_suboru):
        self.specialne = []
        self.plocha = []
        self.rozmer = []
        self.poloha = []

        with open(meno_suboru, "r", encoding="utf8") as f:
            riadok = f.readline()
            while riadok != "\n":
                tmp = []
                for i in riadok:
                    if i == "\n":
                        continue
                    tmp.append([i])
                self.plocha.append(tmp)
                riadok = f.readline()

            for i in range(len(self.plocha)):
                for j in range(len(self.plocha[0])):
                    if self.plocha[i][j][0] == "+":
                        self.specialne.append((i, j))

            riadok = f.readline()
            while riadok != "":
                riadok = riadok.split()
                self.plocha[int(riadok[1])][int(riadok[2])].insert(0, riadok[0])
                riadok = f.readline()

        self.rozmer = (len(self.plocha), len(self.plocha[0]))

        # print(*self.plocha, sep="\n")
        # print(self.specialne)
        # print(self.rozmer)

    def __str__(self):
        to_ret = ""

        for i in self.plocha:
            for j in i:
                to_ret += j[0]
            to_ret += "\n"

        return to_ret[:len(to_ret)-1]

    def start(self, riadok, stlpec):
        self.poloha = [riadok, stlpec]
        self.plocha[riadok][stlpec].insert(0, "@")

    def rob(self, prikazy):
        while prikazy != "":
            self.plocha[self.poloha[0]][self.poloha[1]].pop(0)

            if prikazy[0] == "p":
                if self.poloha[1] + 1 < self.rozmer[1]:
                    self.poloha[1] += 1
                self.plocha[self.poloha[0]][self.poloha[1]].insert(0, "@")

                if self.plocha[self.poloha[0]][self.poloha[1]][1] != "+" and self.plocha[self.poloha[0]][self.poloha[1]][1] != ".":
                    tmp = True
                    offset = 0
                else:
                    tmp = False

                while tmp:
                    mem = self.plocha[self.poloha[0]][self.poloha[1] + offset].pop(1)
                    offset += 1
                    try:
                        self.plocha[self.poloha[0]][self.poloha[1] + offset].insert(0, mem)
                    except IndexError:
                        tmp = False

                    try:
                        if self.plocha[self.poloha[0]][self.poloha[1] + offset][1] == "+" or self.plocha[self.poloha[0]][self.poloha[1] + offset][1] == ".":
                            tmp = False
                    except IndexError:
                        tmp = False

            elif prikazy[0] == "l":

                if self.poloha[1] - 1 > -1:
                    self.poloha[1] -= 1
                self.plocha[self.poloha[0]][self.poloha[1]].insert(0, "@")

                if self.plocha[self.poloha[0]][self.poloha[1]][1] != "+" and self.plocha[self.poloha[0]][self.poloha[1]][1] != ".":
                    tmp = True
                    offset = 0
                else:
                    tmp = False

                while tmp:
                    mem = self.plocha[self.poloha[0]][self.poloha[1] - offset].pop(1)
                    offset += 1
                    try:
                        if self.poloha[1] - offset >= 0:
                            self.plocha[self.poloha[0]][self.poloha[1] - offset].insert(0, mem)
                    except IndexError:
                        tmp = False

                    try:
                        if self.plocha[self.poloha[0]][self.poloha[1] - offset][1] == "+" or self.plocha[self.poloha[0]][self.poloha[1] - offset][1] == ".":
                            tmp = False
                    except IndexError:
                        tmp = False

            elif prikazy[0] == "d":

                if self.poloha[0] + 1 < self.rozmer[0]:
                    self.poloha[0] += 1
                self.plocha[self.poloha[0]][self.poloha[1]].insert(0, "@")

                if self.plocha[self.poloha[0]][self.poloha[1]][1] != "+" and self.plocha[self.poloha[0]][self.poloha[1]][1] != ".":
                    tmp = True
                    offset = 0
                else:
                    tmp = False

                while tmp:
                    mem = self.plocha[self.poloha[0] + offset][self.poloha[1]].pop(1)
                    offset += 1
                    try:
                        self.plocha[self.poloha[0] + offset][self.poloha[1]].insert(0, mem)
                    except IndexError:
                        tmp = False

                    try:
                        if self.plocha[self.poloha[0] + offset][self.poloha[1]][1] == "+" or self.plocha[self.poloha[0] + offset][self.poloha[1]][1] == ".":
                            tmp = False
                    except IndexError:
                        tmp = False

            elif prikazy[0] == "h":

                if self.poloha[0] - 1 > -1:
                    self.poloha[0] -= 1
                self.plocha[self.poloha[0]][self.poloha[1]].insert(0, "@")

                if self.plocha[self.poloha[0]][self.poloha[1]][1] != "+" and self.plocha[self.poloha[0]][self.poloha[1]][1] != ".":
                    tmp = True
                    offset = 0
                else:
                    tmp = False

                while tmp:
                    mem = self.plocha[self.poloha[0] - offset][self.poloha[1]].pop(1)
                    offset += 1
                    try:
                        if self.poloha[0] - offset >= 0:
                            self.plocha[self.poloha[0] - offset][self.poloha[1]].insert(0, mem)
                    except IndexError:
                        tmp = False

                    try:
                        if self.plocha[self.poloha[0] - offset][self.poloha[1]][1] == "+" or self.plocha[self.poloha[0] - offset][self.poloha[1]][1] == ".":
                            tmp = False
                    except IndexError:
                        tmp = False

            prikazy = prikazy[1:]

    def zisti(self):
        to_ret = set()

        for i in self.specialne:
            if self.plocha[i[0]][i[1]][0] != "+" and self.plocha[i[0]][i[1]][0] != "@":
                to_ret.add(self.plocha[i[0]][i[1]][0])

        return to_ret


if __name__ == '__main__':
    # test 2
    m = Mravec('subor1.txt')
    m.start(2, 0)
    m.rob('')
    m.rob('pppp')
    print(m)
    print()
    m.rob('p')
    print(m)
    print()
    m.rob('hp')
    print(m)
    print()
    m.rob('llll')
    print(m)

    # test 1
    # m = Mravec('subor1.txt')m.rob('')
    # print(m)
    # print('zisti =', m.zisti())
    # m.start(1, 0)
    # m.rob('pp')
    # print(m)
    # print('zisti =', m.zisti())
    # m.rob('dl')
    # print(m)
    # print('zisti =', m.zisti())
