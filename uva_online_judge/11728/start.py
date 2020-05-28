from math import *
def getline(): return list(map(int, input().split()))
def getint(): return int(input())


N = 10**3 + 1
prime = [True]*N
prime[0] = prime[1] = False 
res = [1] * N
primes = []
mem = {}


for i in range(N):
    if prime[i]:
        res[i] = i+1
        primes.append(i)
        for j in range(2*i, N, i):
            prime[j] = False
            temp = j
            exp = 0
            while j % i == 0:
                j//=i
                exp += 1
            res[temp] *= (i**(exp+1) - 1) / (i-1)

    mem[res[i]] = i


count = 1
while True:
    cur = getint()
    if cur == 0: break

    print("Case {}: ".format(count), end="")

    if cur in mem:
        print(mem[cur])
    else:
        print(-1)
    count += 1




