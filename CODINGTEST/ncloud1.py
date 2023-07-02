# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# 2^20-1 = 1048575
def check_overflow(num):
    if num > 1048575:
        return True
    return False

def check_underflow(num):
    if num < 0:
        return True
    return False

def check_empty(stack):
    if len(stack) == 0:
        return True
    return False

def check_two(stack):
    if len(stack) < 2:
        return True
    return False

def solution(S):
    arr = S.split()

    stack = []
    for s in arr:
        if s == "POP":
            if check_empty(stack):
                return -1
            stack.pop()

        elif s == "DUP":
            if check_empty(stack):
                return -1
            stack.append(stack[-1])

        elif s == "+":
            if check_two(stack):
                return -1
            first = stack.pop()
            second = stack.pop()

            res = first + second
            if check_overflow(res):
                return -1

            stack.append(first + second)

        elif s == "-":
            if check_two(stack):
                return -1
            first = stack.pop()
            second = stack.pop()
            
            res = first - second
            if check_underflow(res):
                return -1

            stack.append(res)

        else:
            if check_overflow(int(s)) or check_underflow(int(s)):
                return -1
            stack.append(int(s))

    if len(stack) == 0:
        return -1
    return stack[-1]

