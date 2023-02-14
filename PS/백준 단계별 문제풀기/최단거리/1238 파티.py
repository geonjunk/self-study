
# 마을로 돌아올때 최단 시간에 오고가야함
# 단방향, 오고가는 길이 다름
# 오고가는데 가장 많은 시간 걸린사람  = X에 갔다가 X에서 다른 곳으로 가는 길
import heapq
n, m, x = map(int, input().split())
dist1 = [1e9]*(n+1)   # 다른 점에서 X까지의 거리
dist2 = [1e9]*(n+1)  # X에서 다른 점까지의 거리

# dist[X]+

graph1 = [[] for _ in range(n+1)]
graph2 = [[] for _ in range(n+1)]


for i in range(m):
    start, end, t = map(int, input().split())
    graph1[start].append((t, end))
    graph2[end].append((t, start))

dist1[x] = dist2[x] = 0

pq = []
heapq.heappush(pq, (0, x))

while pq:
    w, now = heapq.heappop(pq)

    if dist1[now] < w:
        continue

    for i in graph1[now]:
        nextT, nextPos = i
        if dist1[nextPos] > nextT+dist1[now]:
            dist1[nextPos] = nextT+dist1[now]
            heapq.heappush(pq, (dist1[nextPos], nextPos))

heapq.heappush(pq, (0, x))

while pq:
    w, now = heapq.heappop(pq)

    if dist2[now] < w:
        continue

    for i in graph2[now]:
        nextT, nextPos = i
        if dist2[nextPos] > nextT+dist2[now]:
            dist2[nextPos] = nextT+dist2[now]
            heapq.heappush(pq, (dist2[nextPos], nextPos))

ans = -1
for i in range(1, n+1):
    ans = max(ans, dist1[i]+dist2[i])

print(ans)
