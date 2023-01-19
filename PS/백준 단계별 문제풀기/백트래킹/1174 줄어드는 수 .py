n = int(input())
result = set()


def backtracking(now):
    if now != "":
        result.add(int(now))

    for i in range(10):
        if now == "" or int(now[-1]) > i:
            backtracking(now+str(i))


backtracking("")
result = list(result)
result.sort()
if len(result) > n:
    print(result[n-1])
else:
    print(-1)
# n번째 줄어드는수
# 한자릿수는 -> 줄어드는수
# 0,1,2,3,4,5,6,7,8,9 -> 10개
# 풀이 -> 백트래킹으로 0~9 다해보기, 언제부턴가 감소하는 경우 만족못하는 경우가 오면서 끊김
