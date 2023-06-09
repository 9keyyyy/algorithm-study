# 230609
# 누적합

n, k = map(int, input().split())
arr = list(map(int, input().split()))

total = 0
for i in range(k):
    total += arr[i]

max_value = total

for i in range(k, n):
    total += arr[i]
    total -= arr[i-k]

    if total > max_value:
        max_value = total

print(max_value)