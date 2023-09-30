# 230929
# dijkstra
import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize

def dijkstra(start):
    q = []
    dist = [INF] * (N+1)

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
    
    return dist


N, M, X = map(int, input().split())

graph = [[] for _ in range(N+1)]


for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

result = 0
for i in range(1, N + 1):
    go = dijkstra(i)
    back = dijkstra(X)
    result = max(result, go[X] + back[i])

print(result)