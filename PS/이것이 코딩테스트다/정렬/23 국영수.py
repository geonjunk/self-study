N = int(input())


arr = []
for i in range(N):
    name, s1, s2, s3 = input().split()
    arr.append((tuple(map(int, [s1, s2, s3])), name))
arr.sort(key=lambda x: (-x[0][0], x[0][1], -x[0][2], x[1]))

for a in arr:
    print(a[1])
