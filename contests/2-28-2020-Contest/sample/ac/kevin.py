class UnionFind:
    def __init__(self, r, c):
        self.r = r
        self.c = c
        self.uf = [[(i, j) for j in range(c)] for i in range(r)]
        self.developed = [[False for j in range(c)] for i in range(r)]
        
    def find(self, a, b):
        if self.uf[a][b] == (a, b):
            return (a, b)
        self.uf[a][b] = self.find(*self.uf[a][b])
        return self.uf[a][b]

    def union(self, a, b, c, d):
        u, v = self.find(c, d)
        self.uf[u][v] = self.find(a, b)

    def develop(self, a, b):
        self.developed[a][b] = True
        dxy = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dx, dy in dxy:
            x = min(max(a + dx, 0), self.r - 1)
            y = min(max(b + dy, 0), self.c - 1)
            if self.developed[x][y]:
                self.union(a, b, x, y)


def solve():
    n, m = map(int, input().split())
    union_find = UnionFind(n, m)
    slope_map = dict()
    start = (-1, -1)
    finish = (-1, -1)
    for i in range(n):
        row = list(map(int, input().split()))
        for j in range(m):
            if row[j] == 0:
                if start == (-1, -1):
                    start = (i, j)
                else:
                    finish = (i, j)
            slope_map[row[j]] = (i, j)
    union_find.develop(*start)
    union_find.develop(*finish)
    for i in range(n * m - 2 + 1):
        if i != 0:
            union_find.develop(*slope_map[i])
        if union_find.find(*start) == union_find.find(*finish):
            print(i)
            return
    assert False


solve()
