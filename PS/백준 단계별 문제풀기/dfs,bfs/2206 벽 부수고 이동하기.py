from collections import deque
n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
visited = [[[1e9] * 2 for _ in range(m)] for _ in range(n)]
dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
# 벽을 1개 부수고 갈 수 있음
# 1은 벽이 있는 곳

# 1. 그냥 0  만났을 때 -> 가면됨
# 2. 벽만났을 때 -> 부수거나 안부수거나

q = deque()
visited[0][0][0] = 1
q.append((0, 0, 0, visited[0][0][0]))

# 벽뚫고 갔을때 더 빠르지만 다음 곳을 못갈때가 있음
# 따라서, 벽 뚫이랑 그냥 가는거라 분리를 해야함

while q:
    nowR, nowC, canBreak, length = q.popleft()
    for d in dir:
        nextR = nowR+d[0]
        nextC = nowC+d[1]

        if nextR < 0 or nextR >= n or nextC < 0 or nextC >= m:
            continue

        if arr[nextR][nextC] == "0":
            if visited[nextR][nextC][canBreak] > length+1:
                visited[nextR][nextC][canBreak] = length+1
                q.append((nextR, nextC, canBreak, length+1))

        if arr[nextR][nextC] == "1" and canBreak == 0:
            if visited[nextR][nextC][1] > length+1:
                visited[nextR][nextC][1] = length+1
                q.append((nextR, nextC, 1, length+1))

if visited[n-1][m-1][0] == 1e9 and visited[n-1][m-1][1] == 1e9:
    print(-1)
else:
    print(min(visited[n-1][m-1][0], visited[n-1][m-1][1]))
