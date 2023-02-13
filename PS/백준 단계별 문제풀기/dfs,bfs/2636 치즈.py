from collections import deque
n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
cheese = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            cheese += 1

dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]

q = deque()
q.append((0, 0))
nextq = deque()
count = 0
while True:
    while q:
        nowR, nowC = q.popleft()
        for d in dir:
            nextR, nextC = nowR+d[0], nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= n or nextC >= m:
                continue

            if not visited[nextR][nextC]:
                visited[nextR][nextC] = True
                if arr[nextR][nextC] == 1:
                    arr[nextR][nextC] = 0
                    nextq.append((nextR, nextC))
                else:
                    q.append((nextR, nextC))
    if cheese == len(nextq):
        print(count+1)
        print(cheese)
        break

    count += 1
    cheese -= len(nextq)
    while nextq:
        q.append((nextq.popleft()))

# 흰면과 접할경우 ->안쪽 회색면으로 녹음
# 안쪽 획색 면 없으면 삭제됨


# 밖에있는 0을 기준으로 퍼트린다.

# 밖에있음을 어떻게 판단?

# X에서 BFS -> 외부 판단하고 -> 치즈만나면 좌표 저장
# 저장한 치즈 좌표 녹임  -> 해당 위치에서 다시 BFS하여 방문처리
