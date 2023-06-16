# 230613
# 누적합
import sys
input = sys.stdin.readline

n, h = map(int, input().split())

bottom = [0] * (h+1)
top = [0] * (h+1)

min_cnt = n
range_cnt = 0

for i in range(n):
    if i % 2 == 0:
        bottom[int(input())] += 1
    else:
        top[int(input())] += 1

for i in range(h-1, 0, -1):
    bottom[i] += bottom[i+1]
    top[i] += top[i+1]

for i in range(1, h+1):
    cur = bottom[i] + top[h-i+1]
    if min_cnt > cur:
        min_cnt = cur
        range_cnt = 1
    elif min_cnt == cur:
        range_cnt += 1
    
print(min_cnt, range_cnt)