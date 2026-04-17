# 비트마스킹
import sys

input = sys.stdin.readline

N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]

dp = [[float('inf')] * (N) for _ in range(1<<N)]
dp[1][0] = 0

for mask in range(1<<N):
    for i in range(N):
        if dp[mask][i] == float('inf'):
            continue
        for j in range(N):
            if W[i][j] == 0: 
                continue
            if mask & (1<<j): 
                continue
            dp[mask | (1<<j)][j] = min(dp[mask | (1<<j)][j], dp[mask][i]+W[i][j])
            
ans = float('inf')

for i in range(N):
    if W[i][0] == 0:
        continue
    ans = min(ans, dp[-1][i] + W[i][0])
    
print(ans)
