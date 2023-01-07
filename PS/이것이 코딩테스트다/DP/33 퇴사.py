n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

dp = [0]*(n+1)
for i in range(n-1, -1, -1):
    if arr[i][0]+i > n:
        dp[i] = dp[i+1]
    else:
        dp[i] = max(arr[i][1]+dp[i+arr[i][0]], dp[i+1])
print(dp[0])

# dp[i] = i번째날부터 마지막날까지 낼 수 있는 최대 이익

# 2. 역방향
"""
dp[i] : i번째 일수를 들었을 때 최댓값
dp[7]=0
dp[6]=0
dp[5]=15
dp[4]=20+dp[5]
dp[3] = dp[4]+10
dp[2] = dp[7]+20
dp[1] = dp[4]+10

"""

# 18353
