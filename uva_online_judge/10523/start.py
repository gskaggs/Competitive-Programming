
while True:
    try:
        N, A = map(int, input().split())
        res = 0
        for i in range(1, N+1):
            res += i * (A ** i)
        print(res)
    except EOFError:
        break
