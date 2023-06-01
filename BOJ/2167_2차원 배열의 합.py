# 230601
# 누적합

n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]
cache = [[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        cache[i][j] = arr[i-1][j-1] + cache[i][j-1] + cache[i-1][j] - cache[i-1][j-1]

k = int(input())

for i in range(k):
    i, j, x, y = map(int, input().split())
    print(cache[x][y] + cache[x][j-1] + cache[i-1][y] - cache[i-1][j-1])
