import copy


def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)

# GCD of list


def GCDL(l):
    res = 0
    for x in l:
        res = GCD(res, x)
    return res


def LCM(a, b):
    return a * b // GCD(a, b)

# Adjust list l have denominator d


def expand(l, d):
    r = d // l[-1]
    for i in range(len(l)):
        l[i] *= r


def add(l1, l2):
    lcm = LCM(l1[-1], l2[-1])
    expand(l1, lcm)
    expand(l2, lcm)
    res = [0] * len(l1)
    res[-1] = lcm
    for i in range(len(l1)-1):
        res[i] = l1[i] + l2[i]
    return res

# Adjust list l to be multiplied by n / d


def multiply(l, n, d):
    for i in range(len(l)-1):
        l[i] *= n
    l[-1] *= d


def simplify(l):
    gcd = GCDL(l)
    for i in range(len(l)):
        l[i] //= gcd


# Handle cycles
def clean(res, u):
    res[-1] -= res[u]
    res[u] = 0


# Recursive soln
# Dest = terminal indices
# Stack = indices on the stack, used to detect cycles
def solve(u, dest, stack, table):
    res = [0] * (len(table))
    res.append(1)

    if u in dest or u in stack:
        res[u] = 1
        return res

    stack.add(u)
    denom = sum(table[u])
    for v in range(len(table)):
        cur = solve(v, dest, stack, table)
        multiply(cur, table[u][v], denom)
        simplify(cur)
        res = add(res, cur)

    clean(res, u)
    simplify(res)
    stack.remove(u)
    return copy.copy(res)


def solution(m):
    dest = dict()
    count = 0
    for i in range(len(m)):
        if all(x == 0 for x in m[i]):
            dest[i] = count
            count += 1

    stack = set()
    temp = solve(0, dest, stack, m)
    res = [0] * len(dest)
    for i in range(len(m)):
        if i in dest:
            res[dest[i]] = temp[i]
    res.append(temp[-1])
    return res
