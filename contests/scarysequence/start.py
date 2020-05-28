def dot(A, B, i, j):
    cur = 0
    global K
    for a in range(K):
        cur += (A[i][a] * B[a][j])
    return cur
    
    
N, K = map(int, input().split())
A = list(map(int, input().split()))

TM = []
TM.append(A)
for i in range(0, K-1):
    cur = [0]*K
    cur[i] = 1
    TM.append(cur)

res = []
for i in range(K):
    cur = [0]*K
    cur[i] = 1
    res.append(cur)

while (N):
    if (N & 1): 
        tmp = [[0 for x in range(K)] for y in range(K)]; 
        for i in range(K):
            for j in range(K):
                tmp[i][j] = dot(res, TM, i, j)
        
        for i in range(K):
            for j in range(K):
                res[i][j] = tmp[i][j]

    N //=2
    tmp = [[0 for x in range(K)] for y in range(K)]; 
    for i in range(K):
        for j in range(K):
            tmp[i][j] = dot(TM, TM, i, j)
    
    for i in range(K):
        for j in range(K):
            TM[i][j] = tmp[i][j]

print(sum(res[0]))
