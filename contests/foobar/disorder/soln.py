# Get the next partition in order
# p is the current partion, k keeps track of the last non-zero index
# Taken from https://www.geeksforgeeks.org/generate-unique-partitions-of-an-integer/
def update_partition(p, k):
    rem_val = 0
    while k >= 0 and p[k] == 1:
        rem_val += p[k]
        k -= 1

    # if k < 0, all the values are 1 so
    # there are no more partitions
    if k < 0:
        return p, k

    # Decrease the p[k] found above
    # and adjust the rem_val
    p[k] -= 1
    rem_val += 1

    # If rem_val is more, then the sorted
    # order is violated. Divide rem_val in
    # different values of size p[k] and copy
    # these values at different positions after p[k]
    while rem_val > p[k]:
        p[k + 1] = p[k]
        rem_val = rem_val - p[k]
        k += 1

    # Copy rem_val to next position
    # and increment position
    p[k + 1] = rem_val
    k += 1

    return p, k


def init_partition(size):
    p = [0] * size
    p[0] = size
    return p, 0


def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)


# Factorial of a
def fact(a):
    res = 1
    for i in range(1, a+1):
        res *= i
    return res


# n choose r
def comb(n, r):
    return fact(n) // (fact(n-r) * fact(r))


# Calculate the number of unique ways to construct partition p
def partition_dups(p, k):
    res, rem = 1, len(p)
    for i in range(k+1):
        res *= comb(rem, p[i]) * fact(p[i] - 1)
        rem -= p[i]

    cur = 1
    for i in range(1, k+1):
        if p[i] != p[i-1]:
            res //= fact(cur)
            cur = 1
        else:
            cur += 1
    res //= fact(cur)
    return res


# I needed help figuring out the theoretical solution to this problem
# so I ended up consulting https://math.stackexchange.com/questions/1941503/number-of-equivalence-classes-of-matrices-under-switching-rows-and-columns
# (Luckily I read an abstract algebra textbook this summer so this discussion actually made sense to me.)
# That said, actually implementing the logic in a reasonable manner was by my own design.
def solve(R, C, n):
    res = 0
    p1, k1 = init_partition(R)
    while k1 >= 0:
        p2, k2 = init_partition(C)
        while k2 >= 0:
            cur_exponent = 0
            for i in range(0, k1+1):
                for j in range(0, k2+1):
                    c, d = p1[i], p2[j]
                    cur_exponent += GCD(c, d)
            res += (n ** cur_exponent) * \
                partition_dups(p1, k1) * partition_dups(p2, k2)
            p2, k2 = update_partition(p2, k2)
        p1, k1 = update_partition(p1, k1)
    return res // (fact(R) * fact(C))


def solution(w, h, s):
    return str(solve(w, h, s))
