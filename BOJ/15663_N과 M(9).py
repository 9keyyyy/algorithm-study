# 230515
# 백트래킹

n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []
visited = [False]*(n+1)

arr.sort()

def dfs():
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    before = 0
    for i in range(len(arr)):
        if visited[i] or before == arr[i]:
            continue
        visited[i] = True
        before = arr[i]
        s.append(arr[i])
        dfs()
        visited[i] = False
        s.pop()

dfs()
