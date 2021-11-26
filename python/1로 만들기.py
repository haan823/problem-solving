n = int(input())

d = [0] * 30001

for x in range(2, n + 1):
    d[x] = d[x - 1] + 1
    if x % 2 == 0:
        d[x] = min(d[x], d[x // 2] + 1)
    if x % 3 == 0:
        d[x] = min(d[x], d[x // 3] + 1)
    if x % 5 == 0:
        d[x] = min(d[x], d[x // 5] + 1)

print(d[n])
