# 7. zadanie: repository
# autor: Peter Kendra
# datum: 26.04.2024

class Repository:
    class Node:
        def __init__(self, value=None):    # vrchol prefixového stromu
            self.value = value
            self.child = None    # spájaný zoznam typu Child - spájaný zoznam podstromov

    class Child:
        def __init__(self, char, node=None, next=None):
            self.char = char
            self.node = node     # podstrom typu Node
            self.next = next     # nasledovný prvok spájaného zoznamu

    def __init__(self):
        self.root = None         # prázdny strom
        self.pocet_vrcholov = 0
        self.dlzka = 0

    def __setitem__(self, key, value):
        if self.root is None:
            self.root = self.Node()
            self.pocet_vrcholov += 1
        if key == "":
            self.root.value = value

        node = self.root

        for i in key:
            child = node.child
            if child is None:
                node.child = self.Child(i, self.Node())
                self.pocet_vrcholov += 1
                node = node.child.node
                continue

            while True:
                if child.char == i:
                    break
                if child.next is None:
                    child.next = self.Child(i, self.Node())
                    self.pocet_vrcholov += 1
                child = child.next
            node = child.node

        if node.value is None:
            self.dlzka += 1
        node.value = value
        # print(node.value, "set_item")

    def __getitem__(self, key):
        if self.root is None:
            raise KeyError
        if key == "":
            return self.root.value

        node = self.root

        for i in key:
            child = node.child
            if child is None:
                raise KeyError
            while True:
                if child.char == i:
                    break
                if child.next is None:
                    raise KeyError
                child = child.next
            node = child.node

        if node.value is None:
            raise KeyError
        # print(node.value, "get_item")
        return node.value

    def __delitem__(self, key):
        raise KeyError

    def node_count(self):
        return self.pocet_vrcholov

    def __len__(self):
        return self.dlzka

    def __iter__(self):
        to_yield = set()

        def rek(node, set, slovo):
            if node is None:
                return
            if node.value is not None:
                set.add(slovo)
            if node.child is None:
                return

            child = node.child
            while child is not None:
                rek(child.node, set, slovo+child.char)
                child = child.next
        rek(self.root, to_yield, "")
        # print(to_yield, "iter")
        yield from to_yield


if __name__ == '__main__':
    m = Repository()
    for w in 'mama ma emu a ema ma mamu'.split():
        try:
            m[w] = m[w] + 1
        except KeyError:
            m[w] = 1

    print(list(m), m.node_count(), len(m))
    # ww = list(m)
    # for w in ww:
    #     del m[w]
    #     print(w, m.node_count(), len(m))
