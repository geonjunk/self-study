import sys
input = sys.stdin.readline

a = input().strip()
b = input().strip()
l1, l2 = len(a), len(b)
lcs = [[0]*(l2+1) for _ in range(l1+1)]

for i in range(1, l1+1):
    for j in range(1, l2+1):
        if a[i-1] == b[j-1]:
            lcs[i][j] = lcs[i-1][j-1]+1
        else:
            lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j])

ans = -1
print(lcs[l1][l2])
