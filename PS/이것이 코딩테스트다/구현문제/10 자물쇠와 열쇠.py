def solution(key, lock):
    answer = False
    lockSize = len(lock)
    keySize = len(key)
    blockSize = lockSize+2*(keySize)
    block = [[0]*blockSize for _ in range(blockSize)]
    initBlock(block, keySize, lockSize, lock)
    for _ in range(4):
        for i in range(blockSize-keySize):
            for j in range(blockSize-keySize):
                if check(i, j, block, key, keySize, lockSize):
                    return True
                initBlock(block, keySize, lockSize, lock)
        key = rotate(key)
    return answer


def rotate(key):
    l = len(key)
    tmp = [[0]*l for _ in range(l)]

    for i in range(l):
        for j in range(l):
            tmp[i][j] = key[l-1-j][i]
    return tmp


def initBlock(block, keySize, lockSize, lock):
    for i in range(keySize-1, keySize-1+lockSize):
        for j in range(keySize-1, keySize-1+lockSize):
            block[i][j] = lock[i-keySize+1][j-keySize+1]


def check(r, c, block, key, keySize, lockSize):
    for i in range(r, r+keySize):
        for j in range(c, c+keySize):
            block[i][j] += key[i-r][j-c]

    for i in range(keySize-1, keySize-1+lockSize):
        for j in range(keySize-1, keySize-1+lockSize):
            if block[i][j] != 1:
                return False

    return True
