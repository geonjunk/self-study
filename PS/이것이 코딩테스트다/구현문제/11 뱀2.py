from collections import deque
N = int(input())  # N*N
K = int(input())  # 사과의 위치
apple = []
for _ in range(K):
    r, c = map(int, input().split())
    apple.append((r, c))
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
d = {}
L = int(input())
for _ in range(L):
    x, c = input().split()
    d[int(x)] = c

q = deque([])
q.append((1, 1))
nowDir = 0
sec = 0
while True:
    sec += 1
    r = q[-1][0]+dir[nowDir][0]
    c = q[-1][1]+dir[nowDir][1]
    if r > N or c > N or r < 1 or c < 1 or (r, c) in q:
        break
    else:
        q.append((r, c))
        if (r, c) not in apple:
            q.popleft()
        else:
            apple.remove((r, c))
    if sec in d.keys():
        if d[sec] == "D":
            nowDir = (nowDir+1) % 4
        else:
            nowDir = (nowDir-1) % 4
print(sec)
