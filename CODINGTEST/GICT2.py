# 230127
# pass

#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'cardinalitySort' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY nums as parameter.
#


def cardinalitySort(nums):
    nums = sorted(nums)
    n = len(nums)
    res = [[0, nums[i]] for i in range(n)]
    
    for i in range(n):
        x = nums[i]
        y = ""

        while x > 0:
            y = str(x%2) + y
            x //= 2

        res[i][0] = y.count('1')
        
    res = sorted(res)
    
    output = []
    for v in res:
        output.append(v[1])
    
    return output

    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nums_count = int(input().strip())

    nums = []

    for _ in range(nums_count):
        nums_item = int(input().strip())
        nums.append(nums_item)

    result = cardinalitySort(nums)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
