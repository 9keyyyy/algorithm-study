# 230213
# 그래프 BFS

from collections import deque

n, m = map(int, input().split())

dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

distance = [list(map(int, input().split())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]

def bfs(y, x):
    q = deque()
    q.append([y, x])
    visited[y][x] = 1

    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue
            if visited[ny][nx] == 1 or distance[ny][nx] == 0:
                continue
            visited[ny][nx] = 1
            distance[ny][nx] = distance[y][x] + 1
            q.append([ny, nx])


for i in range(n):
    for j in range(m):
        if distance[i][j] == 2:
            y, x = i, j
            distance[i][j] = 0

bfs(y, x)

for i in range(n):
    for j in range(m):
        if visited[i][j] == 0 and distance[i][j] == 1:
            distance[i][j] = -1


for i in range(n):
    for j in range(m):
        print(distance[i][j], end=" ")
    print()