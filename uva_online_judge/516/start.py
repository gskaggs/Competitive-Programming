
N = 40000
prime = [True] * N
primes = []
prime[0] = False
prime[1] = False

for i in range(2, N):
    if prime[i]:
        for j in range(i * i, N, i):
            prime[j] = False
        primes.append(i)

def primeFact(N):
    global primes
    i = 0
    PF = primes[i]
    res = []

    while PF * PF <= N:
        exp = 0
        while N % PF == 0:
            N //= PF
            exp += 1

        if exp != 0:
            res.append(exp)
            res.append(PF)
        
        i += 1
        PF = primes[i]

    if N > 1:
        res.append(1)
        res.append(N)

    return res[::-1]
        
while True:
    l = list(map(int, input().split()))
    if (l[0] == 0): break
    
    cur = 1
    for i in range(0, len(l), 2):
        cur *= l[i] ** l[i+1]
    cur -= 1
    
    res = primeFact(cur)
    for i in range(0, len(res), 2):
        e = "" if i == len(res)-2 else " "
        print(res[i], res[i+1], end=e)
    print("")





