# 230529
from collections import deque
import sys

input = sys.stdin.readline

def bfs(idx):
    q = deque()
    q.append(idx)

    while q:
        cur = q.popleft()
        for node in graph[cur]:
            if parent[node] == 0:
                parent[node] = cur
                q.append(node)


n = int(input())
graph = [[] for _ in range(n+1)]
parent = [0] * (n+1)

# print(graph)
for i in range(n-1):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

bfs(1)

for i in range(2, n+1):
    print(parent[i])
# print(graph)
