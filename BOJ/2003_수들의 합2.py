# 230608
# 투포인터

n, m = map(int, input().split())
arr = list(map(int, input().split()))

s , e = 0, 0
cnt = 0
total = 0

while True:
    if total >= m:
        if total == m:
            cnt += 1
        total -= arr[s]
        s += 1
    else:
        if e >= n:
            break
        total += arr[e]
        e += 1

print(cnt)