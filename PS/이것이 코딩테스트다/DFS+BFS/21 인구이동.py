from collections import deque
N, L, R = map(int, input().split())
mapArr = [list(map(int, input().split())) for _ in range(N)]

ans = 0


def bfs(i, j, index):
    dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    queue = deque()
    queue.append((i, j))
    unionArr = [(i, j)]
    union[i][j] = index
    sumUnion = mapArr[i][j]
    while queue:
        nowR, nowC = queue.popleft()
        for d in dir:
            nextR = nowR+d[0]
            nextC = nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= N or nextC >= N:
                continue
            if union[nextR][nextC] == -1 and L <= abs(mapArr[nextR][nextC]-mapArr[nowR][nowC]) <= R:
                union[nextR][nextC] = index
                unionArr.append((nextR, nextC))
                queue.append((nextR, nextC))
                sumUnion += mapArr[nextR][nextC]

    if len(unionArr) > 1:
        tmp = sumUnion//len(unionArr)
        for u in unionArr:
            mapArr[u[0]][u[1]] = tmp


while True:
    index = 0
    union = [[-1]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if union[i][j] == -1:
                bfs(i, j, index)
                index += 1

    if index == N*N:
        break
    ans += 1

print(ans)
