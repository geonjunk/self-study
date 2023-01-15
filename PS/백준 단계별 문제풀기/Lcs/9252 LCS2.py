import sys
input = sys.stdin.readline

a = input().strip()
b = input().strip()

n, m = len(a)+1, len(b)+1

lcs = [[""]*m for _ in range(n)]
for i in range(1, n):
    for j in range(1, m):
        if a[i-1] == b[j-1]:
            lcs[i][j] = lcs[i-1][j-1]+a[i-1]
        else:
            if len(lcs[i][j-1]) > len(lcs[i-1][j]):
                lcs[i][j] = lcs[i][j-1]
            else:
                lcs[i][j] = lcs[i-1][j]
print(len(lcs[n-1][m-1]))
print(lcs[n-1][m-1])
