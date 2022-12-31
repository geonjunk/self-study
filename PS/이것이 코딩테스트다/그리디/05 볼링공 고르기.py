N, M = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if arr[i] != arr[j]:
            ans += 1
print(ans)
