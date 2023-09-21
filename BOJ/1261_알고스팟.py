# 230921
# BFS 다익스트라
import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(n)]
dist = [[-1]*m for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

q = deque()
q.append((0, 0))
dist[0][0] = 0

while q:
    y, x = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= m or ny < 0 or ny >= n:
            continue
        if dist[ny][nx] == -1:
            if arr[ny][nx] == 0:
                dist[ny][nx] = dist[y][x]
                q.appendleft(((ny, nx)))
            else:
                dist[ny][nx] = dist[y][x] + 1
                q.append((ny, nx))

print(dist[n-1][m-1])


