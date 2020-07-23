#define _CRT_SECURE_NO_WARNIGNS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[8][8];
int tmp[8][8];
int n, m;
int res = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> v;
vector<int> c;

void virus(int x, int y)
{
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            continue;
        }
        else if (tmp[nx][ny] != 0)
        {
            continue;
        }
        else
        {
            tmp[nx][ny] = 2;
            virus(nx, ny);
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
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        c.push_back(0);
    }
    c[0] = 1;
    c[1] = 1;
    c[2] = 1;

    do
    {
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == 1)
            {
                tmp[v[i].first][v[i].second] = 1;
                a.push_back(make_pair(v[i].first, v[i].second));
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tmp[i][j] == 2)
                {
                    virus(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tmp[i][j] == 0)
                {
                    cnt++;
                }
            }
        }

        if (cnt > res)
        {
            res = cnt;
        }

    } while (prev_permutation(c.begin(), c.end()));

    cout << res << "\n";
}