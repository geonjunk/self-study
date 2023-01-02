def isPossible(answer):    
    for a in answer:
        x,y,t=a
        if t==1:# 보
            if not ([x,y-1,0] in answer or [x+1,y-1,0] in answer or ([x-1,y,1] in answer and [x+1,y,1] in answer)):
                return False
        else:# 기둥
            if not (y==0 or [x,y,1] in answer or [x-1,y,1] in answer or [x,y-1,0] in answer):
                return False
    return True
def solution(n, build_frame):
    answer = []
    for b in build_frame:
        if b[3]==1:
            answer.append(b[:3])
            if not isPossible(answer):
                 answer.remove(b[:3])
        else:
            answer.remove(b[:3])
            if not isPossible(answer):
                answer.append(b[:3])
    answer.sort()
    return answer