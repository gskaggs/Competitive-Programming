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

def sample1():
    return (3, 3, [[1, 2, 4], [0, 7, 0], [3, 5, 6]])

def sample2():
    return (4, 4, [[0, 8, 9, 3], [1,4,7,12], [11,6,5,10], [14,13,2,0]])


def dist(a, b, M):
    la = a // M
    ra = a % M

    lb = b // M
    rb = b % M

    # print(f'{la}, {ra}, {lb}, {rb}')
    return abs(la - lb) + abs(ra - rb)
    
def randGen(size):
    N = random.randint(size - 5, size + 5)
    M = random.randint(size - 5, size + 5)
    a = [[0 for col in range(M)] for row in range(N)]
    pts = [i for i in range(M * N)]
  
    random.shuffle(pts);
    while(dist(pts[N * M - 2], pts[N * M - 1], M) < min(M, N)):
        random.shuffle(pts)

    for i in range(len(pts)):
        a[pts[i] // M][pts[i] % M] = i + 1

    a[pts[N * M - 2] // M][pts[N * M - 2] % M] = 0
    a[pts[N * M - 1] // M][pts[N * M - 1] % M] = 0

    return (N, M, a)


def main():
    global tc
    prep()
    writeTestCase(*sample1())
    writeTestCase(*sample2())
    for i in range(10):
        writeTestCase(*randGen(10))
    for i in range(10):
        writeTestCase(*randGen(100))
    for i in range(10):
        writeTestCase(*randGen(490))
    zipper()


if __name__ == '__main__':
    main()
