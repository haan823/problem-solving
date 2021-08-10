def solution(bridge_length, weight, truck_weights):
    time = 0
    cur = []
    cur_weight = 0
    while True:
        if cur and cur_weight == 0:
            return time
        time += 1
        if len(cur) == bridge_length:
            cur_weight -= cur.pop(0)
        if truck_weights and cur_weight + truck_weights[0] <= weight:
            cur.append(truck_weights[0])
            cur_weight += truck_weights[0]
            truck_weights.pop(0)
        else:
            cur.append(0)
    return time