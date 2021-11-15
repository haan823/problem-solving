input_data = str(input())

x = int(input_data[1]) - 1
y = int(ord(input_data[0]) - ord('a'))

dx = [-2, -1, 1, 2, 2, 1, -1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

count = 0

for d in range(8):
    nx = x + dx[d]
    ny = y + dy[d]
    if 0 <= nx < 8 and 0 <= ny < 8:
        count += 1

print(count)
