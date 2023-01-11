n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

left = 1
right = max(arr)-1
while left <= right:
    mid = (left+right)//2
    total = 0
    for i in range(len(arr)):
        diff = arr[i]-mid
        if diff > 0:
            total += diff
    if total >= m:
        left = mid+1
    else:
        right = mid-1
print(right)
