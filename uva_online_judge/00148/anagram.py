
def recurse(phrase, size):
    
    global words

    cur_l = []
    for i in range(size, (size + 1)//2 - 1, -1):
        for word in words[i]:
            valid = True
            temp = phrase.copy()
            for ch in word:
                if temp[ord(ch) - ord('A')] < 1:
                    valid = False
                    break
                index = ord(ch) - ord('A')
                temp[index] -= 1
        
            if valid:
                if size - i == 0:
                    print("AYY")
                    cur_l.append([word])
                else:
                    rec_l = recurse(temp, size - i)
                    if len(rec_l) > 0:
                        for rec_phrase in rec_l:
                            cur_l.append([word] + rec_phrase)
    return cur_l



words = [[] for _ in range(21)]

while True:
    line = input()
    if line == '#':
        break
    words[len(line)].append(line)


while True:
    line = input()
    if line == '#':
        break
    
    phrase = [0]*26
    count = 0

    for c in line:
        if c == ' ':
            continue
        index = ord(c) - ord('A')
        phrase[index] += 1
        count += 1

    phrases = recurse(phrase, count)
    print("hi", phrases)
    for p in phrases:
        ans = ""
        for w in p:
            ans += w + " "
        print(line, "=", ans.strip())



