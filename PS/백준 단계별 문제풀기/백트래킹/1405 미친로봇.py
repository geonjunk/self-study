# 로봇이 같은곳을 방문하지 않을때 -> 단순경로
n, east, west, south, north = map(int, input().split())
# 동 , 서 , 남 , 북
arr = [(0, 0)]
ans = 0
dir = [(0, 1, east), (0, -1, west), (1, 0, north), (-1, 0, south)]


def backtracking(count, now, result):
    global ans
    if count == n:
        ans += result
        return
    for d in dir:
        next = (now[0]+d[0], now[1]+d[1])
        if next not in arr:
            arr.append(next)
            backtracking(count+1, next, result*(d[2]/100))
            arr.pop()


backtracking(0, (0, 0), 1)
print(ans)
