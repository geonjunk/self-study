import sys


def bfs():
    global graph, virus, N, M, ans
    dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    queue = []
    queue.extend(virus)
    tmp_graph = [[0]*M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            tmp_graph[i][j] = graph[i][j]
    while queue:
        nowR, nowC = queue.pop(0)
        for d in dir:
            nextR = nowR+d[0]
            nextC = nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= N or nextC >= M:
                continue

            if tmp_graph[nextR][nextC] == 0:
                tmp_graph[nextR][nextC] = 2
                queue.append((nextR, nextC))
    count = 0
    for i in range(N):
        for j in range(M):
            if tmp_graph[i][j] == 0:
                count += 1
    ans = max(ans, count)


def setWall(count):
    if count == 3:
        bfs()
        return

    for i in range(N):
        for j in range(M):
            if graph[i][j] == 0:
                graph[i][j] = 1
                setWall(count+1)
                graph[i][j] = 0


input = sys.stdin.readline
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
virus = []
ans = 0

for i in range(N):
    for j in range(M):
        if graph[i][j] == 2:
            virus.append((i, j))

setWall(0)

print(ans)
