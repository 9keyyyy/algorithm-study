# 230626
# BFS

import sys
input = sys.stdin.readline

from collections import deque

n, k = map(int, input().split())
arr = [0]*(100001)

q = deque()
q.append(n)

while q:
    idx = q.popleft()

    if idx == k:
        print(arr[idx])
        break

    if 0 <= idx - 1 <= 100000 and arr[idx - 1] == 0:
        arr[idx - 1] = arr[idx] + 1
        q.append(idx - 1)
    
    if 0 <= idx + 1 <= 100000 and arr[idx + 1] == 0:
        arr[idx + 1] = arr[idx] + 1
        q.append(idx + 1)
        
    if 0 <= idx * 2 <= 100000 and arr[idx * 2] == 0:
        arr[idx * 2] = arr[idx] + 1
        q.append(idx * 2)
