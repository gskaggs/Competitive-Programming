#! /usr/bin/python3
import random
import os
import shutil
import subprocess
import time
import zipfile


random.seed(18943)
tc = 0


def writeTestCase(N, M, a):
    global tc
    tc += 1
    print(tc)
    filename = 'input/input%02d.txt' % tc
    with open(filename, 'w') as fout:
        print(N, M, file=fout)
        for arr in a:
            print(*arr, file=fout)
    with open('output/output%02d.txt' % tc, 'w') as outf:
        with open(filename, 'r') as inf:
            subprocess.call(['./grant.out'],
                            stdin=inf, stdout=outf)


def prep():
    inpath = os.getcwd() + '/input'
    outpath = os.getcwd() + '/output'
    shutil.rmtree(inpath, True)
    os.mkdir(inpath)
    shutil.rmtree(outpath, True)
    os.mkdir(outpath)
    subprocess.call(['g++', '-std=c++17', '-O3', '-o', 'grant.out', '../ac/grant.cc'])
    time.sleep(1)


def zipper():
    zipf = zipfile.ZipFile('test.zip', 'w')
    for _, _, files in os.walk('input'):
        for filename in files:
            zipf.write(os.path.join('input', filename))
    for _, _, files in os.walk('output'):
        for filename in files:
            zipf.write(os.path.join('output', filename))
    zipf.close()

def sample1():
    return (5, 3, [[0, 1, 5], [1, 2, 5], [0, 1, 5]])

def sample2():
    return (5, 4, [[1, 1, 499], [1,1,499], [1,2,3], [0,1,5]])

def sample3():
    N = 20000
    Q = 20000
    a = []

    for i in range(1, 2501):
        a.append([1, i, 2])
    for i in range(2501, Q+1):
        a.append([0, 1, N])

    return (N, Q, a) 

def randGen(sizeN, sizeQ):
    N = random.randint(sizeN//2, sizeN)
    Q = random.randint(sizeQ//2, sizeQ)
    a = []
 
    maxPrime = 500
    prime = [True] * maxPrime 
    prime[0] = prime[1] = False 
    primes = []

    #sieve
    for i in range(maxPrime):
        if prime[i]:
            primes.append(i)
            for j in range(i*i, maxPrime, i):
                prime[j] = False

    for _ in range(Q-1):
        t = random.choice([0, 1])
        if t == 1:
            loc = random.randint(1, N)
            mult = random.choice(primes)
            a.append([t, loc, mult])
        else:
            loc1 = 1
            loc2 = 1
            while abs(loc1 - loc2) < Q//2:
                loc1 = random.randint(1, N)
                loc2 = random.randint(1, N)
            a.append([t, min(loc1, loc2), max(loc1, loc2)])

    a.append([0, 1, N])
    return (N, Q, a)


def main():
    global tc
    prep()
    writeTestCase(*sample1())
    writeTestCase(*sample2())
    for i in range(9):
        writeTestCase(*randGen(10, 5))
    for i in range(5):
        writeTestCase(*randGen(100, 50))
    for i in range(15):
        writeTestCase(*randGen(25000, 25000))
    writeTestCase(*sample3())
    zipper()


if __name__ == '__main__':
    main()
