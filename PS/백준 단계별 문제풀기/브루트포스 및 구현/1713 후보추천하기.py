n = int(input())
m = int(input())
arr = list(map(int, input().split()))
# 추천횟수가 가장 적은 학생의 사진 삭제
# 같으면 가장 오래된 사진 삭제
q1 = []  # 후보번호
q2 = []  # 추천수
for a in arr:
    if a in q1:
        for i in range(len(q1)):
            if q1[i] == a:
                q2[i] += 1
                break
    else:
        if len(q1) == n:
            count = min(q2)
            for i in range(n):
                if count == q2[i]:
                    q1.pop(i)
                    q2.pop(i)
                    q1.append(a)
                    q2.append(1)
                    break
        else:
            q1.append(a)
            q2.append(1)
q1.sort()
for i in range(len(q1)):
    print(q1[i], end=" ")
