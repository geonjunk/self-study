n, x = map(int, input().split())
arr = list(map(int, input().split()))
# 해당 수에 시작점

left = 0
right = n-1
start = -1
while left <= right:
    mid = (left+right)//2
    if arr[mid] < x:
        left = mid+1
    else:
        start = mid
        right = mid-1
print(left, right)
ans = 0
for i in range(start, len(arr)):
    if arr[i] == x:
        ans += 1
    else:
        break
if ans > 0:
    print(ans)
else:
    print(-1)
