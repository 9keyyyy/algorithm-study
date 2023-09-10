# 230908
# BFS, 백트래킹
import sys
import copy
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def create_wall(cnt):
    if cnt == 3:
        bfs()
        return
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                board[i][j] = 1
                create_wall(cnt+1)
                board[i][j] = 0


def bfs():
    queue = deque()
    cur_board = copy.deepcopy(board)
    for i in range(N):
        for j in range(M):
            if cur_board[i][j] == 2:
                queue.append((i, j))

    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or ny >= N or nx < 0 or nx >= M:
                continue

            if cur_board[ny][nx] == 0:
                cur_board[ny][nx] = 2
                queue.append((ny, nx))
    
    global result
    cnt = 0
    for i in range(N):
        cnt += cur_board[i].count(0)
    
    result = max(result, cnt)

result = 0
create_wall(0)
print(result)