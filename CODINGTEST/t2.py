g = [[] for _ in range(101)]
visited = [0] * 101
f = 0
m = 0

def dfs(depth, idx, limit, target):
    global g, f, m, visited

    if visited[idx] == 1:
        return 
    visited[idx] = 1
    # print(depth, idx)
    if depth > limit:
        return 

    for c in g[idx]:
        # print(depth, c)
        if c not in g[target]:
            if c == target:
                continue
            g[target].append(c)
            m += 10
            f += 1
            # print("append! ", c, f, m)
        dfs(depth + 1, c, limit, target)
        


def solution(relationships, target, limit):

    for ff in relationships:
        a, b = ff
        if a not in g[b]:
            g[b].append(a)
        if b not in g[a]:
            g[a].append(b)

    tmp = len(g[target]) * 5
    visited[target] = 1
    dfs(1, target, limit, target)

    # print(f, m)
    return f+m+tmp
