# 231005
# 누적합
import sys
input = sys.stdin.readline

T = int(input())

for i in range(T):
    N = int(input())
    cache = [0]*N
    arr = list(map(int, input().split()))

    cache[0] = arr[0]
    for j in range(1, N):
        cache[j] = max(arr[j], cache[j-1]+arr[j])

    print(max(cache))