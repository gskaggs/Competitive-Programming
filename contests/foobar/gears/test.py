from soln import solution

test_cases = [[4, 17, 50], [4, 30, 50], [30, 30, 30],
              [12, 16], [1, 3, 5], [1, 3, 5, 7, 9]]
passed = 0
failed = 0

for case in test_cases:
    print case
    print solution(case)
    print ''
