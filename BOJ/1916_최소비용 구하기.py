# 230628
# 다익스트라 (우선순위 큐)

import sys
input = sys.stdin.readline

from heapq import heappush, heappop

n = int(input())
m = int(input())

graph = [[]*n for _ in range(n+1)]

for i in range(m):
    s, e, w = map(int, input().split())
    graph[s].append((e, w))

s, e = map(int, input().split())

def dijkstra(graph, start):
    distances = [int(1e9)] * (n+1)
    distances[start] = 0
    q = []
    heappush(q, [distances[start], start])

    while q:
        dist, node = heappop(q)

        if distances[node] < dist:
            continue

        for next_node, next_dist in graph[node]:
            distance = dist + next_dist
            if distance < distances[next_node]:
                distances[next_node] = distance
                heappush(q, [distance, next_node])
    
    return distances
    
dist_start = dijkstra(graph, s)
print(dist_start[e])