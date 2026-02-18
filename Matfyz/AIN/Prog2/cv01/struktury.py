class EmptyError(Exception):
    pass


class Stack:

    def __init__(self, postupnost=None):
        self._prvky = []
        if postupnost is not None:
            for i in postupnost:
                self.push(i)

    def __repr__(self):
        return f"Stack({tuple(self._prvky)})"

    def push(self, data):
        self._prvky.append(data)

    def pop(self):
        if self.is_empty():
            raise EmptyError('prazdny zasobnik')
        return self._prvky.pop()

    def top(self):
        if self.is_empty():
            raise EmptyError('prazdny zasobnik')
        return self._prvky[-1]

    def is_empty(self):
        return self._prvky == []


class Queue:

    def __init__(self, postupnost=None):
        self._prvky = []
        if postupnost is not None:
            for i in postupnost:
                self.enqueue(i)

    def __repr__(self):
        return f"Queue({tuple(self._prvky)})"

    def enqueue(self, data):
        self._prvky.append(data)

    def dequeue(self):
        if self.is_empty():
            raise EmptyError('prazdny rad')
        return self._prvky.pop(0)

    def front(self):
        if self.is_empty():
            raise EmptyError('prazdny rad')
        return self._prvky[0]

    def is_empty(self):
        return self._prvky == []


def postfix(vyraz):
    s = Stack()
    for prvok in vyraz.split():
        if prvok == '+':
            s.push(s.pop() + s.pop())
        elif prvok == '-':
            s.push(-s.pop() + s.pop())
        elif prvok == '*':
            s.push(s.pop() * s.pop())
        elif prvok == '/':
            op2 = s.pop()
            op1 = s.pop()
            s.push(op1 // op2)
        else:
            s.push(int(prvok))
    return s.pop()


def prefix(vyraz):
    s = Stack()
    for prvok in reversed(vyraz.split()):
        if prvok == '+':
            s.push(s.pop() + s.pop())
        elif prvok == '-':
            s.push(s.pop() - s.pop())
        elif prvok == '*':
            s.push(s.pop() * s.pop())
        elif prvok == '/':
            s.push(s.pop() // s.pop())
        else:
            s.push(int(prvok))
    return s.pop()
