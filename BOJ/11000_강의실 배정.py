# 230220   
# greedy, priority queue

import heapq

n = int(input())
class_time = [list(map(int, input().split())) for _ in range(n)]
class_time.sort()

class_queue = []
heapq.heappush(class_queue, class_time[0][1])


for i in range(1, n):
    if class_time[i][0] < class_queue[0]:
        heapq.heappush(class_queue, class_time[i][1])
    else:
        heapq.heappop(class_queue)
        heapq.heappush(class_queue, class_time[i][1])

print(len(class_queue))

