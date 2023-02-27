# 230228
# 브루트포스, 백트래킹

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

visited = [0] * n
ans = 99999

def res():
    global ans
    start, link = 0, 0
    for i in range(n):
        for j in range(n):
            if visited[i] and visited[j]:
                start += graph[i][j]
            elif not visited[i] and not visited[j]:
                link += graph[i][j]
    
    ans = min(ans, abs(start-link))

def sol(iter):
    if iter == n:
        res()
        return
    visited[iter] = 1
    sol(iter + 1)
    visited[iter] = 0
    sol(iter + 1)

sol(0)
print(ans)