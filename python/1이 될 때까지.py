N, K = map(int, input().split())

result = 0

while True:
    if N % K == 0:
        result += N // K
        break
    N -= 1
    result += 1

print(result)