N, K, P = input().split()
N = int(N)
K = int(K)
P = float(P)
M = 1000

C = [[0] * M for _ in range(M)]
P, Q = [P ** R for R in range(M)], [(1-P) ** R for R in range(M)]


C[0][0] = 1
for i in range(1, M):
    C[i][0] = 1
    for j in range(1, i):
        C[i][j] = C[i-1][j-1] + C[i-1][j]
    C[i][i] = 1


def alive(R):
    global P, K, Q
    if R < K:
        return 1
    res = 0
    for k in range(K):
        res += C[R][k] * P[R-k] * Q[k]
    return res


def solve():
    global N
    res = 0
    for R in range(M):
        a = alive(R)
        # print(a)
        res += a * ((1 - a) ** (N-1))
    return res


print(solve())
