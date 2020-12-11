from soln import solution

cases = [(2, 2, 2, 7), (2, 3, 4, 430)]

for case in cases:
    print case[3], solution(case[0], case[1], case[2])
