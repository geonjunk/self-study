import sys
input = sys.stdin.readline
n, m = map(int, input().split())

arr = [input().strip() for _ in range(n)]
dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
visited = [[False]*m for _ in range(n)]
ans = -1
dp = [[0]*m for _ in range(n)]


def dfs(r, c, result):
    global ans
    ans = max(result, ans)
    for d in dir:
        nextR = d[0]*int(arr[r][c])+r
        nextC = d[1]*int(arr[r][c])+c
        if nextR < 0 or nextC < 0 or nextR >= n or nextC >= m or arr[nextR][nextC] == "H" or result+1 <= dp[nextR][nextC]:
            continue
        if visited[nextR][nextC]:
            print(-1)
            exit()
        dp[nextR][nextC] = result+1
        visited[nextR][nextC] = True
        dfs(nextR, nextC, result+1)
        visited[nextR][nextC] = False


dfs(0, 0, 0)
print(ans+1)

# dp를 이용해서 이전값보다 큰 경우에는 계산하지
