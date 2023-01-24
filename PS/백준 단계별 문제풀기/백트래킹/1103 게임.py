n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
dir = [(1, 0), (0, 1), (0, -1), (-1, 0)]
ans = -1
dp = [[0]*m for _ in range(n)]


def dfs(r, c, count):
    global ans
    ans = max(ans, count)
    for d in dir:
        nextR = r+d[0]*int(arr[r][c])
        nextC = c+d[1]*int(arr[r][c])
        if nextR < 0 or nextC < 0 or nextR >= n or nextC >= m or arr[nextR][nextC] == "H" or dp[nextR][nextC] >= count+1:
            continue
        if visited[nextR][nextC]:
            print(-1)
            exit()
        else:
            dp[nextR][nextC] = count+1
            visited[nextR][nextC] = True
            dfs(nextR, nextC, count+1)
            visited[nextR][nextC] = False


visited[0][0] = True
dfs(0, 0, 0)
print(ans+1)
