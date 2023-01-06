def binary_search(arr, n):
    left = 0
    right = len(arr)-1
    while left <= right:
        mid = (left+right)//2
        if arr[mid] >= n:
            right = mid-1
        else:
            left = mid+1
    return right


def solution(words, queries):
    answer = []
    arr = [[] for _ in range(10001)]
    reversed_arr = [[] for _ in range(10001)]
    for w in words:
        arr[len(w)].append(w)
        reversed_arr[len(w)].append(w[::-1])
    for i in range(10001):
        arr[i].sort()
        reversed_arr[i].sort()

    for q in queries:
        if q[0] == "?":
           # 역방향 탐색
            leftIdx = binary_search(
                reversed_arr[len(q)], q.replace("?", "a")[::-1])
            rightIdx = binary_search(
                reversed_arr[len(q)], q.replace("?", "z")[::-1])
        else:
            # 정방향 탐색
            leftIdx = binary_search(arr[len(q)], q.replace("?", "a"))
            rightIdx = binary_search(arr[len(q)], q.replace("?", "z"))
        answer.append(rightIdx-leftIdx)
    return answer
