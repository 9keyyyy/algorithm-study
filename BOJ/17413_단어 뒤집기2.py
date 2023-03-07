# 230307
# 구현

s = input()
flag = [0]*len(s)

i = 0
while True:
    if s[i] == '<':
        flag[i] = 1

        while True:
            flag[i] = 1
            if s[i] == '>':
                break
            i += 1

    elif s[i] == ' ':
        flag[i] = 1

    i += 1
    if i == len(s):
        break



res = ""     
i = 0
while True:
    if flag[i] == 1:
        print(res, end="")
        res = ""
        print(s[i], end="")
    else:
        res = s[i] + res

    i += 1
    if i == len(s):
        print(res)
        break

