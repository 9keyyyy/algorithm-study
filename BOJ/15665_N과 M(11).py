# 230520
# 백트래킹

n, m = map(int, input().split())

arr = list(map(int, input().split()))
s = []
arr.sort()


def dfs():
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    before = 0
    for i in range(len(arr)):
        if before == arr[i]:
            continue
        before = arr[i]
        s.append(arr[i])
        dfs()
        s.pop()


dfs()
