
N = 10 ** 6 + 1
prime = [True] * N
prime[0] = prime[1] = False
res = [1] * N


for i in range(2, N):
    if prime[i]:
        for j in range(i*i, N, i):
            prime[j] = False
        j = i
        while j <= N:
            res[j] = i 
            j *= i

    res[i] *= res[i-1]
    while res[i] % 10 == 0:
        res[i] //= 10
    res[i] %= 1000000000


while True:
    N = int(input())
    if N == 0:
        break
    print(res[N] % 10)



