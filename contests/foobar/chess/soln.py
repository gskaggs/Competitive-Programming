def solution(src, dest):
    seen = [False] * 64
    
    from collections import deque 
    q = deque()
    q.append((src, 0))

    def inbounds(x, y):
        return x < 8 and y < 8 and x >= 0 and y >= 0

    def next_positions(pos):
        dx = [-2, -1, 1, 2, 2, 1, -1, -2]
        dy = [1, 2, 2, 1, -1, -2, -2, -1]
        x = pos // 8
        y = pos % 8
        res = []
        for i in range(len(dx)):
            xp, yp = x + dx[i], y + dy[i]
            if inbounds(xp, yp):
                res.append(8*xp + yp)
        return res

    while q.count > 0:
        cur = q.popleft()
        cur_pos = cur[0]
        dist = cur[1]

        if seen[cur_pos]:
            continue
        seen[cur_pos] = True

        if cur_pos == dest:
            return dist
        
        for next_pos in next_positions(cur_pos):
            q.append((next_pos, dist + 1))

    return -1