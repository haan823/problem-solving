import sys
sys.stdin = open("input.txt",'r')
n = int(input())
board = [[int(x) for x in input().split()] for _ in range(n)]

ans = 0

rate_left = [[0,0,2,0,0],[0,10,7,1,0],[5,'a',0,0,0],[0,10,7,1,0],[0,0,2,0,0]]
rate_down = [[0,0,0,0,0],[0,1,0,1,0],[2,7,0,7,2],[0,10,'a',10,0],[0,0,5,0,0]]
rate_right = [[0,0,2,0,0],[0,1,7,10,0],[0,0,0,'a',5],[0,1,7,10,0],[0,0,2,0,0]]
rate_up = [[0,0,5,0,0],[0,10,'a',10,0],[2,7,0,7,2],[0,1,0,1,0],[0,0,0,0,0]]

def spread(ans, board, rate, nx, ny):
    a, b = nx-2, ny-2

    temp = 0
    for i in range(5):
        for j in range(5):
            if rate[i][j] != 'a' and rate[i][j] != 0:
                if -1 < i+a < n and -1 < j+b < n:
                    board[i+a][j+b] += board[nx][ny] * rate[i][j] // 100
                else:
                    ans += board[nx][ny] * rate[i][j] // 100
                temp += board[nx][ny] * rate[i][j] // 100
            elif rate[i][j] == 'a':
                remain = (i, j)

    if -1 < remain[0] + a < n and -1 < remain[1] + b < n:
        board[remain[0] + a][remain[1] + b] += board[nx][ny] - temp
    else:
        ans += board[nx][ny] - temp
    board[nx][ny] = 0
    return board, ans

x,y = n//2,n//2
dir = [(0,-1),(1,0),(0,1),(-1,0)]
time = 1
flag = 0
while flag != 1:
    for i in range(4):
        dx, dy = dir[i]
        for j in range(time):
            x, y = x+dx, y+dy
            if i == 0:
                board, ans = spread(ans,board,rate_left,x,y)
            elif i == 1:
                board, ans = spread(ans,board,rate_down,x,y)
            elif i == 2:
                board, ans = spread(ans,board,rate_right,x,y)
            elif i == 3:
                board, ans = spread(ans,board,rate_up,x,y)

            if (x, y) == (0,0):
                flag = 1
                break
        if i == 1 or i == 3:
            time += 1
        if flag == 1:
            print(ans)
            break