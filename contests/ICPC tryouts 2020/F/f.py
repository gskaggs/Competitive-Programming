N, M, I = list(map(int, input().split()))

G = []
for i in range(N):
    G.append(list(input()))

delta = [(0, 1), (-1, 0), (1, 0), (0, -1)]

outlet = [[False] * M for _ in range(N)]


def out_bounds(i, j):
    return i < 0 or j < 0 or i >= N or j >= M


def dfs(i, j, d):
    global G, delta, outlet
    if d > 2 or out_bounds(i, j):
        return
    outlet[i][j] = True
    for dx, dy in delta:
        dfs(i+dx, j+dy, d+1)


for i in range(N):
    for j in range(M):
        if G[i][j] == '*':
            dfs(i, j, 0)


def next_to_opp(i, j, c):
    global G
    for dx, dy in delta:
        if not out_bounds(i+dx, j+dy):
            cur = G[i+dx][j+dy]
            if cur >= 'a' and cur <= 'z' and cur != c:
                return True
    return False


def process(i, j, moves):
    global G, delta
    for dx, dy in delta:
        x, y = i + dx, j + dy
        if out_bounds(x, y) or next_to_opp(x, y, G[i][j]):
            continue
        if G[x][y] == '#' and outlet[x][y]:
            if (x, y) in moves:
                moves[(x, y)] = (-1, -1)
            else:
                moves[(x, y)] = (i, j)
            return


for _ in range(I):
    moves = {}
    for i in range(N):
        for j in range(M):
            cur = G[i][j]
            if cur >= 'a' and cur <= 'z':
                process(i, j, moves)

    for m in moves:
        if moves[m] == (-1, -1):
            continue
        x, y = m
        i, j = moves[m]
        G[x][y] = G[i][j]
        G[i][j] = '#'

for l in G:
    print(''.join(l))
