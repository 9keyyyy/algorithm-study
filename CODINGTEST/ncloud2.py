# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    num = [0]*10
    for i in range(len(S)):
        num[int(S[i])] += 1
    
    res = ""
    for i in range(9, -1, -1):
        if num[i] == 0:
            continue
        
        if i == 0 and res == "":
            continue

        if num[i] >= 2:
            while True:
                if num[i] - 2 >= 0:
                    res += str(i)
                else:
                    break
                num[i] -= 2
        # print(i, res)
        
    
    flag = -1
    for i in range(9, -1, -1):
        if num[i] == 0:
            continue
        flag = i
        num[i] -= 1
        break

    if flag == -1:
        return res + ''.join(reversed(res))
    else:
        return res + str(flag) + ''.join(reversed(res))



    





    