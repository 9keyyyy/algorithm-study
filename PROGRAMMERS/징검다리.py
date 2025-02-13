# 20230213
# 이분탐색
def solution(distance, rocks, n):
    answer = 0
    
    rocks.append(distance)
    rocks.sort()
    
    start = 0
    end = distance 
    
    while start <= end:
        mid = (start + end) // 2 
        
        previous = 0 
        count = 0
        for rock in rocks:
            if rock - previous < mid:
                count += 1
                if count > n: break 
            else:
                previous = rock
        
        if count > n:
            end = mid - 1 
        else:
            answer = mid 
            start = mid + 1
    
    return answer
