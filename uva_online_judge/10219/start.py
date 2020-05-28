from math import *

def getline():
    return list(map(int, input().split()))

def choose(n, k):
    k = max(n-k, k)
    res = 0 
    for i in range(n, k, -1):
        res += log10(i) 
    for i in range(1, n-k+1):
        res -= log10(i) 
    return res

while True:
    try:
        n, k = getline()
        print(int(floor(choose(n, k)) + 1))
    
    except EOFError:
        break



