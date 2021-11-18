# N, M = map(int, input().split())
# board = []
# for i in range(N):
#     board.append(list(map(int, input())))
#
# visit = [[0 for _ in range(M)] for _ in range(N)]
# dx = [-1, 0, 1, 0]
# dy = [0, 1, 0, -1]
# result = 987654321
#
# def dfs(cx, cy, count):
#     global result
#     if cx == N-1 and cy == M-1:
#         if count < result:
#             result = count
#         return
#     for i in range(4):
#         nx = cx + dx[i]
#         ny = cy + dy[i]
#         if nx>=0 and nx<N and ny>=0 and ny<M and board[nx][ny] == 1 and visit[nx][ny] == 0:
#             visit[nx][ny] = 1
#             dfs(nx, ny, count+1)
#             visit[nx][ny] = 0
#
# dfs(0, 0, 1)
#
# print(result)

from collections import deque

N, M = map(int, input().split())
board = []
for i in range(N):
    board.append(list(map(int, input())))
visit = [[0 for _ in range(M)] for _ in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
d = deque()
d.append([0, 0, 1])

def bfs(cx, cy, count):
    queue = deque()
    queue.append([cx, cy, count])
    visit[cx][cy] = 1
    while queue:
        node = queue.popleft()
        cx = node[0]
        cy = node[1]
        count = node[2]
        if cx == N-1 and cy == M-1:
            print(count)
            return
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0<=nx<N and 0<=ny<M and board[nx][ny] == 1 and visit[nx][ny] == 0:
                queue.append([nx, ny, count + 1])
                visit[nx][ny] = 1

bfs(0, 0, 1)