import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

arr.sort()
l = len(arr)
print(arr[(l-1)//2])
