N, P = list(map(int, input().split()))
M = 10 ** 9 + 7 

R = N
p = []

while R > 0:
    p.append(R % P)
    R = R // P

t = 0
n = [1] * len(p)

for i in range(len(p)):
    n[i] = p[i] * t + 1
    t = t * P + 1
    n[i] %= M

res = 1 
for i in range(len(p)):
    res *= n[i]
    res %= M

print(res)
