s = input()
s = "".join(sorted(s))
total = 0
pos = -1
for i in range(len(s)):
    if s[i].isdigit():
        total += int(s[i])
    else:
        pos = i
        break
s = s[pos:]+str(total)

print(s)
