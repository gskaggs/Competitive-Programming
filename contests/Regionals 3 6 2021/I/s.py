N, K = map(int, input().split())

def trans(l):
    return [int(ord(a) - ord('A')) for a in l]

n = [trans(list(input())) for _ in range(N)]
    
adj = [[True] * K for _ in range(K)]

for i in range(K):
    adj[i][i] = False

for s in n:
    for i in range(K):
        for j in range(i+1, K):
            adj[s[j]][s[i]] = False

def dfs(u, adj, seen):
    if seen[u] != -1:
        return seen[u] 
    seen[u] = 0 
    next = [dfs(v, adj, seen) for v in range(K) if adj[u][v]]
    next.append(0)
    seen[u] = 1 + max(next)
    return seen[u]

res = 0
for u in range(K):
    seen = [-1] * K
    res = max(res, dfs(u, adj, seen))

print(res)
            
