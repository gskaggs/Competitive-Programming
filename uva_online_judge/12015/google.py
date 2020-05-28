
T = int(input())
for i in range(1, T + 1):
    websites = []
    for _ in range(10):
        IN = input().split()
        IN[1] = int(IN[1])
        websites.append(IN)

    MAX = -1
    for j in range(10):
        MAX = max(MAX, websites[j][1])

    ans = []
    for j in range(10):
        if websites[j][1] == MAX: ans.append(websites[j][0])

    head = "Case #" + str(i) + ":"
    print(head)

    for string in ans:
        print(string)


