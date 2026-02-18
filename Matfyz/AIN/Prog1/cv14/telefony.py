class TelefonnyZoznam:
    def __init__(self):
        self.zoznam = []

    def pridaj(self, meno, telefon):
        for i in self.zoznam:
            if i[0] == meno:
                self.zoznam.insert(self.zoznam.index(i), (meno, telefon))
                self.zoznam.pop(self.zoznam.index(i))
                return
        self.zoznam.append((meno, telefon))

    def vypis(self):
        for i in self.zoznam:
            print(i[0], i[1])
