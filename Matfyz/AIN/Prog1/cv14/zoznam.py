class Zoznam:
    def __init__(self):
        self.zoznam = []

    def pridaj(self, prvok):
        if prvok not in self.zoznam:
            self.zoznam.append(prvok)

    def vyhod(self, prvok):
        if prvok in self.zoznam:
            self.zoznam.pop(self.zoznam.index(prvok))

    def je_v_zozname(self, prvok):
        return prvok in self.zoznam

    def vypis(self):
        print("zoznam: ", end="")
        if len(self.zoznam) > 0:
            print(self.zoznam[0], end="")
        for i in range(1, len(self.zoznam)):
            print(",",self.zoznam[i], end="")
        print()

