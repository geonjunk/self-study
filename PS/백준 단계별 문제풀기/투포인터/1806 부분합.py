n, s = map(int, input().split())
arr = list(map(int, input().split()))
arr.append(0)
# 1. two pointer
low, high = 0, 0
now = 0
INF = 1e9
ans = INF
while high <= n:
    if now < s:
        now += arr[high]
        high += 1
    else:
        length = high-low
        ans = min(ans, length)
        now -= arr[low]
        low += 1

if ans == INF:
    print(0)
else:
    print(ans)
