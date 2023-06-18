# 230616
# graph

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def dfs(y, x):
    visited[y][x] = 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= n or nx < 0 or nx >= m:
            continue

        if visited[ny][nx] == 0 and arr[ny][nx] == 1:
            dfs(ny, nx)
    
    

t = int(input())

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

for i in range(t):
    m, n, k = map(int, input().split())
    cnt = 0
    arr = [[0]*(m+1) for _ in range(n+1)]
    visited = [[0]*(m+1) for _ in range(n+1)]

    for j in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1

    for j in range(n):
        for k in range(m):
            if visited[j][k] == 0 and arr[j][k] == 1:
                cnt += 1
                dfs(j, k)
    
    print(cnt)