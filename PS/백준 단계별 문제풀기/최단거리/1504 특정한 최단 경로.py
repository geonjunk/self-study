import heapq
n, e = map(int, input().split())
INF = 1e9
graph = [[] for _ in range(n+1)]


for i in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))


v1, v2 = map(int, input().split())


def dijkstra(start):
    dist = [INF]*(n+1)
    dist[start] = 0

    pq = []
    heapq.heappush(pq, (0, start))

    while pq:
        d, now = heapq.heappop(pq)

        if d > dist[now]:
            continue

        for x in graph[now]:
            nextPos, nextDist = x
            if dist[nextPos] > nextDist+dist[now]:
                dist[nextPos] = nextDist+dist[now]
                heapq.heappush(pq, (dist[nextPos], nextPos))
    return dist


arr1 = dijkstra(1)
arr2 = dijkstra(v1)
arr3 = dijkstra(v2)
ans = min(arr1[v1]+arr2[v2]+arr3[n], arr1[v2]+arr3[v1]+arr2[n])

if ans < INF:
    print(ans)
else:
    print(-1)


# 1번정점에서 N 번정점
# 1->v1->v2 -> N
# 1->v2->v1-> N

# 500 000 000

# 1. floyd warshall -> 시간 초과

# 2. 다익스트락 -> 1에서 최단거리 찾음 v1,v2중 , v1에서
