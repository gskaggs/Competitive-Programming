#! /usr/bin/python3
import random
import os
import shutil
import subprocess
import time
import zipfile


random.seed(18943)
tc = 0


def writeTestCase(N, Q, a, b):
    global tc
    tc += 1
    print(tc)
    filename = 'input/input%02d.txt' % tc
    with open(filename, 'w') as fout:
        print(N, Q, file=fout)
        for i in range(Q):
            print(a[i], b[i], file=fout)

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
    return (20, 7, [2, 1, 2, 1, 2, 1, 2], [10, 10, 10, 9, 10, 11, 10])
    
def randGen(size, prop):
    N = random.randint(size - 5, size)
    Q = N + random.randint(0, N // 10)
        
    t1 = int(prop * Q)
    t2 = Q - t1

    order = [1 for i in range(t1)]
    for i in range(t2):
        order.append(2)
    
    random.shuffle(order)
    indices = random.sample(range(1, N), t1)

    currT1 = 0
    b = []
    for i in range(Q):
        if order[i] == 1:
            b.append(indices[currT1])
            currT1 = currT1 + 1
        else:
            b.append(random.randint(0, N))

    return (N, Q, order, b)

def genAdv(size):
    N = random.randint(size - 5, size)
    Q = N + N // 10

    t1 = Q // 2
    t2 = Q - t1

    order = [1 for i in range(t1)]
    b = []
    for i in range(20, 20 + t1):
        b.append(i)

    for i in range(20, 20 + t2):
        order.append(2)
        b.append(i)

    return (N, Q, order, b)



def main():
    global tc
    prep()
    writeTestCase(*sample1())
    for i in range(10):
        writeTestCase(*randGen(20, 0.5))
    for i in range(4):
        writeTestCase(*randGen(99000, 0.8))
    for i in range(4):
        writeTestCase(*randGen(99000, 0.2))
    writeTestCase(*genAdv(100000))
    writeTestCase(*genAdv(130000))
    for i in range(3):
        writeTestCase(*randGen(99000, 0.5))
    writeTestCase(*genAdv(150000))
    
    zipper()


if __name__ == '__main__':
    main()
