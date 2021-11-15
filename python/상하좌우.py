N = int(input())
step = list(input().split())

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

sx = 0
sy = 0

for s in step:
    nx = 0
    ny = 0
    d = 0
    if s == 'L':
        d = 0
    elif s == 'R':
        d = 1
    elif s == 'U':
        d = 2
    else:
        d = 3
    nx = sx + dx[d]
    ny = sy + dy[d]
    if 0 <= nx < N and 0 <= ny < N:
        sx = nx
        sy = ny

print(sx + 1, sy + 1)
