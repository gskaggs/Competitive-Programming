from math import *
def getline(): return list(map(int, input().split()))
def getint(): return int(input())

def euclid(a, b):
    global x, y, d
    if b == 0:
        x, y, d = 1, 0, a
        return

    euclid(b, a%b)
    x, y = y, x - (a // b) * y


x, y, d = 0, 0, 0

while True:
    try:
        A, B = getline()
        euclid(A, B)

        resx, resy = x, y
        t = 1
        if x > 0:
            t = -1

        while abs(x) + abs(y) <= abs(resx) + abs(resy):
            if abs(x) + abs(y) < abs(resx) + abs(resy) or x <= y:
                resx, resy = x, y

            x += t * (B // d)
            y += -1 * t * (A // d)

        print(resx, resy, d)

        

    except EOFError:
        break





