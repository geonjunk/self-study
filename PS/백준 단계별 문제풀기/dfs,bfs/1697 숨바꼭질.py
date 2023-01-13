from collections import deque
n, k = map(int, input().split())  # 수빈이 위치 N, 동생 위치 K
ans = 1e9


q = deque()
q.append((n, 0))
visited = [False]*100001

while q:
    pos, t = q.popleft()

    if pos == k:
        ans = t
        break
    for x in (pos-1, pos+1, pos*2):
        if 0 <= x <= 100000 and not visited[x]:
            visited[x] = True
            q.append((x, t+1))


print(ans)
