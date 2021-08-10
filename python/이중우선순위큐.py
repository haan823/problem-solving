import heapq

def solution(operations):
    answer = []
    heap = []
    for op in operations:
        o, num = op.split(" ")
        num = int(num)
        if o == 'I':
            heap.append(num)
        else:
            if num == 1:
                max_heap = []
                for i in heap:
                    heapq.heappush(max_heap, (-i, i))
                if max_heap:
                    tmp = heapq.heappop(max_heap)
                    heap.remove(tmp[1])
            elif num == -1:
                min_heap = heap
                heapq.heapify(min_heap)
                if min_heap:
                    heapq.heappop(min_heap)
                heap = min_heap
    if heap:
        answer.append(max(heap))
        answer.append(min(heap))
    else:
        answer.append(0)
        answer.append(0)
    return answer