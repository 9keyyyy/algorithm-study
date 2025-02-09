# 20250209
from collections import deque

def bfs(maps):
    dx = [-1, 0, 0, 1]
    dy = [0, 1, -1, 0]
    q = deque()
    q.append((0, 0))
    
    while q:
        y, x = q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny >= len(maps) or ny < 0 or nx >= len(maps[0]) or nx < 0:
                continue
            
            if maps[ny][nx] == 0:
                continue
            
            if maps[ny][nx] == 1:
                maps[ny][nx] = maps[y][x] + 1
                q.append((ny, nx))
                
    return maps[len(maps)-1][len(maps[0])-1]
    

def solution(maps):
    answer = bfs(maps)
    return answer if answer != 1 else -1
