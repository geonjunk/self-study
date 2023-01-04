import sys
input = sys.stdin.readline

N = int(input())
ans = False
teachers = []
mapArr = []
# 3개의 장애물 설치
# S, T 위치
mapArr = [list(input().split()) for _ in range(N)]
for i in range(N):
    for j in range(N):
        if mapArr[i][j] == "T":
            teachers.append((i, j))

dir = [(1, 0), (-1, 0), (0, -1), (0, 1)]


def setWall(count):
    global ans
    if count == 3:
        # 4방향 탐색
        # S가 있으면 count후 S 위치 바꿈
        # 다계산후 다 피할수 있는지 여부 확인
        # 감시 피할 수 없다면 S 위치 원위치
        for t in teachers:
            startR, startC = t
            for d in dir:
                nowR = startR+d[0]
                nowC = startC+d[1]
                while True:
                    if nowR < 0 or nowR >= N or nowC < 0 or nowC >= N:
                        break
                    if mapArr[nowR][nowC] == "W":
                        break
                    if mapArr[nowR][nowC] == "S":
                        return
                    nowR += d[0]
                    nowC += d[1]
        ans = True
        return

    for i in range(N):
        for j in range(N):
            if mapArr[i][j] == "X":
                mapArr[i][j] = "W"
                setWall(count+1)
                mapArr[i][j] = "X"


setWall(0)
if ans:
    print("YES")
else:
    print("NO")
