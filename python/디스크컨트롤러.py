import heapq

def solution(jobs):
    answer = 0
    time = 0
    until = 0
    heap = []
    schedule = [[] for _ in range(1001)]
    for job in jobs:
        schedule[job[0]].append(job[1])
    for time in range(1001):
        for load in schedule[time]:
            heapq.heappush(heap, (load, time))
        if time >= until and heap:
            tmp = heapq.heappop(heap)
            answer += time - tmp[1] + tmp[0]
            until = time + tmp[0]
    while heap:
        tmp = heapq.heappop(heap)
        answer += until - tmp[1] + tmp[0]
        until += tmp[0]
    return answer // len(jobs)