S = input()
result = int(S[0])
for i in range(1, len(S)):
    num = int(S[i])
    if result <= 1 or num <= 1:
        result += int(num)
    else:
        result *= int(num)
print(result)
