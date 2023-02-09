h, w = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
now = 0

for i in range(1, w-1):
    leftH = max(arr[:i])
    rightH = max(arr[i+1:])
    height = min(leftH, rightH)

    if height > arr[i]:
        ans += height-arr[i]
print(ans)

# 마지막 위치랑, 현재 위치는 물이 고일 수 없음
"""
0 0 0 1
1 0 0 1
1 0 0 1
1 0 1 1



"""
