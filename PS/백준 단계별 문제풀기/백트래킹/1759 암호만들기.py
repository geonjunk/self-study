l, c = map(int, input().split())
s = {"a", "e", "i", "o", "u"}
arr = list(input().split())
arr.sort()
visited = [False]*c
# 최소 1개의 모음, 최소 2개의 자음
# 자음과 모음 count하면서 깊이 우선 탐색


def backtracking(n, count1, count2, result):
    if n == l:
        if count1 >= 1 and count2 >= 2:
            print(result)
        return

    for i in range(c):
        if not visited[i] and result == "" or result[-1] < arr[i]:
            visited[i] = True
            if arr[i] in s:
                backtracking(n+1, count1+1, count2, result+arr[i])
            else:
                backtracking(n+1, count1, count2+1, result+arr[i])
            visited[i] = False


backtracking(0, 0, 0, "")
