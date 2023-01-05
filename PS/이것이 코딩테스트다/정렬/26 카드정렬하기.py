import sys
import heapq
input = sys.stdin.readline

N = int(input())
arr = []
for i in range(N):
    heapq.heappush(arr, int(input()))

ans = 0
while len(arr) > 1:
    now1 = heapq.heappop(arr)
    now2 = heapq.heappop(arr)
    ans += (now1+now2)
    heapq.heappush(arr, now1+now2)
print(ans)
