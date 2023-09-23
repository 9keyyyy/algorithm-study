# 230923
# dijkstra
import heapq
import sys

input = sys.stdin.readline
INF = sys.maxsize

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0

    while q:
        distance, now = heapq.heappop(q)

        if dist[now] < distance:
            continue

        for node in graph[now]:
            cost = distance + node[1]
            if cost < dist[node[0]]:
                dist[node[0]] = cost
                heapq.heappush(q, (cost, node[0]))


V, E = map(int, input().split())
k = int(input())
dist = [INF] * (V+1)
graph = [[] for _ in range(V+1)]

for i in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

dijkstra(k)

for i in range(1, V+1):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])
