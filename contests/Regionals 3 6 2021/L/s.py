l = list(input())
u = list(input())
l, u = list(map(int, l)), list(map(int, u))

pow = [1]
M = 998244353
for _ in range(max(10**4, len(u))):
    pow.append((pow[-1] * 9) % M)

def RNT(n):
    if n <= 0:
        return 0
    res = 0
    for i in range(1, n+1):
        res += pow[i]
        res %= M
    return res 

def RN(n, k):
    start = n[k]
    if k == 0:
        start -= 1
    if k > 0 and n[k-1] < n[k]:
        start -= 1
    return start * pow[len(n) - k - 1]

def RNN(n):
    res = RNT(len(n)-1)
    for k in range(len(n)):
        res += RN(n, k)
        res %= M
        if k > 0 and n[k] == n[k-1]:
            break
    return res

def isRN(u):
    for k in range(1, len(u)):
        if u[k] == u[k-1]:
            return False
    return True


res = RNN(u) - RNN(l) 
if isRN(u):
    res += 1

print((res+M) % M)

