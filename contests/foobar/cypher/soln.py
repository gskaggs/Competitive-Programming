def solution(x):
    res = []
    cypher = dict()
    for i in range(26):
        cypher[chr(ord('a') + i)] = chr(ord('z') - i)
    for i in range(len(x)):
        char = x[i]
        if char in cypher:
            res.append(cypher[char])
        else:
            res.append(char)
    return ''.join(res)
