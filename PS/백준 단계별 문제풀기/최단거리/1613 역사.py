n, k = map(int, input().split())
INF = 1e9
dist = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(k):
    a, b = map(int, input().split())
    dist[a][b] = 1

for i in range(1, n+1):
    dist[i][i] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

s = int(input())
result = []

for i in range(s):
    a, b = map(int, input().split())
    if dist[a][b] != INF and dist[b][a] == INF:
        result.append(-1)
    elif dist[a][b] == INF and dist[b][a] != INF:
        result.append(1)
    else:
        result.append(0)


for r in result:
    print(r)
