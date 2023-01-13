n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

visited = [False]*(n)
ans = 1e9


def dfs(start, now, count, length):
    global ans
    if n == count:
        if graph[now][start]:
            ans = min(ans, length+graph[now][start])
        return

    for i in range(n):
        if not visited[i] and graph[now][i] != 0:
            visited[i] = True
            dfs(start, i, count+1, length+graph[now][i])
            visited[i] = False


for i in range(n):
    visited[i] = True
    dfs(i, i, 1, 0)
    visited[i] = False

print(ans)
