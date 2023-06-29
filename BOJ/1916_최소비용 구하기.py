# 230628
# 다익스트라

n = int(input())
m = int(input())

graph = [[0]*n for _ in range(n)]

for i in range(m):
    s, e, w = map(int, input().split())
    graph[s][e] = w
    graph[e][s] = w
    
    