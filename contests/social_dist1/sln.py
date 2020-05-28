fin = open("socdist1.in", "r")
fout = open("socdist1.out", "w")
L = list(fin)


N = int(L[0])
s = L[1] 
A = [True] * N
for i in range(N):
    A[i] = s[i] == "1"


def nextone(r):
    global A, N
    for i in range(r, N):
        if A[i]: return i
    return 4*N

def valid(D):
    global N, A
    l = -4*N
    r = nextone(0)
    count = 0

    for i in range(N):
        if A[i]:
            l = i
            r = nextone(r+1)
        elif i - l >= D and r - i >= D:
            l = i
            count += 1

    return count >= 2

lo = 0
hi = N+1

while(lo + 1 < hi):
    mid = (lo + hi) // 2
    if valid(mid): lo = mid
    else: hi = mid


fout.write(str(lo) + "\n");
print(lo)

