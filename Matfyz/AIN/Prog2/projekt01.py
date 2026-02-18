# 1. zadanie: vyraz
# autor: Peter Kendra
# datum: 25.2.2024


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


class Expression:
    def __init__(self):
        self.tab = {}

    def __repr__(self):
        to_ret = ""

        for i in self.tab:
            to_ret += f"{i}: '{self.tab[i]}'\n"

        return to_ret.strip()

    def to_prefix(self, expr):
        specials = ("+", "-", "*", "/", "%", "(", ")")

        for i in specials:
            expr = expr.replace(i, " " + i + " ")

        while expr.find("  ") > 0:
            expr = expr.replace("  ", " ")
        expr = expr.strip()

        # if prefix
        if expr[0] in specials[:5]:
            return expr
        # if postfix
        elif expr[-1] in specials[:5]:
            s = Stack()

            for i in expr.split():
                if i not in specials:
                    s.push(i)
                else:
                    tmp1 = s.pop()
                    tmp2 = s.pop()
                    s.push(i + " " + tmp2 + " " + tmp1)
            return s.pop()
        # if infix
        else:
            priorities = {")": 0,
                          "+": 1, "-": 1,
                          "*": 2, "/": 2, "%": 2}
            s = Stack()
            prefix = ""

            for i in reversed(expr.split()):
                if i not in specials:
                    prefix += " " + i + " "
                elif i == ")":
                    s.push(i)
                elif i == "(":
                    tmp = s.pop()
                    while tmp != ")":
                        prefix += " " + tmp + " "
                        tmp = s.pop()
                else:
                    if s.is_empty():
                        s.push(i)
                    else:
                        if priorities[i] < priorities[s.top()]:
                            while not s.is_empty() and priorities[i] < priorities[s.top()]:
                                prefix += " " + s.pop() + " "
                            s.push(i)
                        else:
                            s.push(i)

            while not s.is_empty():
                prefix += " " + s.pop() + " "

            to_ret = ""
            for i in reversed(prefix.split()):
                to_ret += i + " "
            return to_ret.strip()

    def assign(self, var, expr):
        self.tab[var] = self.to_prefix(expr)

    def evaluate(self, expr):
        try:
            tmp = self.to_prefix(expr)
            to_ret = self.prefix(tmp)
            return to_ret
        except EmptyError:
            return None

    def prefix(self, expr):
        s = Stack()
        for prvok in reversed(expr.split()):
            if prvok == '+':
                try:
                    s.push(s.pop() + s.pop())
                except TypeError:
                    return None
            elif prvok == '-':
                try:
                    s.push(s.pop() - s.pop())
                except TypeError:
                    return None
            elif prvok == '*':
                try:
                    s.push(s.pop() * s.pop())
                except TypeError:
                    return None
            elif prvok == '/':
                try:
                    s.push(s.pop() // s.pop())
                except (TypeError, ZeroDivisionError):
                    return None
            elif prvok == "%":
                try:
                    s.push(s.pop() % s.pop())
                except (TypeError, ZeroDivisionError):
                    return None
            else:
                try:
                    s.push(int(prvok))
                except ValueError:
                    try:
                        tmp = self.tab[prvok]
                    except KeyError:
                        return None
                    to_push = self.evaluate(tmp)
                    s.push(to_push)
        return s.pop()


if __name__ == '__main__':
    e = Expression()
    e.assign('x', 'y*(y-1)')
    e.assign('y', '3+4*5')
    print(e)
    print('x =', e.evaluate('x'))
    print('y =', e.evaluate('y'))
    e.assign('y', '9*9%6')
    print(e)
    for name in e.tab:
        print(name, '=', e.evaluate(name))

