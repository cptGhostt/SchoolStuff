# 5. zadanie: binarny strom
# autor: Peter Kendra
# datum: 30.03.2024

class Node:
    def __init__(self, data, left=None, right=None):
        self.data, self.left, self.right = data, left, right

    def __repr__(self):
        return f'Vrchol({self.data!r}, {self.left}, {self.right})'


def add_node(root, string):
    values = string.split(":")

    if root is None:
        root = Node(None)
    if len(values) == 1 or values[1] == "":
        root.data = values[0]
        return root

    values[1] = values[1].lower()
    tmp = root
    for i in values[1]:
        if i == "l":
            if tmp.left is not None:
                tmp = tmp.left
            else:
                tmp.left = Node(None)
                tmp = tmp.left
        elif i == "r":
            if tmp.right is not None:
                tmp = tmp.right
            else:
                tmp.right = Node(None)
                tmp = tmp.right

    tmp.data = values[0]
    return root


def create_tree(file_name):
    with open(file_name, "r") as f:
        root = None
        line = f.readline()
        while line != "":
            root = add_node(root, line)
            line = f.readline()
    return root


def write_tree_to_file(root, file_name):
    with open(file_name, "w") as f:

        def rek(vrch, cesta):
            if vrch is None:
                return

            if vrch.data is not None:
                print(vrch.data + ":" + cesta, file=f)
            rek(vrch.left, cesta + "l")
            rek(vrch.right, cesta + "r")
        rek(root, "")


def most_frequent(root):
    if root is None:
        return None
    values = {}

    def rek(vrch):
        if vrch is None:
            return

        if vrch.data is not None:
            if vrch.data in values:
                values[vrch.data] += 1
            else:
                values[vrch.data] = 1
        rek(vrch.left)
        rek(vrch.right)
    rek(root)

    tmp = 0
    to_ret = ""
    for i in values:
        if values[i] > tmp:
            to_ret = str(i)
            tmp = values[i]
    return to_ret


def number(root):
    to_ret = [0, 0]

    def rek(vrch):
        if vrch is None:
            return

        to_ret[1] += 1
        if vrch.data is not None:
            to_ret[0] += 1
        rek(vrch.left)
        rek(vrch.right)
    rek(root)
    return tuple(to_ret)


if __name__ == '__main__':
    # s = add_node(None, 'a:rxl l')
    # s = add_node(s, 'b:rl')
    # s = add_node(s, 'c:LL')
    # write_tree_to_file(s, 'strom1.txt')
    # t = create_tree('strom1.txt')
    # print(number(t))
    # t = add_node(t, 'x')
    # t = add_node(t, 'd:' + 'lr'*10)
    # write_tree_to_file(t, 'strom2.txt')
    # print('subor strom1.txt')
    # print(open('strom1.txt').read())
    # print('subor strom2.txt')
    # print(open('strom2.txt').read())
    print(create_tree("empty.txt"))
