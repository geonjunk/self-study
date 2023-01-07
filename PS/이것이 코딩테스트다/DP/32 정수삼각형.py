n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*len(arr[i]) for i in range(len(arr))]
dp[0][0] = arr[0][0]
for i in range(1, len(arr)):
    for j in range(len(arr[i])):
        if j-1 >= 0:
            dp[i][j] = max(dp[i][j], dp[i-1][j-1])
        if j != (len(arr[i])-1):
            dp[i][j] = max(dp[i][j], dp[i-1][j])
        dp[i][j] += arr[i][j]

print(max(dp[n-1]))
# 대각선 오(x+1,y+1) 대각선 왼(x+1,y)
