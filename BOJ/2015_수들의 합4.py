# 230621
# 누적합

import sys
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

sum_dict = {0:1}
sum_val = 0
ans = 0

for i in arr:
    sum_val += i
    if sum_val - k in sum_dict.keys():
        ans += sum_dict[sum_val-k]
    
    if sum_val in sum_dict.keys():
        sum_dict[sum_val] += 1
    else:
        sum_dict[sum_val] = 1

print(ans)