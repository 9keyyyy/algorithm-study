# 240319
# dict, 구현

from collections import defaultdict

def solution(genres, plays):
    answer = []
    
    dict_first = defaultdict(int)
    dict_second = defaultdict(list)
    

    for i, (g, p) in enumerate(zip(genres, plays)):
        dict_first[g] += p
        dict_second[g].append((i, p))

    for (k, v) in sorted(dict_first.items(), key=lambda x:x[1], reverse=True):
        for (i, p) in sorted(dict_second[k], key=lambda x:x[1], reverse=True)[:2]:
            answer.append(i)

    return answer
