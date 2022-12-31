N, M = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
count = [0]*(M+1)
for n in arr:
    count[n] += 1

for c in count:
    N -= c
    ans += N*c
print(ans)
