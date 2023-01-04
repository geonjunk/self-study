import sys
import heapq
input = sys.stdin.readline
# 2시 20분
N, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
S, X, Y = map(int, input().split())  # S초와 X,Y는 무엇?
pq = []
# 번호순서대로 bfs -> 번호기준 우선순위 Queue
for i in range(N):
    for j in range(N):
        if arr[i][j] != 0:
            heapq.heappush(pq, ((0, arr[i][j]), i, j))

dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
# S초를 재야함
while pq:
    now, nowX, nowY = heapq.heappop(pq)
    if now[0] == S:
        break
    for d in dir:
        nextX = nowX+d[0]
        nextY = nowY+d[1]
        if nextX < 0 or nextX >= N or nextY < 0 or nextY >= N:
            continue

        if arr[nextX][nextY] == 0:
            arr[nextX][nextY] = now[1]
            heapq.heappush(pq, ((now[0]+1, now[1]), nextX, nextY))

print(arr[X-1][Y-1])
