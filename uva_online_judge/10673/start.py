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


T = getint()
for _ in range(T):
    N, K = getline()
    euclid(int(floor(N/K)), int(ceil(N/K)))

    print(x * N//d, y * N//d)





