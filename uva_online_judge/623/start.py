def getline():
    return list(map(int, input().split()))

fact = [1]
N = 1001
for i in range(1, N):
    fact.append(fact[-1] * i)

while True:
    try:
        A = int(input())
        print(str(A)+"!")
        print(fact[A])
    except EOFError:
        break




