# 230514
# 백트래킹

n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []

arr.sort()
def dfs(idx):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(idx, len(arr)):
        s.append(arr[i])
        dfs(i)
        s.pop()

dfs(0)
