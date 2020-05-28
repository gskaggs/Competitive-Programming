def euclid(a, b):
    global x, y, d
    if b == 0:
        x, y, d = 1, 0, a
        return

    euclid(b, a%b)
    x, y = y, x - (a // b) * y

x, y, d = 0, 0, 0

