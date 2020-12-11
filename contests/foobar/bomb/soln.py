def solution(x, y):
    res = 0
    x, y = int(x), int(y)

    while x > 0 and y > 0:
        res += x // y
        x %= y
        x, y = y, x

    if x in [1, 0] and y in [1, 0]:
        return str(res - 1)
    return "impossible"
