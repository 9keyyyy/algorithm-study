# 230218
# greedy

n = int(input())

conf = [list(map(int, input().split())) for _ in range(n)]

conf.sort(key = lambda x: (x[1], x[0]))
sum = 1
end_time = conf[0][1]

for i in range(1, len(conf)):
    if end_time <= conf[i][0]:
        end_time = conf[i][1]
        sum += 1

print(sum)
