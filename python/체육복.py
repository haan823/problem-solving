def solution(n, lost, reserve):
    _lost = set(lost) - set(reserve)
    _reserve = set(reserve) - set(lost)
    answer = n - len(_lost)
    for l in _lost:
        if l-1 in _reserve:
            _reserve.remove(l-1)
            answer += 1
        elif l+1 in _reserve:
            _reserve.remove(l+1)
            answer += 1
    return answer