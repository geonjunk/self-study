# 들어오는 경로가 있거나 나가는 경로가 있으면 비교가능
# 비교를 본인수와 다른수와 N-1번 하면 위치 알 수 있는 것

n, m = map(int, input().split())
INF = 1e9
dist = [[INF]*(n+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            dist[i][j] = 0

for _ in range(m):
    a, b = map(int, input().split())
    dist[a][b] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
ans = 0
for i in range(1, n+1):
    count = 0
    for j in range(1, n+1):
        if dist[i][j] != INF or dist[j][i] != INF:
            count += 1

    if count == n:
        ans += 1

print(ans)
