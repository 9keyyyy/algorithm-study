# 240318
# dfs

def solution(n, computers):
    answer = 0
    visited = [0]*n
    
    for i in range(n):
        if not visited[i]:
            dfs(i, n, computers, visited)
            answer += 1
    
    return answer

def dfs(s, n, computers, visited):
    visited[s] = 1
    for i in range(n):
        if visited[i] or i==s:
            continue
        if computers[s][i]:
            dfs(i, n, computers, visited)
    
    
