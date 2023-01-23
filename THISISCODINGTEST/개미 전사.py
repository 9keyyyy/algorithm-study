# 230123
# DP

n = int(input())
array = list(map(int, input().split()))

cache = [0]*100

cache[0] = array[0]
cache[1] = max(array[1], array[0])


# 반복문 ver
for i in range(2, n):
    cache[i] = max(array[i] + cache[i-2], cache[i-1])

'''
# 재귀 ver
def sol(i):
    if i <= 1:
        return cache[i]

    cache[i] = max(array[i]+sol(i-2), sol(i-1))
    return cache[i]

sol(n-1)

'''
print(cache[n-1])


