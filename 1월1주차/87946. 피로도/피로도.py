def solution(k, dungeons):
    answer = -1
    n = len(dungeons)
    visited=[False] *n
    
    def DFS(cur_fatigue,count):
        nonlocal answer
        answer = max(answer,count)
        
        for i in range(n):
            if not visited[i]:
                fati,cons = dungeons[i]
                if cur_fatigue >=fati and cur_fatigue-cons >=0:
                    visited[i] = True
                    DFS(cur_fatigue-cons,count+1)
                    visited[i] = False
                    
    DFS(k,0)
        
    return answer