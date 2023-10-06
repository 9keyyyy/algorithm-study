# 231006
# BFS
import sys
from collections import deque
input = sys.stdin.readline

def bfs(a, b, height):
    global visited

    q = deque()
    q.append((a, b))
    visited[a][b] = 1

    while q:
        y, x = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            if visited[ny][nx] == 0 and height < area[ny][nx]:
                visited[ny][nx] = 1
                q.append((ny, nx))

N = int(input())
area = [list(map(int, input().split())) for _ in range(N)]
height = [0]*101

dy = [-1, 0, 0, 1]
dx = [0, -1, 1, 0]

for i in range(N):
    for j in range(N):
        cur = area[i][j]
        if height[cur] == 0:
            height[cur] = 1

ans = 1
for i in range(101):
    if height[i] == 0:
        continue

    cur = 0
    visited = [[0] * N for _ in range(N)]
    for j in range(N):
        for k in range(N):
            if visited[j][k] == 1:
                continue

            if i < area[j][k]:
                cur += 1
                bfs(j, k, i)
            else:
                visited[j][k] = 1

    ans = max(ans, cur)

print(ans)
