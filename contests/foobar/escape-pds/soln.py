'''
This was a classic MaxFlow / MinCut problem. What follows is a Python implementation 
of Dinic's Algorithm which runs in O(VE^2). Since the algorithm is a classic of competitive programming 
and can be easily referenced in CLRS or any other algorithms textbook, I felt justified in copying this code
with minimal modification from https://github.com/anxiaonong/Maxflow-Algorithms/blob/master/Dinic's%20Algorithm.py 

Of course, understanding how / when to apply the algorithm for this problem was my own work.
'''


# Build level graph by using BFS
def BFS(C, F, s, t):  # C is the capacity matrix
    n = len(C)
    queue = []
    queue.append(s)
    global level
    level = n * [0]  # initialization
    level[s] = 1
    while queue:
        k = queue.pop(0)
        for i in range(n):
            if (F[k][i] < C[k][i]) and (level[i] == 0):  # not visited
                level[i] = level[k] + 1
                queue.append(i)
    return level[t] > 0


# Search augmenting path by using DFS
def DFS(C, F, k, cp):
    tmp = cp
    if k == len(C)-1:
        return cp
    for i in range(len(C)):
        if (level[i] == level[k] + 1) and (F[k][i] < C[k][i]):
            f = DFS(C, F, i, min(tmp, C[k][i] - F[k][i]))
            F[k][i] = F[k][i] + f
            F[i][k] = F[i][k] - f
            tmp = tmp - f
    return cp - tmp


# Run max flow
def solve(C, s, t):
    n = len(C)
    F = [n*[0] for i in range(n)]  # F is the flow matrix
    flow = 0
    while(BFS(C, F, s, t)):
        flow = flow + DFS(C, F, s, 100000)
    return flow


def solution(entrances, exits, path):
    # Add a source and sink with infinite capacity
    INF = 10**9 + 1
    source_row = [INF if i in entrances else 0 for i in range(len(path))]
    sink_row = len(path) * [0]
    path.extend([source_row, sink_row])

    for i in range(len(path)):
        if i in exits:
            path[i].extend([0, INF])
        else:
            path[i].extend([0, 0])

    return solve(path, len(path)-2, len(path)-1)
