# 230127
# pass
# DP

#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'countOptions' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER people
#  2. INTEGER groups
#


def sol(p, n, r, cache):
    if p // n < r:
        return 0
    if n == 1 and r == 1:
        return 1
    if n == 2:
        return p//2 - (r-1)

    res = 0
    for i in range(1, p//2 + 1):
        if (p-i) // (n-1) < r:
            break
        if i >= r:
            if cache[p-i][n-1][i] != -1:
                res += cache[p-i][n-1][i]
            else:
                cache[p-i][n-1][i] = sol(p-i, n-1, i, cache)
                res += cache[p-i][n-1][i]
    
    return res
         

def countOptions(people, groups):
    cache = [[[-1 for p in range(people)] for g in range(groups)] for r in range(people)]
    return sol(people, groups, 1, cache)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    people = int(input().strip())

    groups = int(input().strip())

    result = countOptions(people, groups)

    fptr.write(str(result) + '\n')

    fptr.close()
