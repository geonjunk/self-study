# 투포인터

n, m = map(int, input().split())

arr = list(map(int, input().split()))
ans = 0
idx1, idx2 = 0, 0
s = 0
while True:
    if s < m:
        if idx2 == n:
            break
        else:
            s += arr[idx2]
            idx2 += 1
    else:
        if s == m:
            ans += 1
        s -= arr[idx1]
        idx1 += 1
        break

print(ans)
