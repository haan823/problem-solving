#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct _ball
{
    int depth;
    int rx, ry, bx, by;
} ball;

int gx, gy, irx, iry, ibx, iby;
int n, m, res = -1;
int map[10][10];
int visit[10][10][10][10];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void move(int &x, int &y, int d)
{
    while (true)
    {
        x += dir[d][0];
        y += dir[d][1];
        if (map[x][y] == 1)
        {
            x -= dir[d][0];
            y -= dir[d][0];
        }
        else if (map[x][y] == 2)
        {
            break;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '.')
            {
                map[i][j] = 0;
            }
            else if (tmp == '#')
            {
                map[i][j] = 1;
            }
            else if (tmp == 'O')
            {
                map[i][j] = 2;
                gx = i;
                gy = j;
            }
            else if (tmp == 'R')
            {
                irx = i;
                iry = j;
            }
            else if (tmp == 'B')
            {
                ibx = i;
                iby = j;
            }
        }
    }

    queue<ball> q;
    q.push({0, irx, iry, ibx, iby});
    visit[irx][iry][ibx][iby] = true;

    while (!q.empty())
    {
        ball tmp = q.front();
        q.pop();

        if (tmp.depth > 10)
        {
            break;
        }
        if (tmp.rx == gx && tmp.ry == gy)
        {
            res = tmp.depth;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int rx = tmp.rx, ry = tmp.ry;
            int bx = tmp.bx, by = tmp.by;
            move(rx, ry, i);
            move(bx, by, i);

            if (bx == gx && by == gy)
            {
                continue;
            }
            if (rx == gx && ry == gy)
            {
                switch (i)
                {
                case 0:
                    tmp.rx < tmp.bx ? rx-- : bx--;
                    break;
                case 1:
                    tmp.rx < tmp.bx ? bx++ : rx++;
                    break;
                case 2:
                    tmp.ry < tmp.by ? ry-- : by--;
                case 3:
                    tmp.ry < tmp.by ? by++ : ry++;
                }
            }

            if (!visit[rx][ry][bx][by])
            {
                ball nxt = {tmp.depth + 1, rx, ry, bx, by};
                q.push(nxt);
                visit[rx][ry][bx][by] = true;
            }
        }
    }

    printf("%d", res);
    return 0;
}