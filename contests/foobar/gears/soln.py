def solution(pegs):
    # As we traverse the pegs we'll keep track of
    # cur[0] = coefficent on x
    # cur[1] = constant term
    # That is, peg[i] = cur[0] * x + cur[1] at iteration i
    cur = (1, 0)
    for i in range(1, len(pegs)):
        gap = pegs[i] - pegs[i-1]
        cur = (-cur[0], gap - cur[1])

    # Multiply by 2 since final peg = 2 * x
    x = (2 * cur[0], 2 * cur[1])

    a = x[1]
    b = 1 - x[0]

    def gcd(a, b):
        if b == 0:
            return a
        return gcd(b, a % b)

    a, b = a // gcd(a, b), b // gcd(a, b)
    if a <= 0 or b <= 0:
        return [-1, -1]

    # Make sure all the pegs are valid
    cur = a / b
    for i in range(1, len(pegs)):
        gap = pegs[i] - pegs[i-1]
        cur = gap - cur
        if cur <= 0:
            return[-1, -1]

    return [a, b]
