n, a, b = input().split()
n = int(n)

while a[0] == b[0]:
    a, b = a[1:], b[1:]

if a[0] == '1':
    a, b = b, a

def f(x):
    n = len(x)
    if n == 0:
        return 0
    if x[0] == '0':
        return f(x[1:])
    return 2**n - 1 - f(x[1:])

print(f(b) - f(a) - 1)

