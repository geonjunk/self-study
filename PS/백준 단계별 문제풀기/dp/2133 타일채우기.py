n = int(input())
dp = [0]*(31)
dp[0] = 1
dp[1] = 0
dp[2] = 3
for i in range(3, n+1):
    if i % 2 == 1:
        dp[i] = 0
    else:
        dp[i] = dp[i-2]*dp[2]
        for j in range(4, i+1, 2):
            dp[i] += dp[i-j]*2

print(dp[n])

# dp[i]=dp[i-2]*dp[2] + 고유의 모양 2개씩 존재하는거 해줌(dp[i-4]*2...)
# 짝수면 고유의 모양이 항상 새롭게 2개씩 존재
