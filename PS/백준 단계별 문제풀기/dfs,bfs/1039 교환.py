from collections import deque
n, k = map(int, input().split())
m = len(str(n))
q = deque()
visited = set()

q.append((n, 0))
ans = -1
while q:
    now, count = q.popleft()
    if count == k:
        ans = max(ans, now)
        continue
    now = str(now)
    for i in range(m-1):
        for j in range(i+1, m):
            if i == 0 and now[j] == "0":
                continue
            nextNum = int(now[:i]+now[j]+now[i+1:j]+now[i]+now[j+1:])
            if (nextNum, count+1) not in visited:
                visited.add((int(nextNum), count+1))
                q.append((int(nextNum), count+1))
            

print(ans)
