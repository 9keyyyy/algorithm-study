# 230626
# BFS

import sys
input = sys.stdin.readline

from collections import deque

n, k = map(int, input().split())
arr = [-1]*(k+2)
arr[n] = 0

q = deque()
q.append(n)


while q:
    idx = q.popleft()
    # print("idx" , idx)
    # print(arr)
    if idx == k:
        print(arr[idx])
        break

    if idx - 1 >= 0 and arr[idx - 1] == -1:
        arr[idx - 1] = arr[idx] + 1
        q.append(idx - 1)
    
    if idx + 1 <= k + 1 and arr[idx + 1] == -1:
        arr[idx + 1] = arr[idx] + 1
        q.append(idx + 1)
        
    if idx * 2 <= k + 1 and arr[idx * 2] == -1:
        arr[idx * 2] = arr[idx] + 1
        q.append(idx * 2)
    
# print(arr)