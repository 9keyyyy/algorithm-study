# 230701
# 백트래킹

import sys
input = sys.stdin.readline

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
visited = [False for _ in range(n)]
diff = 1e9


def dfs(depth, cur):
    global diff
    if depth == n//2:
        start, link = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    start += arr[i][j]
                elif not visited[i] and not visited[j]:
                    link += arr[i][j]
        
        diff = min(diff, abs(start-link))
        return

    for i in range(cur, n):
        visited[i] = True
        dfs(depth+1, i+1)
        visited[i] = False

dfs(0, 0)
print(diff)