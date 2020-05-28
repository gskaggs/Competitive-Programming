def fact(N):
    if N == 1:
        return 1
    return N * fact(N-1)


while True:
    N = int(input())
    if N == 0: break
    cur = str(fact(N))
    print(str(N) + '! --')
    line = "     (0) {} (1) {} (2) {} (3) {} (4) {}".format(cur.count('0'), cur.count('1'), cur.count('2'), cur.count('3'), cur.count('4') )
    print(line)
    line = "     (5) {} (6) {} (7) {} (8) {} (9) {}".format(cur.count('5'), cur.count('6'), cur.count('7'), cur.count('8'), cur.count('9') )
    print(line)
