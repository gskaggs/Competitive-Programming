N = int(input())
n = [int(input()) for _ in range(N)]
seen = [False] * (N+1)

from queue import PriorityQueue

q = PriorityQueue()


lo, hi = 0, 1
res = 0

def clear_heap():
   while(seen[-q.queue[0]]):
       q.get()

def move_hi():
    q.put(-n[hi])
    hi+=1

def move_lo():
    lo += 1
    seen[lo] = True
    clear_heap()

while hi <= N:
    if hi - lo == 1;
        move_hi()
        continue
    if n[hi] > -q.queue[0] and n[lo] > -q.queue[0]:
        res += 1
        if n[hi] > n[lo]:
            move_lo()
        else: 
            move_hi()
        continue
    if n[lo] < q.queue[0]:
        move_lo()
        continue
    else:
        move_hi()
        continue


print(res + N-1)



