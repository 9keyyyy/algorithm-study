from collections import deque

# 0 : 바위
area = [[1, 1, 0, 1, 1],
        [0, 1, 0, 1, 1],
        [1, 1, 0, 1, 1],
        [1, 1, 0, 1, 1]]

cage = [1, 3]
dx = [-1, 0, 0, 1]
dy = [0, 1, -1, 0]

n = len(area)
m = len(area[0])
arr = [[1000]*m for _ in range(n)]
arr[cage[0]][cage[1]] = 1

q = deque()
q.append([cage[0], cage[1]])
# print("n, m", n, m)
while q:
    y, x = q.popleft()
    # print("y, x", y, x)
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or ny >= n or nx < 0 or nx >= m:
            continue
        if area[ny][nx] == 0:
            arr[ny][nx] = arr[y][x]
            continue
        # print("ny, nx", ny, nx)
        if arr[ny][nx] == 1000:
            arr[ny][nx] = arr[y][x] + 1
            q.append([ny, nx])

for i in range(n):
    print(arr[i])
    