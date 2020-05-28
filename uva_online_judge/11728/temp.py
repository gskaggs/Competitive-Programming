def getline(): return list(map(int, input().split()))
def getint(): return int(input())

N = 1001
prime = [True] * N
prime[0] = prime[1] = False
div = [1] * N
mem = {}
for i in range(1, N):
    if prime[i]:
        div[i] = i+1
        for j in range(2*i, N, i):
            prime[j] = False
            exp = 0
            n = j
            while n % i == 0:
                n //= i
                exp += 1
            div[j] *= ((i ** (exp + 1)) - 1) // (i - 1)
        
    mem[div[i]] = i


count = 1

while True:
    n = getint()
    if n == 0: break
    print("Case {}: ".format(count), end = "")
    if n in mem: print(mem[n])
    else: print(-1)
    count +=1







