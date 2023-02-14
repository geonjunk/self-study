n = int(input())
m = int(input())  # 0~9까지 숫자와
buttons = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
if m > 0:
    arr = list(map(int, input().split()))  # 고장난 버튼 배열
    for i in arr:
        buttons.remove(i)

ans = abs(100-n)
for now in range(1000001):
    flag = True
    for j in str(now):
        if int(j) not in buttons:
            flag = False
            break
    if flag:
        ans = min(ans, abs(now-n)+len(str(now)))

print(ans)
