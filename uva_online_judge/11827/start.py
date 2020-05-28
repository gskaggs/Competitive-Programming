from math import *

def maxGCD(l):
    if len(l) == 1: return l[0]
    best = gcd(l[0], l[1])
    for i in range(2, len(l)):
        for j in range(0, i):
            best = max(best, gcd(l[i], l[j]))
    return best



N = int(input())
for _ in range(N):
    l = list(map(int, input().split()))
    print(maxGCD(l))
