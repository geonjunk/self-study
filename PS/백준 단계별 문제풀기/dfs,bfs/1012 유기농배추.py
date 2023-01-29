from collections import deque
t = int(input())
dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
for _ in range(t):
    m, n, k = map(int, input().split())
    arr = [[0]*n for _ in range(m)]
    visited = [[False]*n for _ in range(m)]
    startPos = []
    result = 0
    for i in range(k):
        r, c = map(int, input().split())
        arr[r][c] = 1
        startPos.append((r, c))

    for r, c in startPos:
        if not visited[r][c]:
            result += 1
            q = deque()
            q.append((r, c))
            while q:
                nowR, nowC = q.popleft()
                for d in dir:
                    nextR = d[0]+nowR
                    nextC = d[1]+nowC
                    if nextR < 0 or nextR >= m or nextC < 0 or nextC >= n:
                        continue
                    if arr[nextR][nextC] == 1 and not visited[nextR][nextC]:
                        visited[nextR][nextC] = True
                        q.append((nextR, nextC))
    print(result)
