cat = [0]*1001
cat[0] = 1
cat[1] = 1

for i in range(2, 1001):
    for j in range(0, i):
        cat[i] += cat[j] * cat[i-j-1]

while True:
    try:
        N = int(input())
        print(cat[N])
    except EOFError:
        break
