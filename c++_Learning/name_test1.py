#yangkuang
#20202367029
#yang
import turtle as t
import time
t.speed(1)
t.pensize(10)
t.setup(650, 350, 100, 100) #构建画板
#一横
t.pencolor("red")
t.penup()
t.goto(-80, 0)
t.pendown()
t.fd(160)
#一竖
t.pencolor("blue")
t.penup()
t.goto(0, 80)
t.pendown()
t.right(90)
t.fd(280)
#一撇
t.pencolor("purple")
t.penup()
t.home()
t.pendown()
t.right(90)
t.circle(-100, 90)
#一捺
t.penup()
t.home()
t.pendown()
t.right(90)
t.circle(70, 90)
#反文旁
t.pencolor("yellow")
t.penup()
t.home() #调整方向和位置
t.penup()
t.goto(40, 40)
t.pendown()
t.fd(100)
t.right(140)
t.fd(80)
t.left(140) #方向向右
t.circle(-100, 120)
t.right(100)
t.fd(15)
#两撇
t.pencolor("brown")
t.penup()
t.home()
t.goto(80, -60)
t.pendown()
t.right(130)
t.fd(55)
t.penup()
t.goto(100, -80)
t.pendown()
t.fd(60)


