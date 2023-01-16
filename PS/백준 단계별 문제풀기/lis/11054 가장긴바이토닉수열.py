n = int(input())
arr = list(map(int, input().split()))
dp1 = [0]*(n)
dp2 = [0]*(n)
for i in range(n):
    dp1[i] = 1
    for j in range(i):
        if arr[i] > arr[j]:
            dp1[i] = max(dp1[i], dp1[j]+1)


for i in range(n-1, -1, -1):
    dp2[i] = 1
    for j in range(n-1, i, -1):
        if arr[i] > arr[j]:
            dp2[i] = max(dp2[i], dp2[j]+1)

ans = -1
for i in range(n):
    ans = max(ans, dp1[i]+dp2[i]-1)
print(ans)
