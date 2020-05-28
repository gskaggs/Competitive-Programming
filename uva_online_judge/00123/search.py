import sys

def func(a):
    return a[1]
    
cont = True
ignore = set()
titles = []

for line in sys.stdin:
    line = line.strip()
    if cont:
        if line == '::':
            cont = False
            continue
        ignore.add(line)
    
    else:
        titles.append(line.lower())

ans = []

for title in titles:
    found = set()
    for word in title.split():
        if word in ignore or word in found: continue
        else: 
            i = 0
            found.add(word)
            while title.find(word, i) != -1:
                j = title.find(word, i)
                s = title[0:j] + word.upper() + title[j+len(word):]
                l = [s, word.upper()]
                i = j + len(word)
                ans.append(l)

ans = sorted(ans, key = func)

for title in ans:
    print(title[0])
