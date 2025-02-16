# 20250216
# 투포인터

def solution(sequence, k):
    l = r = 0
    answer = [0, len(sequence)]
    sum = sequence[0]

    while True:
        if sum < k:
            r += 1
            if r == len(sequence): 
                break
            sum += sequence[r]
        else:
            if sum == k:
                if r-l < answer[1]-answer[0]:
                    answer = [l, r]
            sum -= sequence[l]
            l += 1
    return answer


"""
시간 초과 (완전탐색)

def solution(sequence, k):
    answer = []
    n = len(sequence)
    
    l = n
    for i in range(n):
        cur = sequence[i]
        if cur == k:
            answer = [i, i]
            break
        for j in range(i+1, n):
            cur = cur + sequence[j]
            if cur == k and j-i < l:
                answer = [i, j]
                l = j-i
            if cur > k:
                break
    return answer
"""
