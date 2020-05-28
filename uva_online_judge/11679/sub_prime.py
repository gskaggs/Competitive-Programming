

while(True):
    IN = list(map(int, input().split()))
    B = IN[0]
    N = IN[1]
    
    if B == 0 and N == 0: break

    banks = list(map(int, input().split()))
    
    for _ in range(N):
        deb = list(map(int, input().split()))
        D = deb[0] - 1
        C = deb[1] - 1
        V = deb[2]
        
        banks[D] -= V
        banks[C] += V

    good = True
    for i in banks:
        if i < 0: good = False

    if good: print("S")
    else: print("N")

