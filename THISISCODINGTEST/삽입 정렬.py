# 230203
# 삽입 정렬 : 데이터가 거의 정렬되어 있을 때 효율적, O(n^2)

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i, 0, -1):   # i에서 1까지 감소하며 반복
        if array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
        else:
            break

print(array)

