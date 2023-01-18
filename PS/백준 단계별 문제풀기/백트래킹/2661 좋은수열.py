n = int(input())

# 7자리
# 인접한 동일 수열이 있다면 나쁜 수열
# 좋은 수열들 중 가장 작은 수를 나타내는 수열만 출력

# 완전 탐색후 나쁜수열 판단


# 추가한 위치를 포함해서 검사하면됨
def isBad(s):
    size = len(s)
    for i in range(1, size//2+1):  # 몇개씩
        if s[size-i:] == s[size-2*i:size-i]:
            return True
    return False


def backtracking(count, s):
    if n == count:
        print(s)
        exit()

    for i in range(1, 4):
        if not isBad(s+str(i)):
            backtracking(count+1, s+str(i))


backtracking(0, "")
