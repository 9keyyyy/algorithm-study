# 230214
# 그래프 BFS

from collections import deque

n, l, r = map(int, input().split())

dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

graph = [list(map(int, input().split())) for _ in range(n)]

def check_possible(a, b):
    n = a - b
    if n < 0:
        n = b - a
    if n >= l and n <= r:
        return True
    

def bfs(y, x, idx):
    q = deque()
    q.append([y, x])
    visited[y][x] = idx
    total_num = 1
    total_value = graph[y][x]

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if visited[ny][nx] != 0:
                continue
            
            if check_possible(graph[y][x], graph[ny][nx]):
                visited[ny][nx] = idx
                total_num += 1
                total_value += graph[ny][nx]
                q.append([ny, nx])

    return total_num, total_value
    

def move(total_num, total_value, idx):
    num = total_value//total_num
    for i in range(n):
        for j in range(n):
            if visited[i][j] == idx:
                graph[i][j] = num

sum = 0        


while True:
    visited = [[0]*n for _ in range(n)]
    idx = 1
    flag = True

    for i in range(n):
        for j in range(n):
            idx += 1
            if visited[i][j] == 0:
                total_n, total_v = bfs(i, j, idx)
                if total_n == 1:
                    continue
                flag = False
                move(total_n, total_v, idx)

    if flag:
        break

    sum += 1

print(sum)