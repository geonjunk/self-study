n, s = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0


def backtracking(num, idx):
    global ans
    if idx>=n:
        return
    num+=arr[idx]
    if num == s:
        ans+=1

    backtracking(num-arr[idx], idx+1)
    backtracking(num, idx+1)


backtracking(0, 0)
print(ans)


# 합이 S
# 더하거나 안더하거나


# 백트래킹 시간복잡도 2^N
