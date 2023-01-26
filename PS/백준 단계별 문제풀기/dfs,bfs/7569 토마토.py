from collections import deque
m, n, h = map(int, input().split())
arr = []
for _ in range(h):
    arr.append([list(map(int, input().split())) for _ in range(n)])
# hXnXm
dir = [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]


q = deque()
for k in range(h):
    for i in range(n):
        for j in range(m):
            if arr[k][i][j] == 1:
                q.append((k, i, j))
while q:
    now = q.popleft()
    for d in dir:
        nextH, nextR, nextC = (now[0]+d[0], now[1]+d[1], now[2]+d[2])
        if nextH < 0 or nextH >= h or nextR < 0 or nextR >= n or nextC < 0 or nextC >= m:
            continue
        if arr[nextH][nextR][nextC] == 0:
            arr[nextH][nextR][nextC] = arr[now[0]][now[1]][now[2]]+1
            q.append((nextH, nextR, nextC))


ans = -1
for k in range(h):
    for i in range(n):
        for j in range(m):
            if arr[k][i][j] == 0:
                print(-1)
                exit()
            ans = max(ans, arr[k][i][j])
print(ans-1)
