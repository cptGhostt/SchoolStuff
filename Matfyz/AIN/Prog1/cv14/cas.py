class Cas:

    def __init__(self, hodiny, minuty):
        self.hodiny = hodiny
        self.minuty = minuty

    def vypis(self):
        if __name__ == "__main__":
            print(f"cas je {self.hodiny:02}:{self.minuty:02}")

    def str(self):
        return f"{self.hodiny:02}:{self.minuty:02}"

    def pridaj(self, hodiny, minuty):
        self.hodiny += hodiny
        self.minuty += minuty

        if self.minuty > 59:
            self.hodiny += self.minuty//60
            self.minuty %= 60

        if self.hodiny > 23:
            self.hodiny %= 24