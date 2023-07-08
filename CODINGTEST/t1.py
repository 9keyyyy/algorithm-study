def dfs(s, N, res, visited, ori):

    if len(res) == N:
        result = ''.join(map(str, res))
        # print(ori, result)
        if result in ori:
            return int(result)

        return -1


    
    for i in range(len(s)-1, -1, -1):
        if visited[i]:
            continue
        res.append(s[i])
        visited[i] = True
        tmp = dfs(s, N, res, visited, ori)
        if tmp != -1:
            return tmp

        res.pop()
        visited[i] = False
    
    return tmp


def solution(s, N):
    answer = 0
    
    ss = ""
    visited = [False]*(N+1)
    for i in range(1, N+1):
        ss += str(i)
    
    res = []

    answer = dfs(ss, N, res, visited, s)

    return answer