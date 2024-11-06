# 241106
# DFS
def dfs(numbers, target, ans, depth):
    if len(numbers) == depth:
        if sum(numbers) == target:
            return ans + 1
        else:
            return ans
    
    ans = dfs(numbers, target, ans, depth + 1)
    numbers[depth]*=-1
    ans = dfs(numbers, target, ans, depth + 1)
    
    return ans

def solution(numbers, target):
    answer = dfs(numbers, target, 0, 0)
    return answer
