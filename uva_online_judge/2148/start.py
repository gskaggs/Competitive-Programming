
t = int(input())

for _ in range(t):
	input()
	n = int(input())
	
	sum = 0
	for _ in range(n):
		sum += int(input())
	
	if (sum % n == 0): print("YES")
	else: print("NO")
