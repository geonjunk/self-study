from collections import deque
n, k = map(int, input().split())
visited = [-1]*100001
q = deque()
q.append((n, 0))
result = deque()
visited[n] = n
ans = 0
while q:
    now, count = q.popleft()
    if now == k:
        ans = count
        tmp = now
        while visited[tmp] != tmp:
            result.appendleft(tmp)
            tmp = visited[tmp]
        result.appendleft(tmp)
        break

    if now*2 <= 100000 and visited[now*2] < 0:
        visited[now*2] = now
        q.append((now*2, count+1))
    if now+1 <= 100000 and visited[now+1] < 0:
        visited[now+1] = now
        q.append((now+1, count+1))

    if now-1 >= 0 and visited[now-1] < 0:
        visited[now-1] = now
        q.append((now-1, count+1))

print(ans)
for i in result:
    print(i, end=" ")
