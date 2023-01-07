str1 = input()
str2 = input()

dp = [[0]*(len(str2)+1) for _ in range(len(str1)+1)]

for i in range(1, len(str1)+1):
    dp[i][0] = i
for j in range(1, len(str2)+1):
    dp[0][j] = j

# dp[i][j] = str1 i자릿수와 str2 j까지의 연산 갯수

for i in range(1, len(str1)+1):
    for j in range(1, len(str2)+1):
        if str1[i-1] == str2[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = 1+min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])

print(dp[len(str1)][len(str2)])
