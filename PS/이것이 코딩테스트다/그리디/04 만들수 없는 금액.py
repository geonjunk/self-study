N = int(input())
arr = list(map(int, input().split()))
arr.sort()
now = 1

for i in arr:
    if now < i:
        break
    else:
        now += i
print(now)
