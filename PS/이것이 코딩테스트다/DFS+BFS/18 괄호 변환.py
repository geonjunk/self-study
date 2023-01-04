def isCorrect(p):
    stack = []
    for i in range(len(p)):
        if p[i] == "(":
            stack.append("(")
        else:
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                return False
    if stack:
        return False

    return True


def balanced_index(p):
    count = 0
    for i in range(len(p)):
        if p[i] == "(":
            count += 1
        else:
            count -= 1
        if count == 0:
            return i


def solution(p):
    answer = ''
    if p == "":
        return answer
    if isCorrect(p):
        answer = p
    else:
        idx = balanced_index(p)
        u = p[:idx+1]
        v = p[idx+1:]
        if isCorrect(u):
            answer = u+solution(v)
        else:
            tmp = ""
            for i in range(1, len(u)-1):
                if u[i] == "(":
                    tmp += ")"
                else:
                    tmp += "("
            answer = "("+solution(v)+")"+tmp
    return answer
