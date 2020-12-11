B, R, C, A = map(int, input().split())

if B >= 10**6 or R >= 10**6 or C >= 10**6 or A >= 10**6:
    print("error")
    
total = B * 1440 + R * 590 + C * 224 + A * 130

print(total // 2000)
