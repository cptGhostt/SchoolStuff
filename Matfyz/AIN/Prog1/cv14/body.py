class Body:
    def __init__(self):
        self.body = 0

    def pridaj(self):
        self.body += 1

    def uber(self):
        self.body -= 1

    def kolko(self):
        return self.body
