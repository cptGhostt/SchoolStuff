# 10. zadanie: sudoku
# autor: Peter Kendra
# datum: 05.12.2023

class Sudoku:
    def __init__(self, meno_suboru):
        self.tab = []

        with open(meno_suboru, "r") as f:
            for riadok in f:
                tmp = []
                for znak in riadok:
                    if znak == ".":
                        tmp.append(".")
                    elif znak == " " or znak == "\n":
                        continue
                    else:
                        tmp.append(int(znak))
                self.tab.append(tmp)

    def __str__(self):
        if type(self.tab[0][0]) is set:
            to_ret = "."
        else:
            to_ret = str(self.tab[0][0])

        for i in range(1, len(self.tab[0])):
            if type(self.tab[0][i]) is set:
                to_ret += " ."
            else:
                to_ret += " " + str(self.tab[0][i])

        for i in range(1, len(self.tab)):
            if type(self.tab[i][0]) is set:
                to_ret += "\n."
            else:
                to_ret += "\n" + str(self.tab[i][0])
            for j in range(1, len(self.tab[i])):
                if type(self.tab[i][j]) is set:
                    to_ret += " ."
                else:
                    to_ret += " " + str(self.tab[i][j])

        return to_ret

    def urob(self):
        jednoprvkove = 0
        control = True

        for i in range(9):
            for j in range(9):
                if self.tab[i][j] == ".":
                    self.tab[i].pop(j)
                    self.tab[i].insert(j, set(range(1, 10)))

        for i in range(9):
            for j in range(9):
                if type(self.tab[i][j]) is set:
                    for z in range(9):
                        if self.tab[i][z] in self.tab[i][j]:
                            self.tab[i][j].remove(self.tab[i][z])

                if type(self.tab[j][i]) is set:
                    for z in range(9):
                        if self.tab[z][i] in self.tab[j][i]:
                            self.tab[j][i].remove(self.tab[z][i])

        for u in (0, 3, 6):
            for v in (0, 3, 6):
                for i in range(u, u+3):
                    for j in range(v, v+3):
                        if type(self.tab[i][j]) is set:
                            for x in range(u, u+3):
                                for y in range(v, v+3):
                                    if self.tab[x][y] in self.tab[i][j]:
                                        self.tab[i][j].remove(self.tab[x][y])
                            if len(self.tab[i][j]) == 1:
                                jednoprvkove += 1
                            elif len(self.tab[i][j]) == 0:
                                control = False
        if control:
            return jednoprvkove
        else:
            return None

    def nahrad(self):
        for i in range(9):
            for j in range(9):
                if type(self.tab[i][j]) is set:
                    if len(self.tab[i][j]) == 1:
                        tmp = self.tab[i][j].pop()
                        self.tab[i].pop(j)
                        self.tab[i].insert(j, tmp)
                    else:
                        self.tab[i].pop(j)
                        self.tab[i].insert(j, ".")



    def ries(self):
        prechody = 0

        tmp = self.urob()
        while tmp is not None:
            self.nahrad()
            prechody += 1

            if self.pocet_nezaplnenych() == 0 or tmp == 0:
                if self.pocet_nezaplnenych() == 0:
                    prechody += 1
                break

            tmp = self.urob()

        self.nahrad()
        if tmp is None:
            prechody += 1
            return prechody, None

        return prechody, self.pocet_nezaplnenych()

    def pocet_nezaplnenych(self):
        to_ret = 0

        for i in self.tab:
            for j in i:
                if j == ".":
                    to_ret += 1

        return to_ret


if __name__ == "__main__":
    s = Sudoku("subor5.txt")
    print(s.ries())
    print(s.tab)
    print(s)
