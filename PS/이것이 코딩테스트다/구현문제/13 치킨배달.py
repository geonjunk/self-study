N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
house = []
chicken = []
store = []  # 그냥 가게들
answer = 1e9
for i in range(len(arr)):
    for j in range(len(arr)):
        if arr[i][j] == 1:
            house.append((i, j))
        elif arr[i][j] == 2:
            store.append((i, j))


def cal():
    result = 0
    for h in house:
        way = 1e9
        for c in chicken:
            way = min(way, abs(h[0]-c[0])+abs(h[1]-c[1]))
        result += way
    return result


def backtracking(n, idx):
    global answer
    if n == M:
        answer = min(answer, cal())
        return

    for i in range(idx, len(store)):
        if store[i] not in chicken:
            chicken.append(store[i])
            backtracking(n+1, i+1)
            chicken.pop()


backtracking(0, 0)
print(answer)
