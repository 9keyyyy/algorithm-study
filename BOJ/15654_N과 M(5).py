# 230309
# 백트래킹

n, m = map(int, input().split())
arr = list(map(int, input().split()))
s = []
visited = [False]*10001

arr.sort()
def dfs():
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in arr:
        if visited[i]:
            continue
        s.append(i)
        visited[i] = True
        dfs()
        s.pop()
        visited[i] = False

dfs()


