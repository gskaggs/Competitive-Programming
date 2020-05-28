def getline():
    return list(map(int, input().split()))

N = 10 ** 6 + 1
prime = [True] * N
prime[0] = prime[1] = False
div = [0] * N
square = set()

for i in range(2, N):
    if prime[i]:
        div[i] = 1
        for j in range(2*i, N, i):
            if j % (i*i) == 0:
                square.add(j)
            prime[j] = False
            div[j] += 1



mu = [0] * N
M = [0, 1]
mu[1] = 1

for i in range(2, N):
    if i not in square:
        mu[i] = 1 if not (div[i] & 1) else -1
    M.append(M[-1] + mu[i])


while True:
    cur = int(input())
    if cur == 0: break
    print(cur, mu[cur], M[cur]) 
