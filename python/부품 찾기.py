def binary_search(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)
    else:
        return binary_search(array, target, mid + 1, end)


n = int(input())
array = list(map(int, input().split()))
m = int(input())
l = list(map(int, input().split()))

array.sort()
for v in l:
    result = binary_search(array, v, 0, n - 1)
    if result != None:
        print('yes', end=' ')
    else:
        print('no', end=' ')
