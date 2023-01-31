from collections import deque
n, h, d = map(int, input().split())  # 한변의길이, 체력, 우산 내구도
# S -> 현재, 안전지대 ->E, U->
arr = [list(input()) for _ in range(n)]
visited = [[0]*n for _ in range(n)]
q = deque()
for i in range(n):
    for j in range(n):
        if arr[i][j] == "S":
            q.append((i, j, h, 0, 0))
            visited[i][j] = h

dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
while q:
    nowR, nowC, nowH, nowD, count = q.popleft()
    for i in dir:
        nextR = i[0]+nowR
        nextC = i[1]+nowC
        if nextR < 0 or nextC < 0 or nextR >= n or nextC >= n:
            continue
        if arr[nextR][nextC] == "E":
            print(count+1)
            exit()
        nextD = nowD
        nextH = nowH
        if arr[nextR][nextC] == "U":
            nextD = d
        if nextD > 0:
            nextD -= 1
        else:
            nextH -= 1

        if nextH == 0:
            continue

        if visited[nextR][nextC] < nextH:
            q.append((nextR, nextC, nextH, nextD, count+1))
            visited[nextR][nextC] = nextH


print(-1)
