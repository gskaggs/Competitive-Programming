from soln import solution

test_cases = [(0, 1, 3), (19, 36, 1), [5, 5, 0], [63, 63, 0], [8, 19, 2], [19, 8, 2], [56, 7, 6], [0, 63, 6], [63, 0, 6]]
passed = 0
failed = 0

for case in test_cases:
    print case[0], case[1]
    print solution(case[0], case[1])
    if solution(case[0], case[1]) == case[2]:
        passed += 1
        print 'passed test', passed + failed
    else:
        failed += 1
        print 'failed test', passed + failed
    print ''

print 'failed', failed, 'tests', '\n'
