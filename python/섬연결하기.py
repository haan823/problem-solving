def solution(n, costs):
    answer = 0
    l = [i for i in range(n)]
    costs.sort(key = lambda x: x[2])
    for cost in costs:
        p0 = parent(l, cost[0])
        p1 = parent(l, cost[1])
        if p0 != p1:
            if p0 < p1:
                l[p1] = p0
            else:
                l[p0] = p1
            answer += cost[2]
    return answer

def parent(l, n):
    if l[n] == n:
        return n
    return parent(l, l[n])