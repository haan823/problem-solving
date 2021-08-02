def solution(name):
    answer = 0
    change = [min(ord(i)-ord('A'), ord('Z')-ord(i)+1) for i in name]
    pos = 0
    while True:
        answer += change[pos]
        change[pos] = 0
        if sum(change) == 0:
            break
        left = 1
        right = 1
        while change[pos-left] == 0:
            left += 1
        while change[pos+right] == 0:
            right += 1
        if left >= right:
            answer += right
            pos += right
        else:
            answer += left
            pos -= left
    return answer