# 8. zadanie: min_sort
# autor: Peter Kendra
# datum: 27.04.2024

class LinkedList:
    class Node:
        def __init__(self, data, next=None):
            self.data, self.next = data, next

    def __init__(self, seq):
        self.front = self.Node(None)

        zoz = self.front
        for i in seq:
            zoz.next = self.Node(i)
            zoz = zoz.next

        # laco = self.front
        # while laco:
        #     print(laco.data, end=" ")
        #     laco = laco.next
        # print()

    def progress(self, first, reverse):
        if reverse:
            zoz = first.next.next
            prev = first.next

            while zoz:
                if zoz.data > first.next.data:
                    tmp = zoz.next
                    prev.next = first.next
                    prev = first.next
                    zoz.next = first.next.next
                    first.next.next = tmp
                    first.next = zoz
                    zoz = tmp
                else:
                    prev = zoz
                    zoz = zoz.next
        else:
            zoz = first.next.next
            prev = first.next

            while zoz:
                if zoz.data < first.next.data:
                    tmp = zoz.next
                    prev.next = first.next
                    prev = first.next
                    zoz.next = first.next.next
                    first.next.next = tmp
                    first.next = zoz
                    zoz = tmp
                else:
                    prev = zoz
                    zoz = zoz.next
                laco = self.front
                while laco:
                    print(laco.data, end=" ")
                    laco = laco.next
                print()

    def min_sort(self, reverse):
        first = self.front
        while first.next is not None:
            self.progress(first, reverse)
            first = first.next

    def get_list(self):
        to_ret = []
        zoz = self.front.next
        while zoz is not None:
            to_ret.append(zoz.data)
            zoz = zoz.next
        return to_ret


def min_sort(seq, reverse=False):
    # return sorted(seq, reverse=reverse)
    ll = LinkedList(seq)
    ll.min_sort(reverse)
    return ll.get_list()


if __name__ == '__main__':
    # seq = (4, 30, 8, 31, 48, 19)
    # lst = min_sort(seq)
    # print(lst)

    z = LinkedList([41, 44, 42, 43, 41, 43, 42, 43, 44, 42, 41, 40, 40, 44, 42, 41, 44, 41, 42, 42, 42, 44, 42, 41, 43, 44, 40, 40, 44, 44, 44, 43, 41, 41, 42, 43, 41, 44, 40, 43, 43, 42, 43, 44, 41, 44, 40, 44, 40, 42, 40, 42, 40, 41, 44, 40, 43, 41, 43, 43, 43, 41, 42, 43, 41, 44, 43, 41, 40, 43, 44, 44, 43, 40, 42, 42, 41, 43, 44, 40, 41, 44, 43, 44, 40, 40, 44, 41, 42, 41, 41, 42, 41, 44, 41, 42, 42, 44, 42, 43, 41, 44, 42, 43, 43, 40, 41, 44, 43, 41, 42, 40, 40, 40, 44, 40, 44, 42, 41, 40, 44, 42, 44, 42, 43, 44, 42, 44, 42, 40, 40, 43, 43, 42, 42, 44, 43, 42, 44, 43, 40, 43, 43, 41, 44, 40, 42, 44, 44, 41, 43, 44, 44, 43, 42, 41, 43, 44, 44, 41, 42, 44, 40, 43, 44, 43, 43, 42, 44, 44, 40, 43, 41, 42, 40, 43, 41, 43, 42, 41, 40, 44, 40, 42, 42, 43, 44, 42, 41, 43, 42, 43, 41, 43, 44, 40, 42, 44, 40, 44, 43, 40, 42, 40, 43, 40, 41, 44, 41, 40, 43, 42, 44, 42, 41, 44, 41, 41, 42, 42, 40, 40, 44, 42, 43, 44, 44, 40, 41, 42, 44, 42, 42, 44, 41, 43, 44, 43, 41, 43, 42, 44, 42, 41, 42, 44, 41, 40, 44, 43, 42, 43, 41, 42, 41, 40, 41, 44, 43, 44, 41, 44, 42, 43, 44, 41, 41, 41, 43, 42, 42, 43, 41, 40, 41, 42, 40, 40, 41, 43, 42, 43, 40, 41, 40, 40, 44, 40, 41, 40, 43, 44, 44, 43, 42, 42, 40, 44, 41, 40, 41, 43, 41, 43, 43, 43, 41, 41, 41, 42, 43, 44, 44, 43, 41, 43, 42, 42, 43, 44, 40, 41, 40, 40, 40, 40, 43, 42, 43, 44, 42, 41, 43, 41, 41, 40, 40, 43, 41, 44, 40, 44, 43, 42, 41, 40, 43, 42, 40, 40, 44, 40, 44, 41, 40, 42, 40, 43, 40, 41, 40, 43, 41, 42, 41, 43, 43, 42, 42, 42, 41, 41, 40, 44, 44, 41, 42, 43, 44, 44, 44, 40, 42, 44, 43, 44, 41, 44, 43, 40, 42, 44, 40, 42, 41, 40, 41, 40, 41, 43, 40, 40, 40, 44, 43, 44, 42, 40, 42, 40, 41, 44, 40, 43, 41, 43, 43, 40, 44, 42, 40, 42, 42, 40, 42, 40, 43, 40, 42, 42, 41, 42, 43, 40, 42, 40, 43, 41, 44, 44, 41, 42, 42, 44, 43, 44, 43, 40, 41, 43, 44, 44, 44, 44, 44, 40, 42, 41, 41, 42, 43, 44, 42, 40, 43, 42, 41, 44, 40, 40, 42, 44, 42, 43, 42, 42, 42, 42, 42, 44, 44, 40, 44, 40, 41, 42, 42, 42, 44, 40, 43, 42, 43, 43, 42, 43, 40])
    z.min_sort(True)
    print(z.get_list())

    # lst = min_sort(seq, reverse=True)
    # print(lst)
