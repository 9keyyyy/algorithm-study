# 230201
# 그래프, BFS

from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = 1

    while q:
        start = q.popleft()
        for i in graph[start]:
            if visited[i] == 0:
                visited[i] = 1
                q.append(i)

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[b].append(a)

cnt = []

for i in range(1, n+1):
    visited = [0 for _ in range(n+1)]
    bfs(i)

    cnt.append(visited.count(1))

idx = 1

for i in cnt:
    if i == max(cnt):
        print(idx, end=" ")
    idx += 1

