from collections import deque
n, k = map(int, input().split())
visited = [False]*100001

q = deque()
q.append((n, 0))
ans = 1e9
while q:
    now, t = q.popleft()
    if now == k:
        ans = min(t, ans)
        break

    if now*2 <= 100000 and not visited[now*2]:
        visited[now*2] = True
        q.appendleft((now*2, t))
    if now+1 <= 100000 and not visited[now+1]:
        visited[now+1] = True
        q.append((now+1, t+1))
    if now-1 >= 0 and not visited[now-1]:
        visited[now-1] = True
        q.append((now-1, t+1))


print(ans)
