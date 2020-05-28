t = int(input())
for _ in range(t):
    line = input().split() 
    a = int(line[0][::-1])
    b = int(line[1][::-1])
    c = str(a + b)
    print(int(c[::-1]))
