n = int(input())
m = int(input())
INF = 1e9
dist = [[INF]*(n+1) for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    dist[a][b] = 1

for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            dist[i][j] = 0


for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j])

ans = 0
for i in range(1, n+1):
    count = 0
    for j in range(1, n+1):
        if dist[i][j] != INF or dist[j][i] != INF:
            count += 1
    print(n-count)
