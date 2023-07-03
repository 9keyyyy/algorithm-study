# 230701
# 백트래킹

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

home = []
chicken = []
for i in range(n):
    for j in range(n):
        if arr[i][j]==1:
            home.append([i, j])
        if arr[i][j]==2:
            chicken.append([i, j])

def calculate(res):
    total = 0
    for i in range(len(home)):
        min_val = 1e9
        for j in range(m):
            dist = abs(home[i][0] - res[j][0]) + abs(home[i][1] - res[j][1])
            if dist < min_val:
                min_val = dist
        total += min_val
    return total

res = []
ans = 1e9
def dfs(cur):
    global ans
    if len(res) == m:
        dist = calculate(res)
        if dist < ans:
            ans = dist
        return
    
    for i in range(cur, len(chicken)):
        res.append(chicken[i])
        dfs(i+1)
        res.pop()


dfs(0)
print(ans)