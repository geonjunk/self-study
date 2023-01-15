n = int(input())
queens = [-1]*n
ans = 0
visited = [False]*n


def isPromising(r, c):
    for i in range(r):
        if queens[i] == c or abs(r-i) == abs(c-queens[i]):
            return False
    return True


def backtracking(count):
    global ans
    if count == n:
        ans += 1
        return

    for i in range(n):
        if not visited[i] and isPromising(count, i):
            queens[count] = i
            visited[i] = True
            backtracking(count+1)
            visited[i] = False


backtracking(0)
print(ans)
