# 230219   
# greedy

a, b = map(int, input().split())

sum = 1
while a < b:
    if b % 10 == 1:
        b = b // 10

    else:
        if b % 2 == 0:
            b = b // 2
        else:
            break
    sum += 1   

if a == b:
    print(sum)
else:
    print(-1)