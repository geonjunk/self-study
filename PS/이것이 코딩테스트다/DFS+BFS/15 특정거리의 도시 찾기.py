import heapq
import sys

input = sys.stdin.readline
N, M, K, X = map(int, input().split())  # N 도시의 갯수, M 도로의 갯수, K 최단거리 , X 출발도시
graph = [[] for _ in range(N+1)]
dist = [1e9] * (N+1)
for _ in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
dist[X] = 0
pq = []
heapq.heappush(pq, (0, X))

while pq:
    w, now = heapq.heappop(pq)
    if dist[now] < w:
        continue

    for pos in graph[now]:
        distance = 1+dist[now]
        if dist[pos] > distance:
            dist[pos] = distance
            heapq.heappush(pq, (distance, pos))

if K not in dist:
    print(-1)
else:
    for i in range(len(dist)):
        if dist[i] == K:
            print(i)
