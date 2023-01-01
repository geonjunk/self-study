def solution(s):
    answer = len(s)
    mid = len(s)//2+1
    for l in range(1, mid):
        result = ""
        now = s[:l]
        count = 1
        for i in range(l, len(s)+l, l):
            if s[i:i+l] == now:
                count += 1
            else:
                if count == 1:
                    result += now
                else:
                    result += str(count)
                    result += now
                count = 1
                now = s[i:i+l]
        answer = min(len(result), answer)
    return answer
