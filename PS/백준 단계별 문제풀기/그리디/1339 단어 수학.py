import heapq
n = int(input())
pq = []
arr = [0]*26
for i in range(n):
    now = input()
    for j in range(len(now)):
        arr[ord("A")-ord(now[j])] += pow(10, len(now)-1-j)

for i in range(26):
    heapq.heappush(pq, -arr[i])
result = 0
for i in range(9, -1, -1):
    now = -heapq.heappop(pq)
    result += now*i

print(result)
