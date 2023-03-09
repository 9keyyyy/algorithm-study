# 230309
# 백트래킹

n, m = map(int, input().split())
s = []

def dfs(idx):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(idx, n+1):
        s.append(i)
        dfs(i + 1)
        s.pop()


dfs(1)
