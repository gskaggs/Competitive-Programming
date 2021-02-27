k, m, n = map(int, input().split())

k = k % (m + n)
res = 'Barb' if k < m else 'Alex'
print(res)

