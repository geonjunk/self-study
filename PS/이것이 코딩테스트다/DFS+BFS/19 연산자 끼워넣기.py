N = int(input())
# 덧셈, 뺄셈, 곱셈, 나눗셈
numArr = list(map(int, input().split()))
opArr = list(map(int, input().split()))

# 최댓값, 최솟값
maxNum = -1e9
minNum = 1e9
# 완전 탐색 12!


def dfs(result, count):
    global maxNum, minNum
    if count == N:
        maxNum = max(result, maxNum)
        minNum = min(result, minNum)
        return

    for i in range(len(opArr)):
        if opArr[i] > 0:
            opArr[i] -= 1
            if i == 0:
                dfs(result+numArr[count], count+1)
            elif i == 1:
                dfs(result-numArr[count], count+1)
            elif i == 2:
                dfs(result*numArr[count], count+1)
            elif i == 3:
                if result < 0:
                    dfs(-(-result//numArr[count]), count+1)
                else:
                    dfs(result//numArr[count], count+1)
            opArr[i] += 1


dfs(numArr[0], 1)
print(maxNum)
print(minNum)
