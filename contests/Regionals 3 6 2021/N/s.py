N = int(input())
n = [int(input()) for _ in range(N)]

n.sort()
res = 0
for lo in range(0, N):
    for hi in range(lo+2, N):
        count = 0
        for mid in range(lo+1, hi):
            if n[lo] + n[mid] > n[hi]:
                count += 1
        res += (2**count) - 1

print(res)

