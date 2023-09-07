# 230907
# DP
import sys
input = sys.stdin.readline

N = int(input())
T = []
P = []
dp = [0] * (N+1)
for i in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

for i in range(N):
    for j in range(i+T[i], N+1):
        if dp[j] < dp[i] + P[i]:
            dp[j] = dp[i] + P[i]

print(dp[N])