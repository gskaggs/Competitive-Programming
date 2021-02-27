n = int(input())
points = []
eps = 10e-5

for _ in range(n):
    points.append(tuple(map(int, input().split())))

def line(a, b):
    if b[0] == a[0]:
        return a[0], a[1], None
    return (a[0], a[1], (a[1] - b[1]) / (a[0] - b[0]))

def onLine(l, x, y):
    px, py, m = l
    if m == None:
        return x == px
    return abs((y - py) - m * (x - px)) < eps

def colinear(points):
    l = line(points[0], points[1])
    return all([onLine(l, x, y) for x, y in points])

def isSoln(points, a, b):
    l = line(points[a], points[b])

    remaining = [(x, y) for x, y in points if not onLine(l, x, y)]

    return len(remaining) <= 2 or colinear(remaining)

def solve(points):
    if (len(points) < 4):
        return True

    return isSoln(points, 0, 1) or isSoln(points, 0, 2) or isSoln(points, 1, 2)

res = 'success' if solve(points) else 'failure'
print(res)
