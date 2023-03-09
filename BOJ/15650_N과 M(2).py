# 230309
# 백트래킹

n, m = map(int, input().split())
s = []
visited = [False] * (n+1)

def dfs(idx):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(idx, n+1):
        if visited[i]:
            continue

        s.append(i)
        visited[i] = True
        dfs(i + 1)
        s.pop()
        visited[i] = False


dfs(1)
