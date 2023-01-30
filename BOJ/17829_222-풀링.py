# 320130
# 분할 정복

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

def sol(w, x, y):
    if w == 2:
        tmp = [board[x][y], board[x+1][y], board[x][y+1], board[x+1][y+1]]
        tmp.sort()
        return tmp[2]
        
        
    tmp = [sol(w//2, x, y), sol(w//2, x+w//2, y), sol(w//2, x, y+w//2), sol(w//2, x+w//2, y+w//2)]
    tmp.sort()
    return tmp[2]

print(sol(n, 0, 0))