n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

visited = [[False]*(m) for _ in range(n)]
ans = 0
dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def backtracking(r, c, s):
    global ans
    if c == m:
        c = 0
        r += 1
    if r == n:
        ans = max(ans, s)
        return
    if not visited[r][c]:
        for i in range(4):
            nextR1 = r+dir[i][0]
            nextC1 = c+dir[i][1]
            nextR2 = r+dir[(i+1) % 4][0]
            nextC2 = c+dir[(i+1) % 4][1]

            if nextR1 < 0 or nextC1 < 0 or nextR1 >= n or nextC1 >= m or nextR2 < 0 or nextC2 < 0 or nextR2 >= n or nextC2 >= m:
                continue

            if not visited[nextR1][nextC1] and not visited[nextR2][nextC2]:
                visited[r][c] = True
                visited[nextR1][nextC1] = True
                visited[nextR2][nextC2] = True
                subSum = 2*arr[r][c]+arr[nextR1][nextC1]+arr[nextR2][nextC2]
                backtracking(r, c+1, s+subSum)
                visited[r][c] = False
                visited[nextR1][nextC1] = False
                visited[nextR2][nextC2] = False
    backtracking(r, c+1, s)  # 그냥 다음으로 넘어가는 경우


backtracking(0, 0, 0)
# ㄱ자모양 판단
print(ans)
