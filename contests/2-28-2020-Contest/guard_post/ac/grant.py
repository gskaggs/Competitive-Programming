N = int(input())
l = []
for _ in range(N):
    A, B = map(int, input().split())
    l.append((A, B))
    
M = int(input())
for _ in range(M):
    A, B = map(int, input().split())
    l.append((A, B))
    
def func(pair):
    return pair[0]

l = sorted(l, key = func)

#print(l)

cur = l[0]

none, one, two = 0, 0, 0
for i in range(1, M+N):
    prev = cur
    cur = l[i]
    
    if cur[0] >= prev[1]:
        one += prev[1] - prev[0]
        none += cur[0] - prev[1]
    elif cur[1] > prev[1]:
        one += cur[0] - prev[0]
        two += prev[1] - cur[0]
        cur = (prev[1], cur[1])
    else:
        one += cur[0] - prev[0]
        two += cur[1] - cur[0]
        cur = (cur[1], prev[1])

one += cur[1] - cur[0]
print(none, one, two)
