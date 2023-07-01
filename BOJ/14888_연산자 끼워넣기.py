# 230701
# 백트래킹

import sys
input = sys.stdin.readline

n = int(input())
num = list(map(int, input().split()))
exp = list(map(int, input().split()))

cur = 0
min_val = 1000000000
max_val = -100000000

def dfs(cur, res):
    global min_val, max_val
    if cur == n:
        min_val = min(min_val, res)
        max_val = max(max_val, res)
        return

    if exp[0] > 0:
        exp[0] -= 1
        dfs(cur + 1, res + num[cur])
        exp[0] += 1

    if exp[1] > 0:
        exp[1] -= 1
        dfs(cur + 1, res - num[cur])
        exp[1] += 1

    if exp[2] > 0:
        exp[2] -= 1
        dfs(cur + 1, res * num[cur])
        exp[2] += 1

    if exp[3] > 0:
        exp[3] -= 1
        dfs(cur + 1, int(res/num[cur]))
        exp[3] += 1

dfs(1, num[0])

print(max_val)
print(min_val)