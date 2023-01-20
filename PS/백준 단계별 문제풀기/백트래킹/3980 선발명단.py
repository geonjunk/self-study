t = int(input())


def backtracking(count, s):
    global ans
    if count == 11:
        ans = max(ans, s)
        return

    for i in range(11):
        if not visited[i] and arr[count][i] != 0:
            visited[i] = True
            backtracking(count+1, s + arr[count][i])
            visited[i] = False


for _ in range(t):
    arr = [list(map(int, input().split()))
           for _ in range(11)]  # arr[i][j] : i번째 선수가 j 번째 포지션에서 뛸때
    visited = [False]*11
    ans = -1
    backtracking(0, 0)
    print(ans)
