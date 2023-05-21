T = int(input())
for test_case in range(1, T + 1):
    n = int(input())

    car_available = [0] * 21
    result = 0

    for i in range(n):
        inp = list(map(int, input().split()))

        if inp[0] == 1:
            car_available[inp[1]] = 1
        else:
            if car_available[inp[1]] == 1 and inp[1] > result:
                result = inp[1]

    print("#%d %d" % (test_case, result))
