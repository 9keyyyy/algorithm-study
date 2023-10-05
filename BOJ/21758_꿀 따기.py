# 231005
# 누적합

import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

ans=0

#i번째 원소까지의 누적합
prefix=[] 
prefix.append(data[0]) 

for i in range(1,n): 
    prefix.append(prefix[i-1]+data[i]) 
    
#case1 - left
for i in range(1,n-1): 
    ans=max(ans,prefix[n-2]+prefix[i-1]-data[i])

#case2 - right
for i in range(1, n-1): 
    ans = max(ans, prefix[n-1] - data[0] - data[i] + prefix[n-1] - prefix[i]) 
   
#case3 - middle
for i in range(1,n-1): 
    ans=max(ans,prefix[n-2] - data[0] + data[i])
       
print(ans)