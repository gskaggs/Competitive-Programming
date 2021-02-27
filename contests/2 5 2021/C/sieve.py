N = 10**5
prime = [True] * N
prime[0] = prime[1] = False 
primes = []


for i in range(N):
    if prime[i]:
        primes.append(i)
        for j in range(i*i, N, i):
            prime[j] = False

def winning(n, f, s):
    pows = {}

    for p in primes:
        while n % p == 0:
            if not p in pows:
                pows[p] = 0
            n //= p
            pows[p] += 1

    if n > 1:
        pows[n] = 1
        
    pows = list(pows.values())
    pows.sort()
    
    if len(pows) == 1:
        return f if bool(pows[0] % 2) else s
    if len(pows) == 2 and pows[1] - pows[0] <= 1:
        return f if pows[1] > pows[0] else s
    else:
        return 'tie' 

def solve():
    n, f = input().split()
    n = int(n)
    s = 'Alice' if f == 'Bob' else 'Bob'
    print(winning(n, f, s))

T = int(input())
for _ in range(T):
    solve()
