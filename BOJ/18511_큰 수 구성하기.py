from itertools import product

n, k = map(int, input().split())
data = list(map(str, input().split()))
l = len(str(n))

data.sort()

while True:
    tmp = list(product(data, repeat=l))
    ans = []

    for i in tmp:
        if int("".join(i)) <= n:
            ans.append(int("".join(i)))

    if len(ans) >= 1:
        print(max(ans))
        break
    else:
        l -= 1


    