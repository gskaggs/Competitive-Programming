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
    N = getint()
    if N == 0: break
    c1, n1 = getline()
    c2, n2 = getline()
    
    euclid(n1, n2)

    N1 = int(ceil(-1*x*N/n2))
    N2 = int(floor(y*N/n1))

    if N1 > N2 or N % d != 0:
        print("failed")
        continue
    
    
    cost1 = (N//d) * (c1*x + c2*y) + N1 * (c1*n2-c2*n1) // d
    cost2 = (N//d) * (c1*x + c2*y) + N2 * (c1*n2-c2*n1) // d
    T = N1 if cost1 < cost2 else N2

    res1, res2 = (x*N + n2*T) // d , (y*N - n1*T) // d

    print(res1, res2)







