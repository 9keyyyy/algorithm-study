# 230215
# DP

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
cache = [[0]*n for _ in range(n)]
cache[0][0] = 1

for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
           
        dy = i + graph[i][j]
        dx = j + graph[i][j]

        if dy > 0 and dy < n:
            cache[dy][j] += cache[i][j]

        if dx > 0 and dx < n:
            cache[i][dx] += cache[i][j]
    

print(cache[n-1][n-1])