import turtle
t = turtle.Turtle()
def test():
    t.fd(10)
    def test2():
        t.fd(10)
        t.fd(repc)
        t.lt(30)
    t.rt(90)
    for repc in range(1, 51):
        test2()
for repc in range(1, 6):
    test()
    t.rt(45)
turtle.done()
