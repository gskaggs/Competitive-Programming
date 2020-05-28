def getline(): return list(map(int, input().split()))
def getint(): return int(input())



def lastdig(N, M):
    res = 1
    for i in range(M):
        res *= N - i
        while res % 10 == 0 and res > 0:
            res //= 10
        res %= 10 ** 9

    return res % 10



while True:
    try:
        N, M = getline()
        print(lastdig(N, M))
    except EOFError:
        break






