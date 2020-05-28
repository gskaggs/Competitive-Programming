
fib = [1] * 120
fib[1] = 2
for i in range(2, 120):
    fib[i] = fib[i-1] + fib[i-2]


while True:
    try:
        a = input()
        b = input()
        n1 = 0
        n2 = 0

        a = a[::-1]
        b = b[::-1]

        for i in range(0, len(a)):
            if (a[i] == '1'): n1 += fib[i]

        for i in range(0, len(b)):
            if (b[i] == '1'): n2 += fib[i]

        s = n1 + n2
        first = False
        res = ''
        temp = s

        for i in range(119, -1, -1):
            if fib[i] <= s:
                s-= fib[i]
                res += '1'
                first = True
            elif first:
                res += '0'
        
        if temp != 0:
            print(res)
        else:
            print(0)

        input()
        print("")

    except EOFError:
        break
