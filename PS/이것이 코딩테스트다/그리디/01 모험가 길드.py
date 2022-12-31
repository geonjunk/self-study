N = int(input())
arr = list(map(int, input().split()))
arr.sort()
ans = 0
now = 0
for i in arr:
    now += 1
    if now >= i:
        ans += 1
        now = 0
print(ans)
