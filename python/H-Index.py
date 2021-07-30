def solution(citations):
    answer = 0
    citations.sort(reverse = True)
    for i in range(len(citations)-1):
        print(i)
        print(citations[i])
        if i+1 <= citations[i] and i+1 >= citations[i+1]:
            answer = i+1
    if len(citations) <= citations[len(citations)-1]:
        answer = len(citations)
    return answer