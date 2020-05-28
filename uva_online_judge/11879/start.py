while True:
    n = int(input())
    if n == 0:
        break

    d = n % 10
    n //= 10
    n -= 5*d
    if n % 17 == 0:
        print(1)
    else:
        print(0)
