# 9. zadanie: karel
# autor: Peter Kendra
# datum: 03.12.2023

class RobotKarel:
    def __init__(self, meno_suboru):
        self.pozicia = []
        self.storage = []

        with open(meno_suboru, "r", encoding="utf8") as f:
            tmp = f.readline().split()
            self.plocha = []
            self.rozmer = [tmp[0], tmp[1]]

            for i in range(int(tmp[0])):
                self.plocha.append([])

                for j in range(int(tmp[1])):
                    self.plocha[i].append([])

            tmp = f.readline()
            while tmp != "":
                tmp2 = tmp.split()
                self.plocha[int(tmp2[1])][int(tmp2[2])].insert(0, tmp2[0])
                tmp = f.readline()

    def __str__(self):
        to_ret = ""

        for i in self.plocha:
            for j in i:
                try:
                    to_ret += j[0]
                except IndexError:
                    to_ret += "."
            to_ret += "\n"

        return to_ret.strip()

    def robot(self, riadok, stlpec, smer):
        if len(self.pozicia) != 0:
            self.plocha[self.pozicia[0]][self.pozicia[1]].pop(0)
            self.pozicia.clear()

        self.pozicia.append(riadok)
        self.pozicia.append(stlpec)
        self.pozicia.append(smer)

        if smer == 0:
            self.plocha[riadok][stlpec].insert(0, '>')
        elif smer == 1:
            self.plocha[riadok][stlpec].insert(0, 'v')
        elif smer == 2:
            self.plocha[riadok][stlpec].insert(0, '<')
        elif smer == 3:
            self.plocha[riadok][stlpec].insert(0, '^')

    def rob(self, prikaz):
        vykonane = 0
        opakuj = 1
        tmp = prikaz.split()

        while len(tmp) != 0:
            try:
                opakuj = int(tmp[0])
                tmp.pop(0)

            except ValueError:
                if tmp[0] == "vlavo":
                    self.plocha[self.pozicia[0]][self.pozicia[1]].pop(0)

                    for i in range(opakuj):
                        self.pozicia[2] -= 1
                        if self.pozicia[2] == -1:
                            self.pozicia[2] = 3
                        vykonane += 1

                    if self.pozicia[2] == 0:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '>')
                    elif self.pozicia[2] == 1:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, 'v')
                    elif self.pozicia[2] == 2:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '<')
                    elif self.pozicia[2] == 3:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '^')

                    opakuj = 1

                elif tmp[0] == "vpravo":
                    self.plocha[self.pozicia[0]][self.pozicia[1]].pop(0)

                    for i in range(opakuj):
                        self.pozicia[2] += 1
                        if self.pozicia[2] == 4:
                            self.pozicia[2] = 0
                        vykonane += 1

                    if self.pozicia[2] == 0:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '>')
                    elif self.pozicia[2] == 1:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, 'v')
                    elif self.pozicia[2] == 2:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '<')
                    elif self.pozicia[2] == 3:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '^')

                    opakuj = 1

                elif tmp[0] == "krok":
                    self.plocha[self.pozicia[0]][self.pozicia[1]].pop(0)

                    for i in range(opakuj):
                        if self.pozicia[2] == 0:
                            self.pozicia[1] += 1
                            if self.pozicia[1] < int(self.rozmer[1]):
                                vykonane += 1
                        elif self.pozicia[2] == 1:
                            self.pozicia[0] += 1
                            if self.pozicia[0] < int(self.rozmer[0]):
                                vykonane += 1
                        elif self.pozicia[2] == 2:
                            self.pozicia[1] -= 1
                            if self.pozicia[1] >= 0:
                                vykonane += 1
                        elif self.pozicia[2] == 3:
                            self.pozicia[0] -= 1
                            if self.pozicia[0] >= 0:
                                vykonane += 1

                    if self.pozicia[0] >= int(self.rozmer[0]):
                        self.pozicia[0] = int(self.rozmer[0])-1
                    if self.pozicia[0] < 0:
                        self.pozicia[0] = 0
                    if self.pozicia[1] >= int(self.rozmer[1]):
                        self.pozicia[1] = int(self.rozmer[1])-1
                    if self.pozicia[1] < 0:
                        self.pozicia[1] = 0

                    if self.pozicia[2] == 0:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '>')
                    elif self.pozicia[2] == 1:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, 'v')
                    elif self.pozicia[2] == 2:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '<')
                    elif self.pozicia[2] == 3:
                        self.plocha[self.pozicia[0]][self.pozicia[1]].insert(0, '^')

                    opakuj = 1

                elif tmp[0] == "zdvihni":
                    for i in range(opakuj):
                        try:
                            self.storage.append(self.plocha[self.pozicia[0]][self.pozicia[1]].pop(1))
                            vykonane += 1
                        except IndexError:
                            continue

                    opakuj = 1

                elif tmp[0] == "poloz":
                    for i in range(opakuj):
                        try:
                            self.plocha[self.pozicia[0]][self.pozicia[1]].insert(1, self.storage.pop())
                            vykonane += 1
                        except IndexError:
                            continue

                    opakuj = 1

                tmp.pop(0)

        return vykonane

    def batoh(self):
        return self.storage
