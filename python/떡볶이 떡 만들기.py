n, m = map(int, input().split())
input_data = list(map(int, input().split()))
start = 0
end = max(input_data)
result = 0
while start <= end:
    total = 0
    mid = (start + end) // 2
    for i in input_data:
        if i > mid:
            total += (i - mid)
    if total >= m:
        result = mid
        start = mid + 1
    else:
        end = mid - 1

print(result)