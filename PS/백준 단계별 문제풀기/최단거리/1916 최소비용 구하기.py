import heapq
n = int(input())
m = int(input())
INF = 1e9
dist = [INF]*(n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

start, end = map(int, input().split())
dist[start] = 0

pq = [(0, start)]

while pq:
    d, now = heapq.heappop(pq)
    if d > dist[now]:
        continue

    for g in graph[now]:
        pos, w = g
        nextW = w+dist[now]
        if dist[pos] > nextW:
            dist[pos] = nextW
            heapq.heappush(pq, (nextW, pos))

print(dist[end])
