import sys
from collections import deque
input = sys.stdin.readline
r, c = map(int, input().split())
arr = [list(input().strip()) for _ in range(r)]
sr, sc = -1, -1
waters = deque()
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'S':
            sr, sc = i, j
        if arr[i][j] == "*":
            waters.append((i, j))

dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
q = deque()
ans = -1
q.append((sr, sc, 0))

while q:
    for i in range(len(waters)):
        wR, wC = waters.popleft()
        for d in dir:
            nextwR, nextwC = wR+d[0], wC+d[1]
            if nextwR < 0 or nextwC < 0 or nextwR >= r or nextwC >= c:
                continue
            if arr[nextwR][nextwC] != "X" and arr[nextwR][nextwC] != "D" and arr[nextwR][nextwC] != "*":
                arr[nextwR][nextwC] = "*"
                waters.append((nextwR, nextwC))

    for _ in range(len(q)):
        nowR, nowC, nowT = q.popleft()
        for d in dir:
            nextR, nextC = nowR+d[0], nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= r or nextC >= c:
                continue
            if arr[nextR][nextC] == "D":
                ans = nowT+1
                print(ans)
                exit()
            if arr[nextR][nextC] == ".":
                q.append((nextR, nextC, nowT+1))
                arr[nextR][nextC] = "S"
print("KAKTUS")
