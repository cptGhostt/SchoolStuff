class Kniha:
    def __init__(self, autor, titul):
        self.autor = autor
        self.titul = titul
        self.vydavatel = None
        self.rok = None

    def nastav_vydavatela(self, vydavatel):
        self.vydavatel = vydavatel

    def nastav_rok(self, rok):
        self.rok = rok

    def vypis(self):
        print(f"Kniha: {self.autor}: {self.titul}", end="")
        if self.vydavatel is not None:
            print(f", {self.vydavatel}", end="")
        if self.rok is not None:
            print(f", {self.rok}", end="")
        print()
