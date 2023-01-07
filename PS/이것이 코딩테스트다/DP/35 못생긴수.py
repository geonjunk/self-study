n = int(input())
dp = [0]*(n+1)
dp[1] = 1
i2, i3, i5 = 1, 1, 1

next2, next3, next5 = 2, 3, 5
for i in range(2, n+1):
    dp[i] = min(next2, next3, next5)

    if dp[i] == next2:
        i2 += 1
        next2 = dp[i2]*2
    if dp[i] == next3:
        i3 += 1
        next3 = dp[i3]*3
    if dp[i] == next5:
        i5 += 1
        next5 = dp[i5]*5

print(dp[n])
# dp[n]= dp[n-1]*
