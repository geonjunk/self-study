n = int(input())
arr = list(map(int, input().split()))

left = 0
right = len(arr)-1
ans = -1
while left <= right:
    mid = (left+right)//2
    if arr[mid] > mid:
        right = mid-1
    elif arr[mid] < mid:
        left = mid+1
    else:
        ans = mid
        break

print(ans)
# 좋은 문제
