import math
from itertools import permutations

def solution(numbers):
    answer = []
    for i in range(1, len(numbers)+1):
        arr = list(permutations(numbers, i))
        for j in range(len(arr)):
            num = int(''.join(map(str, arr[j])))
            if isPrime(num):
                answer.append(num)
    answer = list(set(answer))
    return len(answer)

def isPrime(number):
    if number == 0 or number == 1:
        return False
    else:
        for i in range(2, int(math.sqrt(number))+1):
            if number % i == 0:
                return False
        return True