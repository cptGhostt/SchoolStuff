# 12. zadanie: robot
# autor: Peter Kendra
# datum: 14.12.2023

class Robot:
    def __init__(self, meno_suboru):
        self.room = []
        self.poloha = None
        self.rozmer = [0, 0]

        with open(meno_suboru, "r") as f:
            tmp = ""
            last = ""

            line = f.readline()
            while line != "":
                tmp += last
                last = line
                line = f.readline()

        last = last.split()
        last[0] = int(last[0])
        last[1] = int(last[1])
        self.rozmer = last

        for i in range(last[0]):
            self.room.append([])
            for j in range(last[1]):
                self.room[i].append(["."])
        if tmp != "":
            tmp = tmp.strip().split("\n")

        for i in range(len(tmp)):
            tmp[i] = tmp[i].split()
            for j in range(len(tmp[i])):
                tmp[i][j] = int(tmp[i][j])

        if tmp != "":
            if len(tmp) > 0:
                for i in tmp:
                    if len(i) == 2:
                        self.room[i[0]][i[1]] = "#"
                    else:
                        for j in range(i[0], i[1]+1):
                            for u in range(i[2], i[3]+1):
                                self.room[j][u] = "#"

    def __str__(self):
        to_ret = ""

        for i in self.room:
            for j in i:
                if j[0] == ".":
                    to_ret += " ."
                elif j == "#":
                    to_ret += " #"
                elif j[0] == "R":
                    to_ret += " R"
                else:
                    if len(str(j[0] % 100)) == 1:
                        to_ret += " " + str(j[0] % 100)
                    else:
                        to_ret += str(j[0] % 100)
            to_ret += "\n"

        return to_ret

    def daj_robot(self):
        return self.poloha

    def zmen_robot(self, poloha):
        for i in self.room:
            for j in i:
                if type(j) is list and j[0] == "R":
                    j.pop(0)

        self.poloha = list(poloha)
        self.room[poloha[0]][poloha[1]].insert(0, "R")
        if self.room[poloha[0]][poloha[1]][1] == ".":
            self.room[poloha[0]][poloha[1]][1] = 1
        else:
            self.room[poloha[0]][poloha[1]][1] += 1
        self.poloha = tuple(self.poloha)

    robot = property(daj_robot, zmen_robot)

    def poloz(self, poloha):
        if len(poloha) == 2:
            self.room[poloha[0]][poloha[1]] = "#"
        else:
            for i in range(poloha[0], poloha[1]+1):
                for j in range(poloha[2], poloha[3]+1):
                    self.room[i][j] = "#"

    def pohyb(self, prikazy):
        skok = "0"
        hotove = 0
        self.poloha = list(self.poloha)

        while prikazy != "":
            if prikazy[0] == "p":
                prikazy = prikazy[1:]
                if self.poloha[1] + int(skok) + 1 >= self.rozmer[1]:
                    skok = "0"
                    continue
                elif self.room[self.poloha[0]][self.poloha[1] + int(skok) + 1] == "#":
                    skok = "0"
                    continue
                else:

                    hotove += 1
                    self.room[self.poloha[0]][self.poloha[1]].pop(0)
                    self.room[self.poloha[0]][self.poloha[1] + int(skok) + 1].insert(0, "R")
                    if self.room[self.poloha[0]][self.poloha[1] + int(skok) + 1][1] == ".":
                        self.room[self.poloha[0]][self.poloha[1] + int(skok) + 1][1] = 1
                        self.poloha[1] = self.poloha[1] + int(skok) + 1
                    else:
                        self.room[self.poloha[0]][self.poloha[1] + int(skok) + 1][1] += 1
                        self.poloha[1] = self.poloha[1] + int(skok) + 1
                    skok = "0"
            elif prikazy[0] == "d":
                prikazy = prikazy[1:]
                if self.poloha[0] + int(skok) + 1 >= self.rozmer[0]:
                    skok = "0"
                    continue
                elif self.room[self.poloha[0] + int(skok) + 1][self.poloha[1]] == "#":
                    skok = "0"
                    continue
                else:
                    hotove += 1
                    self.room[self.poloha[0]][self.poloha[1]].pop(0)
                    self.room[self.poloha[0] + int(skok) + 1][self.poloha[1]].insert(0, "R")
                    if self.room[self.poloha[0] + int(skok) + 1][self.poloha[1]][1] == ".":
                        self.room[self.poloha[0] + int(skok) + 1][self.poloha[1]][1] = 1
                        self.poloha[0] = self.poloha[0] + int(skok) + 1
                    else:
                        self.room[self.poloha[0] + int(skok) + 1][self.poloha[1]][1] += 1
                        self.poloha[0] = self.poloha[0] + int(skok) + 1
                    skok = "0"
            elif prikazy[0] == "l":
                prikazy = prikazy[1:]
                if self.poloha[1] - int(skok) - 1 < 0:
                    skok = "0"
                    continue
                elif self.room[self.poloha[0]][self.poloha[1] - int(skok) - 1] == "#":
                    skok = "0"
                    continue
                else:
                    hotove += 1
                    self.room[self.poloha[0]][self.poloha[1]].pop(0)
                    self.room[self.poloha[0]][self.poloha[1] - int(skok) - 1].insert(0, "R")
                    if self.room[self.poloha[0]][self.poloha[1] - int(skok) - 1][1] == ".":
                        self.room[self.poloha[0]][self.poloha[1] - int(skok) - 1][1] = 1
                        self.poloha[1] = self.poloha[1] - int(skok) - 1
                    else:
                        self.room[self.poloha[0]][self.poloha[1] - int(skok) - 1][1] += 1
                        self.poloha[1] = self.poloha[1] - int(skok) - 1
                    skok = "0"
            elif prikazy[0] == "h":
                prikazy = prikazy[1:]
                if self.poloha[0] - int(skok) - 1 < 0:
                    skok = "0"
                    continue
                elif self.room[self.poloha[0] - int(skok) - 1][self.poloha[1]] == "#":
                    skok = "0"
                    continue
                else:
                    hotove += 1
                    self.room[self.poloha[0]][self.poloha[1]].pop(0)
                    self.room[self.poloha[0] - int(skok) - 1][self.poloha[1]].insert(0, "R")
                    if self.room[self.poloha[0] - int(skok) - 1][self.poloha[1]][1] == ".":
                        self.room[self.poloha[0] - int(skok) - 1][self.poloha[1]][1] = 1
                        self.poloha[0] = self.poloha[0] - int(skok) - 1
                    else:
                        self.room[self.poloha[0] - int(skok) - 1][self.poloha[1]][1] += 1
                        self.poloha[0] = self.poloha[0] - int(skok) - 1
                    skok = "0"
            elif prikazy[0].isdigit():
                if skok == "0":
                    skok = prikazy[0]
                    prikazy = prikazy[1:]
                else:
                    skok += prikazy[0]
                    prikazy = prikazy[1:]
            else:
                prikazy = prikazy[1:]

        self.poloha = tuple(self.poloha)

        return hotove
