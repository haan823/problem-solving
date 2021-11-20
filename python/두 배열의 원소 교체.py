n, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a = sorted(a, reverse=True)
b = sorted(b, reverse=True)

result = 0

for i in range(n-k):
    result += a[i]
for i in range(k):
    result += b[i]

print(result)