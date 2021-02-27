C, R = map(int, input().split())
INF = 10 ** 9
d = input()
d = [ int(x) + 1 for x in d ]
N = len(d)

g = []
for _ in range(R):
    g.append(list(map(int, list(input()))))
g.reverse()

# dp [i, j, s] = best you can do at location i,j having used s digits
dp = [[ [0] * (N+1) for _ in range(C) ] for _ in range(R) ]

for i in range(R):
    for j in range(C):
        for s in range(N+1):
            cur = []
            if i > 0:
                cur.append(dp[i-1][j][s])
            if j > 0:
                cur.append(dp[i][j-1][s])
            if s > 0:
                delta = d[s-1]
                if i - delta >= 0:
                    cur.append(dp[i - delta][j][s-1])
                if j - delta >= 0:
                    cur.append(dp[i][j - delta][s-1])
            if len(cur) > 0:
                dp[i][j][s] = min(cur) + g[i][j]
            else:
                dp[i][j][s] = INF if s > 0 else g[i][j]


print(min(dp[R-1][C-1]))
