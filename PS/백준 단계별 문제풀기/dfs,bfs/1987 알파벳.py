import sys
input = sys.stdin.readline
R, C = map(int, input().split())
arr = [list(input().strip()) for _ in range(R)]
visited = [False]*26
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# dfs로
ans = -1


def dfs(r, c, count):
    global ans
    ans = max(ans, count)

    for d in dir:
        nextR = r+d[0]
        nextC = c+d[1]

        if nextR < 0 or nextR >= R or nextC < 0 or nextC >= C:
            continue

        nextIdx = ord(arr[nextR][nextC])-ord("A")
        if not visited[nextIdx]:
            visited[nextIdx] = True
            dfs(nextR, nextC, count+1)
            visited[nextIdx] = False


visited[ord(arr[0][0])-ord("A")] = True
dfs(0, 0, 1)

print(ans)
