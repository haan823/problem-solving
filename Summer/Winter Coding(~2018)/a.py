def solution(total_sp, skills):
    answer = []
    dic = {}
    k = 1
    for i in skills:
        k += 1
        if i[0] in dic:
            dic[i[0]].append(i[1])
        else:
            lst = []
            lst.append(i[1])
            dic[i[0]] = lst
        if i[1] not in dic:
            lst = []
            dic[i[1]] = lst

    result = {}
    n = 1
    while dic:
        tmp = []
        for key, value in dic.items():
            if not value:
                result[key] = n
                tmp.append(key)
        for i in tmp:
            del dic[i]
        for key, value in dic.items():
            for i in tmp:
                if i in value:
                    dic[key].remove(i)
        n += 1

    for i in dic.items():
        print(i)

    for i in result.items():
        print(i)
    return answer


skills = [[1, 2], [1, 3], [3, 6], [3, 4], [3, 5]]
solution(20, skills)
