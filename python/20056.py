from pprint import pprint
import sys
sys.stdin = open("input.txt", "r")
N, M, K = map(int, input().split())

board = [[[] for _ in range(N)] for _ in range(N)]
info = []
for _ in range(M):
    r, c, m, s, d = map(int, input().split())
    board[r-1][c-1].append([r, c, m, s, d])
    info.append([r, c, m, s, d])
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

for _ in range(K):
    for i in range(len(info)):
        r, c, m, s, d = info[i]
        dx, dy = s*dir[d][0], s*dir[d][1]
        nx, ny = (r+dx)%N, (c+dy)%N
        board[nx-1][ny-1].append([nx, ny, m, s, d])
        board[r-1][c-1].remove([r, c, m, s, d])
    for i in range(N):
        for j in range(N):
            if len(board[i][j]) > 1:
                m = 0
                s = 0
                d = []
                for k in range(len(board[i][j])):
                    m += board[i][j][k][2]
                    s += board[i][j][k][3]
                    d.append(board[i][j][k][4]%2)
                m //= 5
                if m != 0:
                    s //= len(board[i][j])
                    if d == [0]*len(board[i][j]) or d == [1]*len(board[i][j]):
                        board[i][j] = [[i+1, j+1, m, s, 0], [i+1, j+1, m, s, 2], [i+1, j+1, m, s, 4], [i+1, j+1, m, s, 6]]
                    else:
                        board[i][j] = [[i + 1, j + 1, m, s, 1], [i + 1, j + 1, m, s, 3], [i + 1, j + 1, m, s, 5],
                                       [i + 1, j + 1, m, s, 7]]
                else:
                    board[i][j] = []

        info = []
        for i in range(N):
            for j in range(N):
                if board[i][j] != []:
                    info += board[i][j]
        M = len(info)

    ans = 0
    for i in range(N):
        for j in range(N):
            for k in range(len(board[i][j])):
                ans += board[i][j][k][2]

print(ans)