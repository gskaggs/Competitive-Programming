b = 257
p = 10**9 + 7

def val(c):
    return int(c - 'a')

def f(n, prev, s):
    h = 0
    num = (b ** n) % p
    for i in range(n):
        h *= b
        h += val(a[i])
        h %= p
    for i in range(n, len(a)):
        roll = (h * b + val(a[i])) % p
        if h in prev:
            res[roll] = res.get(roll, 0) + 1
        h = (roll - num * val(a[i-n]) % p

    return res

        
def simplify(next):
    res = set()
    for n in next:
        if next[n] >= 2:
            res.add(n)
    return res



        


