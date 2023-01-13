from collections import deque
n = int(input())
arr = [list(map(int, input().strip())) for _ in range(n)]

result = []
visited = [[False]*n for _ in range(n)]


def bfs(sr, sc):
    q = deque()
    q.append((sr, sc))
    visited[sr][sc] = True
    count = 1
    dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    while q:
        nowR, nowC = q.popleft()

        for d in dir:
            nextR = nowR+d[0]
            nextC = nowC+d[1]

            if nextR < 0 or nextC < 0 or nextR >= n or nextC >= n:
                continue

            if arr[nextR][nextC] == 1 and not visited[nextR][nextC]:
                count += 1
                q.append((nextR, nextC))
                visited[nextR][nextC] = True

    result.append(count)


for i in range(n):
    for j in range(n):
        if not visited[i][j] and arr[i][j] == 1:
            bfs(i, j)

result.sort()

print(len(result))
for i in result:
    print(i)
