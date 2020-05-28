def getline():
    return list(map(int, input().split()))

N = 10 ** 5 + 1
prime = [True] * N
prime[0] = prime[1] = False
primes = []

for i in range(2, N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False

def div(N):
    x = 0
    PF = primes[x]
    res = 1

    while PF * PF <= N:
        exp = 0 
        while N % PF == 0:
            N //= PF
            exp += 1
        res *= exp + 1

        x += 1
        PF = primes[x]

    if N > 1:
        res *= 2

    return res


T = int(input())
for i in range(T):
    L, U = getline()

    best = div(L)
    best_id = L
    for i in range(L+1, U+1):
        cur = div(i)
        if best < cur:
            best = cur 
            best_id = i

    print("Between {} and {}, {} has a maximum of {} divisors.".format(L, U, best_id, best))





