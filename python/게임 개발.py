N, M = map(int, input().split())
cx, cy, cd = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
count = 1

visit = [[0 for _ in range(M)] for _ in range(N)]
board = [list(map(int, input().split())) for _ in range(N)]

visit[cx][cy] = 1

while True:
    flag = False
    for i in range(4):
        nd = (cd + 3 - i) % 4
        nx = cx + dx[nd]
        ny = cy + dy[nd]
        if 0 <= nx < N and 0 <= ny < M:
            if visit[nx][ny] == 0 and board[nx][ny] == 0:
                count += 1
                visit[nx][ny] = 1
                cx = nx
                cy = ny
                cd = nd
                flag = True
                break
    if not flag:
        nx = cx - dx[cd]
        ny = cy - dy[cd]
        if 0 <= nx < N and 0 <= ny < M:
            if board[nx][ny] == 0:
                if visit[nx][ny] == 0:
                    count += 1
                    visit[nx][ny] = 1
                    cx = nx
                    cy = ny
                else:
                    cx = nx
                    cy = ny
            else:
                break

print(count)