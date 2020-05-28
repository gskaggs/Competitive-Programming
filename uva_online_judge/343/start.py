
def get_base(a):
    base = 2
    while True:
        try:
            int(a, base)
            return base
        except ValueError:
            base+=1

while True:
    try:
        a, b = input().split()
        
        base1 = get_base(a)
        base2 = get_base(b)
        
        while (base1 <= 36 and base2 <= 36):
            val1 = int(a, base1)
            val2 = int(b, base2)
            if val1 == val2:
                break
            elif val1 < val2:
                base1 += 1
            else:
                base2 += 1

        if (base1 <= 36 and base2 <= 36):
            print(a, base1, b, base2)
        else:
            print("impossible")

        #do something
    except EOFError:
        break
