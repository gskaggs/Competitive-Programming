
N = 10**5
prime = [True] * N
prime[0] = prime[1] = False 
primes = []


for i in range(N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False

n = int(input())

def solve(n):
    for p in primes:
        if n % p  == 0:
            return (n // p, n - n//p)
    return (1, n - 1)

res = solve(n)
print(res[0], res[1])
