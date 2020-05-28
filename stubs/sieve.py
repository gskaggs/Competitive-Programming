

N = 10**5
prime = [True] * N
prime[0] = prime[1] = False 
primes = []


for i in range(N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False
