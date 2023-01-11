n = int(input())
s = set(map(int, input().split()))
m = int(input())
arr = list(map(int, input().split()))

for i in range(m):
    if arr[i] in s:
        print(1)
    else:
        print(0)
