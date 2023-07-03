# 230704
# 우선순위 큐
import sys
input = sys.stdin.readline

from heapq import heappush, heappop

n = int(input())
q = []

for i in range(n):
    num = int(input())
    if num == 0:
        if len(q) == 0:
            print(0)
        else:
            print(heappop(q))
    else:
        heappush(q, num)
