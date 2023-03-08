# 230309
# 백트래킹ß
n, m = map(int, input().split())
s = []
visited = [False]*(n+1)

def dfs():
    if len(s) == m:
        print(' '.join(map(str, s))) # s 내 요소 공백 기준 조인
        return
    
    for i in range(1, n+1):
        if visited[i]:
            continue
        visited[i] = True
        s.append(i)
        dfs()
        s.pop()
        visited[i] = False

dfs()
