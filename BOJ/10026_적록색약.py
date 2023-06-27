# 230627
# 그래프

import sys
input = sys.stdin.readline

from collections import deque

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

n = int(input())

arr = [list(input().strip()) for _ in range(n)]
visited = [[0]*n for _ in range(n)]

def bfs(a, b):
    q = deque()
    q.append([a, b])
    visited[a][b] = 1

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or ny >= n or nx < 0 or nx >= n:
                continue

            if visited[ny][nx] == 0 and arr[ny][nx] == arr[y][x]:
                visited[ny][nx] = 1
                q.append([ny, nx])

cnt_1 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j)
            cnt_1 += 1

for i in range(n):
    for j in range(n):
        if arr[i][j] == 'R':
            arr[i][j] = 'G'

visited = [[0]*n for _ in range(n)]

cnt_2 = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs(i, j)
            cnt_2 += 1

print(cnt_1, cnt_2)
