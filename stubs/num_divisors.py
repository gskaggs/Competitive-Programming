
N = 10**5
prime = [True] * N
prime[0] = prime[1] = False 
primes = []


for i in range(N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False


def num_divisors(N):
    global primes
    res, x = 1, 0
    PF = primes[x]

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
        

while True:
    N = int(input())
    if N == 0: break
    print(num_divisors(N))
