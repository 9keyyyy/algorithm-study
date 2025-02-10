# 20250210
# DFS, 백트래킹
def solution(tickets):
    answer = []
    visited = [False]*len(tickets)
    
    def dfs(airport, path):
        if len(path) == len(tickets)+1:
            answer.append(path.copy())
            return
        
        for idx, ticket in enumerate(tickets):
            if airport == ticket[0] and visited[idx] == False:
                visited[idx] = True
                path.append(ticket[1])
                dfs(ticket[1], path)
                path.pop()
                visited[idx] = False
                
    dfs("ICN", ["ICN"])
    
    answer.sort()
        
    return answer[0]
