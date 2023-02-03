# 230203
# 구현

r, c, n = map(int, input().split())

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

graph = [list(input().strip()) for _ in range(r)]
bomb_check = [[0]*c for _ in range(r)]
bomb_time = [[0]*c for _ in range(r)]

for i in range(r):
    for j in range(c):
        if graph[i][j] == 'O':
            bomb_check[i][j] = 1


def time_check():
    for i in range(r):
        for j in range(c):
            if bomb_check[i][j] == 1:
                bomb_time[i][j] += 1
            
            
def install_bomb():
    for i in range(r):
        for j in range(c):
            if bomb_check[i][j] == 0:
                graph[i][j] = 'O'
                bomb_check[i][j] = 1

def exploration():
    for i in range(r):
        for j in range(c):
            if bomb_time[i][j] == 3:
                graph[i][j] = '.'
                bomb_check[i][j] = 0
                bomb_time[i][j] = 0

                for k in range(4):
                    nx = j + dx[k]
                    ny = i + dy[k]
                    if nx < 0 or nx >= c or ny < 0 or ny >= r or bomb_time[ny][nx] == 3:
                        continue
                    graph[ny][nx] = '.'
                    bomb_check[ny][nx] = 0
                    bomb_time[ny][nx] = 0
                

def print_graph():
    for i in range(r):
        for j in range(c):
            print(graph[i][j], end="")
        print()


for i in range(1, n+1):
    time_check()
    if i == 1:
        continue
    if i % 2 == 1:
        exploration()
    if i % 2 == 0:
        install_bomb()


print_graph()