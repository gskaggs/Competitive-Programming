from soln import solution

cases = [("2", "1", "1"), ("4", "7", "4"),
         ("2", "4", "impossible"), (str(10**50), str(10**26 + 2), "impossible")]

for case in cases:
    print case
    print solution(case[0], case[1])
    if case[2] == solution(case[0], case[1]):
        print "success"
    else:
        print "failure"
    print ""
