# 3. zadanie: Turing
# autor: Peter Kendra
# datum: 22.3.2024

class Turing:
    ### vnorená podtrieda

    class DvojsmernyZoznam:
        class Vrchol:
            def __init__(self, data, prev=None, next=None):
                self.data = data
                self.prev = prev
                self.next = next

        def __init__(self, postupnost):
            self.zac = self.kon = None
            for prvok in postupnost:
                self.append(prvok)
            self.poz = self.zac

        def __str__(self):
            vysl, zoz = [], self.zac
            while zoz is not None:
                vysl.append(str(zoz.data))
                zoz = zoz.next
            # vysl.append('None')
            return ''.join(vysl)

        def __repr__(self):
            vysl, zoz = [], self.zac
            while zoz is not None:
                vysl.append(str(zoz.data))
                zoz = zoz.next
            # vysl.append('None')
            return ''.join(vysl)

        def insert0(self, hodnota):
            self.zac = self.Vrchol(hodnota, None, self.zac)
            if self.kon is None:
                self.kon = self.poz = self.zac
            else:
                self.zac.next.prev = self.zac

        def append(self, hodnota):
            if self.zac is None:
                self.insert0(hodnota)
            else:
                novy = self.Vrchol(hodnota, self.kon)
                self.kon.next = novy
                self.kon = novy

    ### metody triedy Turing

    def __init__(self, program, obsah=''):
        self.program = {}
        self.paska = self.DvojsmernyZoznam(obsah or "_")

        tmp = program.split("\n")
        while "" in tmp:
            tmp.remove("")
        stavy = tmp[0].split()
        tmp.pop(0)
        for i in range(len(tmp)):
            tmp[i] = tmp[i].split()
        while [] in tmp:
            tmp.remove([])

        for i in range(len(stavy)):
            for j in range(len(tmp)):
                rule = tmp[j][i+1]
                if rule == ".":
                    continue
                elif rule == "<" or rule == ">" or rule == "=":
                    self.program[stavy[i], tmp[j][0]] = tmp[j][0], rule, stavy[i]
                elif len(rule) == 2 and (rule[1] == "<" or rule[1] == ">" or rule[1] == "="):
                    self.program[stavy[i], tmp[j][0]] = rule[0], rule[1], stavy[i]
                elif rule[0] == "<" or rule[0] == ">" or rule[0] == "=":
                    self.program[stavy[i], tmp[j][0]] = tmp[j][0], rule[0], rule[1:]
                else:
                    self.program[stavy[i], tmp[j][0]] = rule[0], rule[1], rule[2:]

            self.stav = stavy[0]

    def restart(self, stav=None, obsah=None, n=None):
        # od noveho stavu (ak nie je None), s novou paskou (ak nie je None) a zavola rob()
        if obsah is not None:
            self.paska = self.DvojsmernyZoznam(obsah or "_")
        if stav is not None:
            self.stav = stav

        return self.rob(n)

    def rob(self, n=None):
        count = 0

        while True:
            if n is not None and count+1 > n:
                return False, count
            if self.stav == "end" or self.stav == "stop":
                return True, count

            try:
                rule = self.program[self.stav, self.paska.poz.data]
            except KeyError:
                return False, count
            if rule == ".":
                return False, count
            self.paska.poz.data = rule[0]
            if rule[1] == ">":
                if self.paska.poz.next is None:
                    self.paska.append("_")
                self.paska.poz = self.paska.poz.next
            elif rule[1] == "<":
                if self.paska.poz.prev is None:
                    self.paska.insert0("_")
                self.paska.poz = self.paska.poz.prev

            self.stav = rule[2]
            count += 1

    def text(self):
        return str(self.paska).strip("_")

    text = property(text)


if __name__ == '__main__':
    prog = '''
               A B C D E
             1 <C > _<E < _<A
             _ 1>B 1>C 1>D 1<A 1=end
             
     '''
    t = Turing(prog, '')
    t.rob(100000)
    print(t.restart('A', '', 90900))

