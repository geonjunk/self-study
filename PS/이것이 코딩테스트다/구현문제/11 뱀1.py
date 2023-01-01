N = int(input())  # N*N
K = int(input())  # 사과의 위치
arr = [[0]*(N+1) for _ in range(N+1)]

for _ in range(K):
    r, c = map(int, input().split())
    arr[r][c] = 1
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
d = {}
L = int(input())
for _ in range(L):
    x, c = input().split()
    d[int(x)] = c

q = []
q.append((1, 1))
arr[1][1] = 2
nowDir = 0
sec = 0
while True:
    sec += 1
    r = q[-1][0]+dir[nowDir][0]
    c = q[-1][1]+dir[nowDir][1]
    if r > N or c > N or r < 1 or c < 1 or arr[r][c] == 2:
        break

    if arr[r][c] == 0:
        q.append((r, c))
        arr[r][c] = 2
        tmpR, tmpC = q.pop(0)
        arr[tmpR][tmpC] = 0
    else:
        q.append((r, c))
        arr[r][c] = 2
    if sec in d.keys():
        if d[sec] == "D":
            nowDir = (nowDir+1) % 4
        else:
            nowDir = (nowDir-1) % 4
print(sec)
