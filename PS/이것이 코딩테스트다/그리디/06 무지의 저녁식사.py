import heapq


def solution(food_times, k):
    answer = 0
    if sum(food_times) <= k:
        return -1

    h = []
    for i in range(len(food_times)):
        heapq.heappush(h, (food_times[i], i+1))

    sum_value = 0
    pre = 0

    l = len(food_times)

    while sum_value+(h[0][0]-pre)*l <= k:
        now = heapq.heappop(h)[0]
        sum_value += (now-pre)*l
        l -= 1
        pre = now

    result = sorted(h, key=lambda x: x[1])
    return result[(k-sum_value) % l][1]
