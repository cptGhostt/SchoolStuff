# 6. zadanie: rodokmen
# autor: Peter Kendra
# datum: 12.04.2024


class FamilyTree:

    class Node:
        def __init__(self, data, left=None, right=None):
            self.data, self.left, self.right = data, left, right

    # ----------------------------

    def __init__(self, file_name):
        self.root = None
        rodicia = set()
        deti = set()
        rodina = {}

        with open(file_name, 'rb') as f:
            db = f.read(2)
            while db != b'':
                d = int.from_bytes(db, 'big')
                d1 = d // 1000
                d2 = (d//10) % 100
                rod = f.read(d1).decode('utf-8')
                pot = f.read(d2).decode('utf-8')
                if rod not in rodina:
                    rodina[rod] = []
                    rodina[rod].append(pot)
                else:
                    rodina[rod].append(pot)
                rodicia.add(rod)
                deti.add(pot)
                db = f.read(2)

            self.root = self.Node((rodicia - (rodicia & deti)).pop())

            q = [self.root]
            while q:
                dalej = []
                for i in q:
                    vrch = i
                    try:
                        pom = rodina[vrch.data]
                    except KeyError:
                        continue
                    if len(pom) == 1:
                        vrch.left = self.Node(pom.pop())
                    else:
                        vrch.left = self.Node(pom.pop())
                        vrch.right = self.Node(pom.pop())

                    if vrch.left is not None:
                        dalej.append(vrch.left)
                    if vrch.right is not None:
                        dalej.append(vrch.right)
                q = dalej

    def __len__(self):
        if self.root is None:
            return 0
        to_ret = 0
        uroven = [self.root]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                to_ret += 1
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            uroven = dalsia_uroven

        return to_ret

    def depth(self, data):
        if self.root is None:
            return None
        to_ret = 0
        control = False
        uroven = [self.root]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.data == data:
                    control = True
                    break
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            if control:
                break
            to_ret += 1
            uroven = dalsia_uroven
        else:
            return None

        return to_ret

    def height(self):
        if self.root is None:
            return 0
        to_ret = 0
        uroven = [self.root]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            to_ret += 1
            uroven = dalsia_uroven

        return to_ret - 1

    def width(self):
        if self.root is None:
            return 0
        to_ret = 0
        uroven = [self.root]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            if len(dalsia_uroven) > to_ret:
                to_ret = len(dalsia_uroven)
            uroven = dalsia_uroven

        return to_ret

    def subtree_num(self, data):
        if data == self.root.data:
            return len(self)

        uroven = [self.root]
        control = False
        hladany = None
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.data == data:
                    hladany = vrch
                    control = True
                    break
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            if control:
                break
            uroven = dalsia_uroven
        else:
            return 0

        to_ret = 0
        uroven = [hladany]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                to_ret += 1
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            uroven = dalsia_uroven

        return to_ret

    def descendant(self, data1, data2):
        if self.root is None:
            return False
        uroven = [self.root]
        control = False
        chceny = None
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.data == data1:
                    control = True
                    chceny = vrch
                    break
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            if control:
                break
            uroven = dalsia_uroven

        uroven = [chceny]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.left is not None:
                    if vrch.left.data == data2:
                        return True
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    if vrch.right.data == data2:
                        return True
                    dalsia_uroven.append(vrch.right)
            uroven = dalsia_uroven
        else:
            return False

    def level_set(self, k):
        if self.root is None:
            return 0
        uroven_no = 0
        uroven = [self.root]
        while uroven:
            if uroven_no == k:
                to_ret = set()
                for i in uroven:
                    to_ret.add(i.data)
                return to_ret
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            uroven = dalsia_uroven
            uroven_no += 1
        else:
            return set()

    def leaves_num(self):
        if self.root is None:
            return 0
        to_ret = 0
        uroven = [self.root]
        while uroven:
            dalsia_uroven = []
            for vrch in uroven:
                if vrch.left is None and vrch.right is None:
                    to_ret += 1
                    continue
                if vrch.left is not None:
                    dalsia_uroven.append(vrch.left)
                if vrch.right is not None:
                    dalsia_uroven.append(vrch.right)
            uroven = dalsia_uroven

        return to_ret


if __name__ == '__main__':
    import time
    start = time.time()
    f = FamilyTree('subor1.dat')
    # print('pocet vrcholov =', len(f))
    # print('podstrom pre Bohumir =', f.subtree_num('Bohumir'))
    # print('podstrom pre Robert =', f.subtree_num('Robert'))
    # print('vyska =', f.height())
    # print('sirka =', f.width())
    # print('hlbka vrcholu Vlastimil =', f.depth('Vlastimil'))
    # print('Miroslav ma potomka Bohuslav =', f.descendant('Miroslav','Bohuslav'))
    # print('Jaroslav ma potomka Svatopluk =', f.descendant('Jaroslav','Svatopluk'))
    # print('vrcholy na urovni 2 =', f.level_set(2))
    # print('vrcholy na urovni 10 =', f.level_set(10))
    # print('pocet listov =', f.leaves_num())
    print(f.descendant('Jaroslav', 'Jaroslav'))
    print(time.time() - start)

