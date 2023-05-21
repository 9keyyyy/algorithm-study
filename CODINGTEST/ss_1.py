# problem 1. 레이저 발사기

T = int(input())
for test_case in range(1, T + 1):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]

    start = arr[0][0]
    cnt = 0

    for i in range(n):
        if start > arr[i][0]:
            continue

        cnt += 1
        start = arr[i][0] + arr[i][1] + 1

    print("#%d %d" % (test_case, cnt))