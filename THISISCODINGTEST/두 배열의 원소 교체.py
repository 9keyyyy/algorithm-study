# 230123
# 정렬

n, k = map(int, input().split())

arrA = map(int, input().split())
arrB = map(int, input().split())

arrA.sort()
arrB.sort(reverse=True)

for i in range(k):
    if(arrA[i]<arrB[i]):
        arrA[i], arrB[i] = arrB[i], arrA[i]
    else:
        break

print(sum(arrA))

'''
arrA.sort()
arrB.sort()

for i in range(k):
    if arrB[i] > arrA[n-1-i]:
        arrA[n-1-i] = arrB[i]
    else:
        break

print(sum(arrA))
'''