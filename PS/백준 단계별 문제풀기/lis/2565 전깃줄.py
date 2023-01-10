n = int(input())
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))

arr.sort()
dp = [0]*n
dp[0] = 1
for i in range(n):
    dp[i] = 1
    for j in range(i):
        if arr[i][1] > arr[j][1]:
            dp[i] = max(dp[j]+1, dp[i])

print(n-max(dp))
