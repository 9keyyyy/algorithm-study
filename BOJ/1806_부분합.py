# 230605
# 투포인터

n, s = map(int, input().split())
arr = list(map(int, input().split()))
start = arr[0]
res = 100001
i, j = 0, 0

while True:
    if start >= s:
        start -= arr[i]
        res = min(res, j - i + 1)
        i += 1
    else:
        j += 1
        if j == n:
            break
        start += arr[j]

if res == 100001:
    print(0)
else:
    print(res)
