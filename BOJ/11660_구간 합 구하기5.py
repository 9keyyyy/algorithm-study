# 230529
# DP
import sys

input = sys.stdin.readline
n, m = map(int, input().split())

matrix = [list(map(int, input().split())) for _ in range(n)]
cache = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
  for j in range(1, n+1):
    cache[i][j] = cache[i-1][j] + cache[i][j-1] - cache[i-1][j-1] + matrix[i-1][j-1]

for i in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(cache[x2][y2] - cache[x1-1][y2] - cache[x2][y1-1] + cache[x1-1][y1-1])
