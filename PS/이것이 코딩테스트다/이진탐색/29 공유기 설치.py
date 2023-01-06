n, c = map(int, input().split())
arr = [int(input()) for _ in range(n)]
arr.sort()
start = 1  # 공유기 사이거리 최솟값
end = arr[n-1]-arr[0]  # 최댓값
result = 0
while start <= end:
    mid = (start+end)//2
    count = 1
    current = arr[0]
    for i in range(1, len(arr)):
        if arr[i] >= current+mid:  # 현재위치 더하기 gap
            current = arr[i]
            count += 1

    if count >= c:
        start = mid+1
        result = mid
    else:
        end = mid-1
print(result)
