N, M = map(int, input().split())
uid = 0
mp = {}
m = [int(input()) for _ in range(M)]

for n in m:
    if n in mp:
        continue
    mp[n] = uid
    uid += 1

L = [0] * uid
count = 1
for n in m:
    for i in range(uid):
        L[i] += 1
    L[mp[n]] = 0
    x = (N - uid) * (count)
    print(sum(L) + x)
    count += 1

