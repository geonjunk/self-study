arr = [list(map(int, input().split())) for _ in range(9)]
zeroCount = 0
zeroArr = []
isFinish = False
for i in range(9):
    for j in range(9):
        if arr[i][j] == 0:
            zeroCount += 1
            zeroArr.append((i, j))


def check(r, c, num):
    for i in range(9):
        if num == arr[r][i] or num == arr[i][c]:
            return False

    sr = (r//3)*3
    sc = (c//3)*3
    for i in range(sr, sr+3):
        for j in range(sc, sc+3):
            if arr[i][j] == num:
                return False

    return True


def backtracking(count):
    global isFinish
    if count == zeroCount:
        for i in range(9):
            for j in range(9):
                print(arr[i][j], end=" ")
            print()
        isFinish = True
        return 0
    if isFinish:
        return
    for j in range(1, 10):
        r, c = zeroArr[count]
        if check(r, c, j):
            arr[r][c] = j
            backtracking(count+1)
            arr[r][c] = 0


backtracking(0)
