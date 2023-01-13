import heapq
n = int(input())
m = int(input())
INF = 1e9
graph = [[] for _ in range(n+1)]
dist = [INF]*(n+1)


for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


pq = []
heapq.heappush(pq, (0, 1))
dist[1] = 0

while pq:
    nowW, nowPos = heapq.heappop(pq)

    if nowW > dist[nowPos]:
        continue

    for i in graph[nowPos]:
        w = dist[nowPos]+1
        if w < dist[i]:
            dist[i] = w
            heapq.heappush(pq, (dist[i], i))

ans = 0
for d in dist:
    if d != INF and d != 0:
        ans += 1

print(ans)
