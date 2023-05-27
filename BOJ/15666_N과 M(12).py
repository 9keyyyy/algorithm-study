# 230527
# 백트래킹

n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []
arr.sort()


def dfs(idx):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    before = 0
    for i in range(idx, len(arr)):
        if before == arr[i]:
            continue
        before = arr[i]
        s.append(arr[i])
        dfs(i)
        s.pop()


dfs(0)
