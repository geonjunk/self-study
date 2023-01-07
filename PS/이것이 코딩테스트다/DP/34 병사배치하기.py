n = int(input())

arr = list(map(int, input().split()))


arr.reverse()
dp = [1]*n
for i in range(1, n):
    for j in range(i):
        if arr[i] < arr[j]:
            dp[i] = max(dp[i], dp[j]+1)


print(n-max(dp))
# LIS**** dp[i] : i에서 끝나는 최장 증가 수열
