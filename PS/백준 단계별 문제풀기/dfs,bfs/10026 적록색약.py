from collections import deque
n = int(input())

arr = [list(input()) for _ in range(n)]


dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]


def check1():
    count = 0
    visited = [[False]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                q = deque()
                count += 1
                visited[i][j] = True
                q.append((i, j))
                while q:
                    nowR, nowC = q.popleft()

                    for d in dir:
                        nextR = d[0]+nowR
                        nextC = d[1]+nowC

                        if nextR < 0 or nextR >= n or nextC < 0 or nextC >= n:
                            continue

                        if not visited[nextR][nextC] and arr[nextR][nextC] == arr[i][j]:
                            q.append((nextR, nextC))
                            visited[nextR][nextC] = True
    return count


def check2():
    count = 0
    visited = [[False]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if arr[i][j] == "R":
                arr[i][j] = "G"
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                q = deque()
                count += 1
                visited[i][j] = True
                q.append((i, j))
                while q:
                    nowR, nowC = q.popleft()

                    for d in dir:
                        nextR = d[0]+nowR
                        nextC = d[1]+nowC

                        if nextR < 0 or nextR >= n or nextC < 0 or nextC >= n:
                            continue

                        if not visited[nextR][nextC] and arr[nextR][nextC] == arr[i][j]:
                            q.append((nextR, nextC))
                            visited[nextR][nextC] = True
    return count


print(check1(), end=" ")
print(check2())
