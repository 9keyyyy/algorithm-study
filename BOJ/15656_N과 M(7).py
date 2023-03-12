# 230313
# 백트래킹


n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []

arr.sort()
def dfs():
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(len(arr)):
        s.append(arr[i])
        dfs()
        s.pop()

dfs()
