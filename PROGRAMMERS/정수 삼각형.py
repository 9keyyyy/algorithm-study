# 240304
# DP
def solution(triangle):
    answer = 0
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            if j-1 < 0:
                triangle[i][j]+=triangle[i-1][j]
            elif j == len(triangle[i])-1:
                triangle[i][j]+=triangle[i-1][j-1]
            else:
                triangle[i][j]+=max(triangle[i-1][j-1], triangle[i-1][j])

    for arr in triangle:
        for n in arr:
            if answer < n:
                answer = n
