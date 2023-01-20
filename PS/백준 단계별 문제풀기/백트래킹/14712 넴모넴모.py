n, m = map(int, input().split())
arr = [[0]*m for _ in range(n)]
ans = 0
# 넴모가 하나라도 만들어지면 안됨


def dfs(r, c):
    global ans
    if c == m:
        c = 0
        r += 1
    if r == n:
        ans += 1
        return

    dfs(r, c+1)
    if arr[r-1][c] == 0 or arr[r-1][c-1] == 0 or arr[r][c-1] == 0:
        arr[r][c] = 1
        dfs(r, c+1)
        arr[r][c] = 0


dfs(0, 0)
print(ans)
