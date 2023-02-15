n, k = map(int, input().split())

arr = [(0, 0)]
for i in range(n):
    w, v = map(int, input().split())
    arr.append((w, v))
dp = [[0]*(k+1) for _ in range(n+1)]


for i in range(1, n+1):
    for j in range(1, k+1):
        w = arr[i][0]
        v = arr[i][1]

        if w > j:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)
print(dp[n][k])
