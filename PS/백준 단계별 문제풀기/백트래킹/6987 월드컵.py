import sys
input = sys.stdin.readline


def backtracking(count):
    global ans
    if count == 15:
        for i in range(6):
            if sum(res[i]) != 0:
                return
        ans = 1
        return

    team1, team2 = matchList[count]
    if res[team1][0] > 0 and res[team2][2] > 0:
        res[team1][0] -= 1
        res[team2][2] -= 1
        backtracking(count+1)
        res[team1][0] += 1
        res[team2][2] += 1

    if res[team1][1] > 0 and res[team2][1] > 0:
        res[team1][1] -= 1
        res[team2][1] -= 1
        backtracking(count+1)
        res[team1][1] += 1
        res[team2][1] += 1

    if res[team1][2] > 0 and res[team2][0] > 0:
        res[team1][2] -= 1
        res[team2][0] -= 1
        backtracking(count+1)
        res[team1][2] += 1
        res[team2][0] += 1


matchList = []
for i in range(6):
    for j in range(i+1, 6):
        matchList.append((i, j))


for _ in range(4):
    data = list(map(int, input().split()))
    res = []
    ans = 0
    for i in range(0, 16, 3):
        res.append(data[i:i+3])
    backtracking(0)
    print(ans, end=" ")


# 5 0 0 ->
# 각 판의 순서대로 다해봄 (A,B),(B,C)
