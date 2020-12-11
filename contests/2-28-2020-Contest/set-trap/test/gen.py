#! /usr/bin/python3
import random
import os
import shutil
import subprocess
import time
import zipfile


random.seed(18943)
tc = 0


def writeTestCase(N, M, C, A, t):
    global tc
    tc += 1
    print(tc)
    filename = 'input/input%02d.txt' % tc
    with open(filename, 'w') as fout:
        print(N, M, C, A, file=fout)
        print(*t, file=fout)
    with open('output/output%02d.txt' % tc, 'w') as outf:
        with open(filename, 'r') as inf:
            subprocess.call(['./abhilash.out'],
                            stdin=inf, stdout=outf)


def prep():
    inpath = os.getcwd() + '/input'
    outpath = os.getcwd() + '/output'
    shutil.rmtree(inpath, True)
    os.mkdir(inpath)
    shutil.rmtree(outpath, True)
    os.mkdir(outpath)
    subprocess.call(['g++', '-std=c++17', '-O3', '-o', 'abhilash.out', '../ac/abhilash.cpp'])
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
    return (1, 3, 1, 4, [7])

def sample2():
    return (4, 4, 3, 2, [7,9,11])

    
def randGen(size1, size2, size3, size4, size5):
    N = random.randint(size5 - size5/2, size5 + size5/2)
    C = random.randint(size1 - size1/2, size1 + size1/2)
    
    M = random.randint(size2 - size2/2, size2 + size2/2)

    A = random.randint(0, size4 + size4/2)

    t = []
    for i in range(C):
        val = random.randint(1, size3)
        t.append(val)

    t.sort();

    return (N, M, C, A, t)


def main():
    global tc
    prep()
    writeTestCase(*sample1())
    writeTestCase(*sample2())
    for i in range(10):
        writeTestCase(*randGen(100, 1000, 1000, 50, 1000))
    for i in range(10):
        writeTestCase(*randGen(5000, 1000000, 1000000, 1000, 1000000))
    for i in range(10):
        writeTestCase(*randGen(50000, 5e7, 1e17, 100000, 3e9))
    zipper()


if __name__ == '__main__':
    main()
