# 230127
# time limit

#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'numWays' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING_ARRAY words
#  2. STRING target
#
from itertools import product


def perm(arr, n):
    result = []
    if n ==0:
        return [[]]
    for i, elem in enumerate(arr):
        for P in perm(arr[:i] + arr[i:], n-1):
            result += [[elem]+P]
    return result

def numWays(words, target):
    l = len(target)

    # words = ['valya', 'lyglb', 'vldoh']
    # target = 'val'
    # l = 3
    # word_group = perm(words, l)
    word_group = product(words, repeat=l)
    # print(word_group)
    
    res = 0
    for group in word_group:
        idx = 0
        cur = 0
        
    #     # print(group)
    #     l = len(group)
    #     for char in target:
    #         # print(char)
    #         flag = 0
    #         while True:
    #             if idx >= len(group):
    #                 flag = 1
    #                 break
    #             if char in group[idx]:
    #                 idx += 1
    #                 break
    #             else:
    #                 idx += 1
    #         # idx += 1
    #         if flag == 1:
    #             break
            
    #     print(idx)
    #     if idx != len(group):
    #         res += 1
            
            
        for val in group:
            find_val = val[cur:len(val)]
            # print(find_val)
            if target[idx] in find_val:
                # print("target = ", target[idx])
                cur = find_val.find(target[idx]) + cur + 1
                idx += 1
                
            if idx >= len(target):
                # print(group)
                res += 1
                break
            
            
    return res
            
            
        
    # Write your code here
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    words_count = int(input().strip())

    words = []

    for _ in range(words_count):
        words_item = input()
        words.append(words_item)

    target = input()

    result = numWays(words, target)

    fptr.write(str(result) + '\n')

    fptr.close()
