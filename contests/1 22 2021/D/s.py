p = tuple(map(int, input().split()))
q = tuple(map(int, input().split()))
E = int(input())

if q < p:
    p, q = q, p

def diff(a, b):
    return (a[0] - b[0] ) / (a[1] - b[1])

def eq(a, b):
    return abs(a - b) < 0.000001

def block(e, p, q):
    if e < p or e > q:
        return False

    return eq(diff(p, e), diff(q, e))

for _ in range(E):
    e = tuple(map(int, input().split()))
    if block(e, p, q):
        print('Yes')
    else:
        print('No')
