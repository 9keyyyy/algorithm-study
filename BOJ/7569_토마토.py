# 230521
# BFS

from collections import deque

dx = [-1, 0, 0, 1, 0, 0]
dy = [0, 1, -1, 0, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

m, n, h = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(n)] for __ in range(h)]
q = deque()

for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                q.append([i, j, k])


def bfs():
    result = 0

    while q:
        z, y, x = q.popleft()

        for i in range(6):
            nz = z + dz[i]
            ny = y + dy[i]
            nx = x + dx[i]
            if nx < 0 or ny < 0 or nz < 0 or nx >= m or ny >= n or nz >= h:
                continue
            if box[nz][ny][nx] == 0:
                box[nz][ny][nx] = box[z][y][x] + 1
                if box[nz][ny][nx] > result:
                    result = box[nz][ny][nx]
                q.append([nz, ny, nx])

    return result


result = bfs()

if result != 0:
    result -= 1

for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 0:
                result = -1


print(result)

