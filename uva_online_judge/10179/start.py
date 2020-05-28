def getline(): return list(map(int, input().split()))
def getint(): return int(input())

N = 10 ** 5
prime = [True] * N
prime[0] = prime[1] = False
primes = []

for i in range(2, N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False

def euler(N):
    global primes
    x = 0
    PF = primes[x]
    res = N

    while PF * PF <= N:
        exp = 0 
        while N % PF == 0:
            N //= PF
            exp += 1

        if exp > 0:
            res = res - res // PF
        
        x += 1
        PF = primes[x]

    if N > 1: res = res - res // N

    return res



while True:
    N = getint()
    if N == 0: break
    print(euler(N))








