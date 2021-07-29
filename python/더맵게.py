import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while len(scoville) >= 2:
        if scoville[0] >= K:
            return answer
        tmp1 = heapq.heappop(scoville)
        tmp2 = heapq.heappop(scoville)
        tmp3 = tmp1 + (tmp2 * 2)
        heapq.heappush(scoville, tmp3)
        answer += 1
    if scoville[0] >= K:
            return answer
    return -1