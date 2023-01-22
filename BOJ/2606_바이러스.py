# 230122
# BFS, DFS

'''
# ver1. BFS

from collections import deque

n = int(input())    # node
v = int(input())    # edge
graph = [[] for i in range(n+1)]
visited = [0]*(n+1)

# print("visited = ", visited)

for i in range(v):  # create graph
    a, b = map(int, input().split())
    graph[a] += [b]
    graph[b] += [a]

visited[1] = 1
queue = deque([1])

while queue:
    c = queue.popleft()
    for nx in graph[c]:
        if visited[nx] == 0:
            queue.append(nx)
            visited[nx] = 1

print(sum(visited)-1)
'''

# ver2. DFS

n = int(input())    # node
v = int(input())    # edge
graph = [[] for i in range(n+1)]
visited = [0]*(n+1)

for i in range(v):  # create graph
    a, b = map(int, input().split())
    graph[a] += [b]
    graph[b] += [a]


def dfs(c):
    visited[c] = 1
    for nx in graph[c]:
        if visited[nx] == 0:
            dfs(nx)

dfs(1)

print(sum(visited)-1)
