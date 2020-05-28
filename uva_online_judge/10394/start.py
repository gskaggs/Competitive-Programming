from math import *
def getline(): return list(map(int, input().split()))
def getint(): return int(input())

N = 20000000
prime = [True] * N
prime[0] = prime[1] = False
prev = 2
twins = []

for i in range(N):
    if prime[i]:
        if i - prev == 2:
            twins.append((prev, i))
        prev = i
        for j in range(i*i, N, i):
            prime[j] = False


while True:
    try:
        N = getint()
        print("({}, {})".format(twins[N-1][0], twins[N-1][1]))
    except EOFError:
        break


