# 2차원  DIjkstra
import heapq


def dijkstra(n):
    graph = [list(map(int, input().split())) for _ in range(n)]
    dist = [[1e9]*(n) for _ in range(n)]
    dist[0][0] = graph[0][0]

    pq = []
    heapq.heappush(pq, (dist[0][0], 0, 0))
    dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    while pq:
        nowW, nowR, nowC = heapq.heappop(pq)
        if dist[nowR][nowC] < nowW:
            continue
        for d in dir:

            nextR = nowR+d[0]
            nextC = nowC+d[1]
            if nextR < 0 or nextC < 0 or nextR >= n or nextC >= n:
                continue

            if dist[nextR][nextC] > nowW+graph[nextR][nextC]:
                dist[nextR][nextC] = nowW+graph[nextR][nextC]
                heapq.heappush(pq, (dist[nextR][nextC], nextR, nextC))

    print(dist[n-1][n-1])


t = int(input())
for _ in range(t):
    n = int(input())
    dijkstra(n)
