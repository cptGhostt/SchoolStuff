import turtle
t = turtle.Turtle()
def obluk():
    for repc in range(1, 10):
        t.fd(9)
        t.lt(10)
def lupen():
    obluk()
    t.lt(90)
    obluk()
    t.lt(90)
def kvet():
    for repc in range(1, 11):
        lupen()
        t.rt(36)
kvet()
t.pu()
t.fd(150)
t.pd()
t.lt(30)
for repc in range(1, 201):
    t.fd(repc)
    t.fd(repc)
    t.rt(91)
turtle.done()
