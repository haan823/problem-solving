#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[50][50];
int n, m, r, c, d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

int main()
{
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    while (true)
    {
        if (map[r][c] == 1 || r < 0 || c < 0 || r >= n || c >= m)
        {
            break;
        }
        bool flag1 = false;
        if (map[r][c] == 0)
        {
            map[r][c] = 2;
            cnt++;
        }
        int nr, nc, nd;
        for (int i = 3; i >= 0; i--)
        {
            nd = (d + i) % 4;
            nr = r + dx[nd];
            nc = c + dy[nd];
            if (map[nr][nc] == 1 || map[nr][nc] == 2 || nr < 0 || nc < 0 || nr >= n || nc >= m)
            {
                continue;
            }
            else
            {
                r = nr;
                c = nc;
                d = nd;
                flag1 = true;
                break;
            }
        }
        if (flag1)
        {
            continue;
        }
        else
        {
            r -= dx[d];
            c -= dy[d];
        }
    }

    cout << cnt;
}