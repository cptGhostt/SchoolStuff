import turtle
t = turtle.Turtle()
def jedna():
    t.pensize(repc)
    t.fd(5+repc)
def dva():
    t.pu()
    t.fd(25)
    t.pd()
    t.rt(15)
for repc in range(1, 25):
    for repc in range(1, 5):
        jedna()
        t.rt(90)
    dva()
turtle.done()
