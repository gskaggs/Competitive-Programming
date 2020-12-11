#! /usr/bin/python3
import random
import os
import shutil
import subprocess
import time
import zipfile


random.seed(18943)
tc = 0


def writeTestCase(N, M, a, b):
    global tc
    tc += 1
    print(tc)
    filename = 'input/input%02d.txt' % tc
    with open(filename, 'w') as fout:
        print(N, file=fout)
        for i in range(N):
            print(a[2 * i], a[2 * i + 1], file=fout)
        print(M, file=fout)
        for i in range(M):
            print(b[2 * i], b[2 * i + 1], file=fout)

    with open('output/output%02d.txt' % tc, 'w') as outf:
        with open(filename, 'r') as inf:
            subprocess.call(['./aditya.out'],
                            stdin=inf, stdout=outf)


def prep():
    inpath = os.getcwd() + '/input'
    outpath = os.getcwd() + '/output'
    shutil.rmtree(inpath, True)
    os.mkdir(inpath)
    shutil.rmtree(outpath, True)
    os.mkdir(outpath)
    subprocess.call(['g++', '-std=c++17', '-O3', '-o', 'aditya.out', '../ac/aditya.cpp'])
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

def sample2():
    return (4, 3, [1, 3, 5, 7, 8, 9, 10, 16], [1, 6, 9, 12, 14, 18])

def sample1():
    return (2, 1, [1, 3, 5, 7], [6, 12])

    
def randGen(size, end):
    N = random.randint(size - 5, size)
    M = random.randint(size - 5, size)
        
    a = sorted(random.sample(range(end), N * 2))
    b = sorted(random.sample(range(end), M * 2))

    return (N, M, a, b)


def main():
    global tc
    prep()
    writeTestCase(*sample1())
    writeTestCase(*sample2())
    for i in range(10):
        writeTestCase(*randGen(10, 100))
    for i in range(10):
        writeTestCase(*randGen(1000, 10000))
    for i in range(10):
        writeTestCase(*randGen(10000, 1000000))
    zipper()


if __name__ == '__main__':
    main()
