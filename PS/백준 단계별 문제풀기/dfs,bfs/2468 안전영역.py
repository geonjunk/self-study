from collections import deque
n = int(input())
maxCount = -1
arr = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        maxCount = max(maxCount, arr[i][j])


def bfs(r, c, tmp):
    dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    q = deque()
    q.append((r, c))
    visited[r][c] = True
    while q:
        nowR, nowC = q.popleft()
        for d in dir:
            nextR = d[0]+nowR
            nextC = d[1]+nowC
            if nextR < 0 or nextC < 0 or nextR >= n or nextC >= n:
                continue
            if not visited[nextR][nextC] and arr[nextR][nextC] > tmp:
                visited[nextR][nextC] = True
                q.append((nextR, nextC))


ans = -1
for tmp in range(maxCount):
    visited = [[False]*n for _ in range(n)]
    count = 0
    for i in range(n):
        for j in range(n):
            if arr[i][j] > tmp and not visited[i][j]:
                bfs(i, j, tmp)
                count += 1
    ans = max(ans, count)

print(ans)
