from math import *
def getline(): return list(map(int, input().split()))
def getint(): return int(input())

N = 25
X = 150
dp = [[0]*X for i in range(N)]

for i in range(1, 7):
    dp[1][i] = 1

for i in range(2, N):
    for j in range(1, X):
        cur = 0
        for k in range(1, 7):
            if j - k > 0:
                cur += dp[i-1][j-k]
        dp[i][j] = cur


for i in range(N):
    for j in range(X-2, -1, -1):
        dp[i][j] += dp[i][j+1] 



while True:
    n, x = getline()
    if (n + x == 0): break

    nom = dp[n][x]
    den = 6 ** n
    d = gcd(nom, den)
    
    if nom == den: print(1)
    elif nom == 0: print(0)
    else:
        print("{}/{}".format(nom//d, den//d))





