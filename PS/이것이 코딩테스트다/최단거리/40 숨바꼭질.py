import heapq
n, m = map(int, input().split())
INF = int(1e9)
graph = [[] for _ in range(n+1)]
dist = [INF]*(n+1)
dist[1] = 0
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append((b, 1))
    graph[b].append((a, 1))

pq = [(0, 1)]

while pq:
    w, now = heapq.heappop(pq)
    if dist[now] < w:
        continue

    for i in graph[now]:
        cost = i[1]+w
        if dist[i[0]] > cost:
            dist[i[0]] = cost
            heapq.heappush(pq, (cost, i[0]))
# 헛간번호(여러개면 가장 작은), 거리, 같은 거리 갖는 갯수
ans = []
maxDist = max(dist[1:])
for i in range(1, n+1):
    if maxDist == dist[i]:
        ans.append(i)
print(dist)
print(min(ans), maxDist, len(ans))
