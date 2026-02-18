import turtle
t = turtle.Turtle()
t.pencolor("#ff0077")
t.pensize(15)
for repc in range(1, 21):
    t.fd(repc)
t.pencolor('indian red')
for repc in range(1, 31):
    t.pensize(15-repc//2)
    t.rt(90)
    t.fd(100+10*repc)
turtle.done()
