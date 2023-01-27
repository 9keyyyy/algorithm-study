# 230127
# pass

#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getGroupedAnagrams' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING_ARRAY words as parameter.
#

def getGroupedAnagrams(words):
    

    n = len(words)
    for i in range(n):
        words[i] = sorted(words[i])
    
    flag = [i for i in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            if words[i] == words[j]:
                flag[j] = flag[i] 
                
    uniqSet = set(flag)
    
    return len(uniqSet)
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    words_count = int(input().strip())

    words = []

    for _ in range(words_count):
        words_item = input()
        words.append(words_item)

    result = getGroupedAnagrams(words)

    fptr.write(str(result) + '\n')

    fptr.close()
