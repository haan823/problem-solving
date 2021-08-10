def solution(people, limit):
    answer = 0
    people.sort()
    lp = 0
    rp = len(people)-1
    while lp < rp:
        if people[lp] + people[rp] <= limit:
            answer += 1
            lp += 1
            rp -= 1
        else:
            answer += 1
            rp -= 1
    if lp == rp:
        answer += 1
    return answer