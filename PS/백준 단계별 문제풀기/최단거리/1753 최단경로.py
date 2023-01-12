import heapq
v, e = map(int, input().split())
s = int(input())
INF = 1e9
dist = [INF]*(v+1)
graph = [[] for _ in range(v+1)]

for _ in range(e):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

pq = []
dist[s] = 0
heapq.heappush(pq, (0, s))

while pq:
    d, now = heapq.heappop(pq)

    if dist[now] < d:
        continue

    for g in graph[now]:
        nextPos, nextW = g
        w = nextW + dist[now]
        if w < dist[nextPos]:
            dist[nextPos] = w
            heapq.heappush(pq, (w, nextPos))

for i in range(1, v+1):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])
