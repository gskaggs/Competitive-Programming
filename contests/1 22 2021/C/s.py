s = int(input())

def too_big(x, s):
    return x**3 * (153) > s

lo = 0
hi = 10**8

for _ in range(2000):
    mid = (lo + hi) / 2
    if too_big(mid, s):
        hi = mid
    else:
        lo = mid

print(lo)
