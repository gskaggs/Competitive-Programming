import math
n = int(input())

def pow(p, n):
    if n == 0:
        return 1
    i = 1 
    res = 1

    i = int(math.log2(n)) + 1
    while i > 0:
        if res == 0:
            return 0
        res = (res**2) % 5
        if i & n:
            res *= p
        i >>= 1
        res %= 5

    return res 

def solve(i):
    return sum([pow(i, n) for i in range(1, 5)]) % 5

for i in range(32):
    print(pow(i, n))
