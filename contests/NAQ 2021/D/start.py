w, _ = map(int, input().split())
p = [0]
p.extend(list(map(int, input().split())))
p.append(w)

n = len(p)
res = set()
for i in range(n):
    for j in range(i+1, n):
        res.add(p[j] - p[i])

res = list(res)
res.sort()


for i, x in enumerate(res):
    end = '\n' if i == len(res) -1 else ' '
    print(x, end=end)

