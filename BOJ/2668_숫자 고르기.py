# 230216
# 그래프

n = int(input())
graph = [[] for _ in range(n+1)]

for i in range(1, n+1):
    graph[i].append(int(input()))

result = []
cnt = 0

def dfs(s):
    global result, cnt

    visited[s] = True

    for now in graph[s]:
        if visited[now] == False:
            dfs(now)

        elif visited[now] == True and finished[now] == False:
            if now not in result:
                cnt += 1
                result.append(now)
                
        else:
            return
        
    finished[s] = True


for i in range(1, n+1):
    visited = [False]*(n+1)
    finished = [False]*(n+1)
    dfs(i)

result.sort()
print(cnt)
for i in result:
    print(i)



