# 1번!=2번 -> n번집은 !=n-1
# i번째 집은 i-1 i+1과 달라야함
n = int(input())

# dp[색깔][n]= min(dp[다른색깔][n-1])

arr = [list(map(int, input().split())) for _ in range(n)]
# arr[0][1]= 1번집을 초록으로 색칠할때 비용
dp = [[1e9]*3 for _ in range(n)]
dp[0][0] = arr[0][0]
dp[0][1] = arr[0][1]
dp[0][2] = arr[0][2]

for i in range(1, n):
    dp[i][0] = min(dp[i-1][1], dp[i-1][2])+arr[i][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2])+arr[i][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1])+arr[i][2]

print(min(dp[n-1]))
