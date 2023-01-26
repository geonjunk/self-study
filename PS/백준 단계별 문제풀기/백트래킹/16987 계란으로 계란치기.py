n = int(input())
eggs = []
for i in range(n):
    a, b = map(int, input().split())
    eggs.append([a, b])
ans = -1


def backtracking(count):
    global ans
    if count == n:
        tmp = 0
        for i in range(n):
            if eggs[i][0] <= 0:
                tmp += 1
        ans = max(ans, tmp)
        return
    if eggs[count][0] <= 0:
        backtracking(count+1)
    else:
        for i in range(n):
            flag = True  # 모든계란이 깨진 경우
            if i != count and eggs[i][0] > 0:
                flag = False
                eggs[i][0] -= eggs[count][1]
                eggs[count][0] -= eggs[i][1]
                backtracking(count+1)
                eggs[i][0] += eggs[count][1]
                eggs[count][0] += eggs[i][1]
        if flag:
            backtracking(count+1)


backtracking(0)
print(ans)
