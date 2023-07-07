# 230704
# 세그먼트 트리

import sys, math
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 8) # 재귀 깊이 제한 늘리기

def initMin(start, end, idx):
    if start == end:
        tree_min[idx] = arr[start]
        return tree_min[idx]
    
    mid = (start + end)//2
    tree_min[idx] = min(initMin(start, mid, idx*2), initMin(mid+1, end, idx*2+1))
    return tree_min[idx]

def initMax(start, end, idx):
    if start == end:
        tree_max[idx] = arr[start]
        return tree_max[idx]
    
    mid = (start + end)//2
    tree_max[idx] = max(initMax(start, mid, idx*2), initMax(mid+1, end, idx*2+1))
    return tree_max[idx]    

def queryMin(start, end, left, right, idx):
    if right < start or left > end:
        return 1000000000
    
    if left <= start and end <= right:
        return tree_min[idx]
    
    mid = (start + end)//2
    return min(queryMin(start, mid, left, right, idx*2), queryMin(mid+1, end, left, right, idx*2+1))

def queryMax(start, end, left, right, idx):
    if right < start or left > end:
        return 0
    
    if left <= start and end <= right:
        return tree_max[idx]
    
    mid = (start + end)//2
    return max(queryMax(start, mid, left, right, idx*2), queryMax(mid+1, end, left, right, idx*2+1))



n, m = map(int, input().split())

tree_min = [0] * 4 * n
tree_max = [0] * 4 * n

arr = []
for i in range(n):
    arr.append(int(input()))

initMin(0, n-1, 1)
initMax(0, n-1, 1)

for i in range(m):
    a, b = map(int, input().split())

    print(queryMin(0, n-1, a-1, b-1, 1), queryMax(0, n-1, a-1, b-1, 1))
