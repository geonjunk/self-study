# 자신 큰사람 왼쪽에 몇명 이 있는 지
n = int(input())


arr = list(map(int, input().split()))
seq = [0]*n

for i in range(n):
    count = 0  # 앞에 키큰 사람 넣은 횟수
    for j in range(n):
        if count == arr[i] and seq[j] == 0:
            seq[j] = i+1
            break
        elif seq[j] == 0:
            count += 1
for i in range(n):
    print(seq[i], end=" ")
