# 230311
# 백트래킹

n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []
visited = [False]*(n+1)

arr.sort()
def dfs(idx):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(idx, len(arr)):
        if visited[i]:
            continue
        s.append(arr[i])
        visited[i] = True
        dfs(i)
        s.pop()
        visited[i] = False

dfs(0)

