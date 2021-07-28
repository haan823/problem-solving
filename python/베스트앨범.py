def solution(genres, plays):
    answer = []
    dic = {}
    for i in range(len(genres)):
        g = genres[i]
        p = plays[i]
        if g in dic.keys():
            dic[g][0] += p
            dic[g][1][i] = p
        else:
            dic[g] = [p, {i : p}]
    sorted_dic = sorted(dic.items(), key = lambda x: (-x[1][0]))
    for sd in sorted_dic:
        sorted_sorted_dic = sorted(sd[1][1].items(), key = lambda x: (-x[1], x[0]))
        for i in range(len(sorted_sorted_dic)):
            if i>1:
                break
            answer.append(sorted_sorted_dic[i][0])
    return answer