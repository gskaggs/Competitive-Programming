cat = [1] * 11 

for i in range(2, 11):
    cat[i] = 0
    for j in range(0, i):
        cat[i] += cat[j] * cat[i-j-1]

first = False
while True:
    try:
        if first: print("")
        N = int(input())
        print(cat[N])
        input()
        first = True
    except EOFError:
        break

