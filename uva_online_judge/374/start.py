def getline(): return list(map(int, input().split()))
def getint(): return int(input())

def pow(B, P, M):
    res = 1
    while P > 0:
        if P & 1:
            res *= B
            res %= M
        B *= B 
        B %= M
        P >>= 1
    return res
        

while True:
    try:
        B, P, M = getint(), getint(), getint()
        print(pow(B, P, M))
        input()
    except EOFError:
        break



