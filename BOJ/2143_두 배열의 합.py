# 230925
# 누적합

import bisect
import sys

input = sys.stdin.readline

T = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

aan, bbn = [], []
for i in range(n):
    for j in range(i + 1, n + 1):
        aan.append(sum(A[i:j]))
for i in range(m):
    for j in range(i + 1, m + 1):
        bbn.append(sum(B[i:j]))

aan.sort()
bbn.sort()

ans = 0
for i in range(len(aan)):
    bmp = T - aan[i]
    left = bisect.bisect_left(bbn, bmp)
    right = bisect.bisect_right(bbn, bmp)
    ans += (right - left)
print(ans)