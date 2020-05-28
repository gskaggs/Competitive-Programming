from math import *
def getline(): return list(map(int, input().split()))
def getint(): return int(input())

N = 10 ** 5
prime = [True] * N
prime[0] = prime[1] = False
primes = []

for i in range(N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False




def isPrime(N):
    if N == 1:
        return False
    global primes
    for p in primes:
        if p * p > N:
            return True

        if N % p == 0:
            return False
        

while True:
    try:
        L, U = getline()
        prev = 0
        c1, c2, d1, d2 = [0]*4

        for i in range(L, U+1):
            if isPrime(i):
                if prev != 0:
                    if c2 == 0 or c2 - c1 > i - prev:
                        c2, c1 = i, prev
                    if d2 == 0 or d2 - d1 < i - prev:
                        d2, d1 = i, prev
                prev = i


        if c2 != 0: print("{},{} are closest, {},{} are most distant.".format(c1, c2, d1, d2))
        else: print("There are no adjacent primes.")

    except EOFError:
        break







