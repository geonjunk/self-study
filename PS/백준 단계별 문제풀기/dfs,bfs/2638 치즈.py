from collections import deque
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
count = [[0]*m for _ in range(n)]
# 2변이상 접함? ->BFS

dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
q = deque()
q.append((0, 0))
ans = 0
while True:
    nextq = deque()
    while q:
        nowR, nowC = q.popleft()
        for d in dir:
            nextR, nextC = nowR+d[0], nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= n or nextC >= m:
                continue

            if count[nextR][nextC] == 0:
                count[nextR][nextC] += 1
                if arr[nextR][nextC] == 0:
                    q.append((nextR, nextC))
            elif count[nextR][nextC] == 1 and arr[nextR][nextC] == 1:
                count[nextR][nextC] += 1
                nextq.append((nextR, nextC))
    if len(nextq) == 0:
        break
    ans += 1
    q = nextq
print(ans)
