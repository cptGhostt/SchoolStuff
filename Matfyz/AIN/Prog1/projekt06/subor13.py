import turtle
t = turtle.Turtle()
def trojuholnik():
    for repc in range(1, 4):
        t.fd(50)
        t.lt(120)
def stvorec():
    for repc in range(1, 5):
        t.fd(50)
        t.rt(90)
def dom():
    stvorec()
    trojuholnik()
    t.pu()
    t.fd(100)
    t.rt(45)
    t.pd()
for repc in range(1, 9):
    dom()
t.lt(90)
t.pu()
t.fd(300)
t.rt(90)
t.fd(-400)
t.pd()
for repc in range(1, 13):
    dom()
    t.lt(45)
    t.rt(repc)
    t.rt(repc)
turtle.done()
