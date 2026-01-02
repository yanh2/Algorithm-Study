from collections import Counter

def solution(topping):
    answer = 0
    right = Counter(topping)
    left = set()
    
    for x in topping[:-1]:
        left.add(x)
        right[x] -=1
        if right[x] ==0:
            del right[x]
        if len(right) == len(left):
            answer +=1
            
    return answer