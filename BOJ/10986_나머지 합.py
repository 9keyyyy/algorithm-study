# 230621
# 누적합

import sys
input = sys.stdin.readline

n, k = map(int, input().split())
data = list(map(int, input().split()))

sum_list = [0 for _ in range(1000)]
sum_list[0] = 1

sum_ = 0
answer = 0

for i in data:
    sum_ += i
    answer += sum_list[sum_ % k]
    sum_list[sum_ % k] += 1

print(answer)