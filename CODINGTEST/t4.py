

def solution(maxSize, actions):
    answer = 0
    recent = []
    back = []
    front = []
    cur = ""
    
    for a in actions:
        if a == "B":
            if len(back) >= 1:
                if len(recent) >= 1 :
                    front.append(recent[-1])
                cur = back.pop()
                if cur in recent:
                    recent.remove(cur)
                if len(recent) == maxSize:
                    recent.pop(0)
                recent.append(cur)



        elif a == "F":
            if len(front) >= 1:
                if len(recent) >= 1 :
                    back.append(recent[-1])
                cur = front.pop()
                if cur in recent:
                    recent.remove(cur)
                if len(recent) == maxSize:
                    recent.pop(0)
                recent.append(cur)
        
        else:
            front = []
            cur = a
            if len(recent) >= 1 :
                back.append(recent[-1])
            if a in recent:
                recent.remove(a)
            if len(recent) == maxSize:
                recent.pop(0)
            recent.append(a)

        print(recent, back, front)


    return recent[::-1]