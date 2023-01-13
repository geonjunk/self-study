from collections import deque
n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]
result1, result2 = [], []
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n+1):
    graph[i].sort()


def dfs(now):
    result1.append(now)
    for g in graph[now]:
        if not visited[g]:
            visited[g] = True
            dfs(g)


def bfs(v):
    q = deque([])
    q.append(v)
    visited[v] = True
    while q:
        now = q.popleft()
        result2.append(now)
        for g in graph[now]:
            if visited[g]:
                continue
            else:
                q.append(g)
                visited[g] = True


visited = [False]*(n+1)
visited[v] = True
dfs(v)

visited = [False]*(n+1)
visited[v] = True
bfs(v)

for i in result1:
    print(i, end=" ")
print()
for j in result2:
    print(j, end=" ")
