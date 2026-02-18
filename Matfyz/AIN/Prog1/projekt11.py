# 11. zadanie: pajton
# autor: Peter Kendra
# datum: 12.12.2023

class Pajton:
    def __init__(self):
        self.tab = {}

    def prem(self, meno):
        try:
            return self.tab[meno]
        except KeyError:
            raise NameError

    def vyraz(self, retazec):
        if retazec.isdigit() or (retazec[1:].isdigit() and retazec[0] == "-"):
            return int(retazec)
        tmp = retazec.split()
        if "+" in tmp[0] or ("-" in tmp[0] and "-" != tmp[0][0]) or "*" in tmp[0] or "/" in tmp[0]:
            raise SyntaxError

        if len(tmp) == 1:
            if tmp[0].isdigit():
                return int(tmp[0])
            else:
                return self.prem(tmp[0])

        if tmp[0].isdigit() or (tmp[0][1:].isdigit() and tmp[0][0] == "-"):
            to_ret = int(tmp[0])
        else:
            to_ret = self.prem(tmp[0])

        if "+" not in tmp and "-" not in tmp and "*" not in tmp and "/" not in tmp:
            raise SyntaxError

        op = ""
        for i in range(1, len(tmp)):
            if len(tmp[i]) > 1 and ("+" in tmp[0] or ("-" in tmp[0] and "-" != tmp[0][0]) or "*" in tmp[0] or "/" in tmp[0]):
                raise SyntaxError

            if tmp[i] == "+" or tmp[i] == "-" or tmp[i] == "*" or tmp[i] == "/":
                op = tmp[i]
            else:
                if op == "+":
                    if tmp[i].isdigit() or (tmp[i][1:].isdigit() and tmp[i][0] == "-"):
                        to_ret += int(tmp[i])
                    else:
                        to_ret += self.prem(tmp[i])
                elif op == "-":
                    if tmp[i].isdigit() or (tmp[i][1:].isdigit() and tmp[i][0] == "-"):
                        to_ret -= int(tmp[i])
                    else:
                        to_ret -= self.prem(tmp[i])
                elif op == "*":
                    if tmp[i].isdigit() or (tmp[i][1:].isdigit() and tmp[i][0] == "-"):
                        to_ret *= int(tmp[i])
                    else:
                        to_ret *= self.prem(tmp[i])
                elif op == "/":
                    if tmp[i].isdigit() or (tmp[i][1:].isdigit() and tmp[i][0] == "-"):
                        if int(tmp[i]) == 0:
                            to_ret = 0
                        else:
                            to_ret //= int(tmp[i])
                    else:
                        if int(self.prem(tmp[i])) == 0:
                            to_ret = 0
                        else:
                            to_ret //= self.prem(tmp[i])
        return int(to_ret)

    def prirad(self, meno: str, hodnota):
        if meno[0].isdigit():
            raise NameError

        for i in meno:
            if i == "_" or 48 <= ord(i) <= 57 or 65 <= ord(i) <= 90 or 97 <= ord(i) <= 122:
                continue
            raise NameError

        if type(hodnota) is str:
            if "-" in hodnota and "-" not in hodnota.split() and " " not in hodnota:
                self.tab[meno] = -int(self.vyraz(str(hodnota[1:])))
                return None
            else:
                self.tab[meno] = int(self.vyraz(str(hodnota)))
        else:
            self.tab[meno] = hodnota

    def prikaz(self, retazec):
        retazec = retazec.strip()

        if retazec == 'globals()':
            return self.globals()
        if retazec == 'dir()':
            return self.dir()

        if "=" in retazec:
            if " = " in retazec:
                return self.prirad(retazec[:retazec.find("=")-1], retazec[retazec.find("=")+2:])
            else:
                raise SyntaxError
        elif "+" in retazec or "-" in retazec or "*" in retazec or "/" in retazec:
            return self.vyraz(retazec)
        else:
            if retazec.isdigit():
                return int(retazec)
            return self.prem(retazec)

    def dir(self):
        return set(self.tab.keys())

    def globals(self):
        if len(self.tab) == 0:
            return None

        to_ret = ""
        for i in self.tab:
            to_ret += f"{i}: {self.tab[i]}\n"

        return to_ret.strip()


if __name__ == '__main__':
    p = Pajton()

    p.prikaz('___7_ = 7')
    p.prikaz('___7_ = 15 - ___7_')
    print(p.prikaz('___7_ = ___7_ + -13 * 3'))
    print(p.prikaz('___7_'))

    # while True:
    #     try:
    #         hodn = p.prikaz(input('>>> '))
    #         if hodn is not None:
    #             print(hodn)
    #     except SyntaxError:
    #         print('+++ syntakticka chyba +++')
    #     except NameError:
    #         print('+++ chybne meno premennej +++')
