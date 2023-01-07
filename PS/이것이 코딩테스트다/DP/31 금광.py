T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    arr = [arr[i*m:(i+1)*m] for i in range(len(arr)//m)]
    dp = [[0]*m for _ in range(n)]

    for i in range(n):
        dp[i][0] = arr[i][0]

    for i in range(1, m):
        for j in range(n):
            dp[j][i] = dp[j][i-1]
            if j > 0:
                dp[j][i] = max(dp[j][i], dp[j-1][i-1])
            if j+1 < n:
                dp[j][i] = max(dp[j][i], dp[j+1][i-1])
            dp[j][i] += arr[j][i]
    ans = -1
    for i in range(n):
        ans = max(ans, dp[i][m-1])
    print(ans)
