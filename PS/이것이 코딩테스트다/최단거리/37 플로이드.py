# 길이 하나가 아닐수도 있다 -> 경로여러개일수도있음 -> 그중 최소를 선택
# n개의 마을 m개의 버스 = m개의 경로
n = int(input())
m = int(input())
dist = [[1e9]*(n+1) for _ in range(n+1)]

for i in range(n+1):
    for j in range(n+1):
        if i == j:
            dist[i][j] = 0

for i in range(m):
    a, b, c = map(int, input().split())
    dist[a][b] = min(dist[a][b], c)


for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

for i in range(1, n+1):
    for j in range(1, n+1):
        if dist[i][j] >= 1e9:
            print(0, end=" ")
        else:
            print(dist[i][j], end=" ")
    print()
