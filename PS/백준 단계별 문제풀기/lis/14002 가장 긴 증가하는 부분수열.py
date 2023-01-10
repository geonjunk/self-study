a = int(input())
arr = list(map(int, input().split()))
result = [[] for _ in range(a)]
result[0].append(arr[0])
for i in range(1, a):
    result[i].append(arr[i])
    for j in range(i):
        if arr[i] > arr[j]:
            if len(result[j])+1 > len(result[i]):
                result[i] = []
                result[i].extend(result[j])
                result[i].append(arr[i])
max_idx = 0
length = len(result[0])
for i in range(1, len(result)):
    if len(result[i]) > length:
        max_idx = i
        length = len(result[i])
print(length)
for i in result[max_idx]:
    print(i, end=" ")

# 10 20
