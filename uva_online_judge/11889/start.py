def getline():
    return list(map(int, input().split()))

N = 10**4
prime = [True] * N
primes = []
prime[0] = prime[1] = False

for i in range(2, N):
    if prime[i]:
        for j in range(i * i, N, i):
            prime[j] = False
        primes.append(i)


def primeFacts(N):
    global primes
    i = 0
    PF = primes[i]
    res = {}

    while PF * PF <= N:
        exp = 0
        while N % PF == 0:
            N //= PF
            exp += 1
            res[PF] = exp

        i += 1
        PF = primes[i]

    if N > 1:
        res[N] = 1

    return res


T = int(input())
for _ in range(T):
    A, C = map(int, input().split())
    factA = primeFacts(A)
    factC = primeFacts(C)
    res = 1
    exists = True
    
    for key in factA:
        if key not in factC or factA[key] > factC[key]:
            exists = False
            break
        if factA[key] < factC[key]: res *= key ** factC[key]
        del factC[key]

    for key in factC:
        res *= key ** factC[key]

    if exists: print(res)
    else: print("NO SOLUTION")




