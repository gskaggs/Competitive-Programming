from math import *

while True:
    l = list(map(int, input().split()))
    l.pop()
    if len(l) == 0: break

    first = l[0]
    for i in range(len(l)):
        l[i] -= first

    res = abs(l[1])
    for i in range(2, len(l)):
        res = gcd(l[i], res)

    print(res)
