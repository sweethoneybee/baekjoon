def solution(participant, completion):
    answer = ''
    c = {}
    for name in completion:
        if name in c:
            c[name] += 1
        else:
            c[name] = 1
    for p in participant:
        if p not in c:
            answer = p
            break
        elif c[p] == 0:
            answer = p
            break
        else:
            c[p] -= 1
    return answer
