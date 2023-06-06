# 230606
# 누적합

n, m = map(int, input().split())
arr = list(map(int, input().split()))
cache = [0]*(n+1)

cache[1] = arr[0]
for i in range(1, n+1):
    cache[i] = arr[i-1] + cache[i-1]

for i in range(m):
    s, e = map(int, input().split())
    print(cache[e] - cache[s-1])