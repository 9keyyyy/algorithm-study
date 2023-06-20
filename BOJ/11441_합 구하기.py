# 230620
# 누적합
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

presum = [0]*(n+1) 
presum[0] = arr[0]
for i in range(1, n):
    presum[i] = presum[i - 1] + arr[i]


m = int(input())
for i in range(m):
    i, j = map(int, input().split())
    if i == 1:
        print(presum[j-1])
    else:
        print(presum[j-1]-presum[i-2])
