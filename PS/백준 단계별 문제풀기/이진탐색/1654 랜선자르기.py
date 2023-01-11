k, n = map(int, input().split())
arr = []

for _ in range(k):
    arr.append(int(input()))


left = 1
right = max(arr)

while left <= right:
    mid = (left+right)//2  # 자를 길이
    s = 0
    for i in range(k):
        s += arr[i]//mid
    if s >= n:
        left = mid+1
    else:
        right = mid-1


print(right)
