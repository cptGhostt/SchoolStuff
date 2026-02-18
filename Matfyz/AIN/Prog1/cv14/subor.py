class Subor:
    def __init__(self, meno_suboru):
        self.meno_suboru = meno_suboru
        with open(meno_suboru, "w") as f:
            pass

    def pripis(self, text):
        with open(self.meno_suboru, "a") as file:
            file.write(text + "\n")

    def vypis(self):
        with open(self.meno_suboru, "r") as file:
            print(file.read(), end="")
