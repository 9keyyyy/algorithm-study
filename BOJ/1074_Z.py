# 230520
# 분할정복

n, r, c = map(int, input().split())
result = 0


def find_rc(y, x, size):
    global result

    # 좌표를 찾았을 때 출력 후 종료
    if y == r and x == c:
        print(result)
        exit(0)

    # 현재 사분면에 찾는 좌표가 없으면 result에 크기 더함
    if not (y <= r < y + size and x <= c < x + size):
        result += size * size
        return

    # 1/2/3/4분면 차례로 탐색
    find_rc(y, x, size // 2)                            # 1사분면
    find_rc(y, x + size // 2, size // 2)                # 2사분면
    find_rc(y + size // 2, x, size // 2)                # 3사분면
    find_rc(y + size // 2, x + size // 2, size // 2)    # 4사분면


find_rc(0, 0, 2 ** n)
