#include <iostream>
#include <vector>

using namespace std;

int n, m, t, x, d, k;

int map[51][51];
int check[51][51];

void invalid(int i, int j, int ni, int nj)
{
    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)
    {
        if (map[i][j] != -1 && map[i][j] == map[ni][nj])
        {
            check[i][j] = 1;
            check[ni][nj] = 1;
        }
    }
}

void update()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            check[i][j] = 0;
        }
    }
    bool flag = false;
    double sum = 0, cnt = 0, avg;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] != -1)
            {
                sum += map[i][j];
                cnt++;
            }
        }
    }
    if (cnt)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j == m)
                {
                    invalid(i, j, i, 1);
                    invalid(i, j, i, j - 1);
                }
                else if (j == 1)
                {
                    invalid(i, j, i, m);
                    invalid(i, j, i, j + 1);
                }
                else
                {
                    invalid(i, j, i, j - 1);
                    invalid(i, j, i, j + 1);
                }
                invalid(i, j, i - 1, j);
                invalid(i, j, i + 1, j);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (check[i][j] == 1)
                {
                    flag = true;
                    map[i][j] = -1;
                }
            }
        }
        avg = sum / cnt;
        if (!flag)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (map[i][j] != -1 && map[i][j] < avg)
                    {
                        map[i][j]++;
                    }
                    else if (map[i][j] != -1 && map[i][j] > avg)
                    {
                        map[i][j]--;
                    }
                }
            }
        }
    }
}
void rotate(int i, int d, int k)
{
    vector<int> tmp(m + 1, 0);
    if (d == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            tmp[(j + k - 1) % m + 1] = map[i][j];
        }
    }
    else
    {
        for (int j = 1; j <= m; j++)
        {
            tmp[(j + (m - k - 1)) % m + 1] = map[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        map[i][j] = tmp[j];
    }
}

void rotate_all(int x, int d, int k)
{
    for (int i = x; i <= n; i+=x)
    {
        rotate(i, d, k);
    }
}

int main()
{
    int answer = 0;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        cin >> x >> d >> k;
        rotate_all(x, d, k);
        update();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] != -1)
            {
                answer += map[i][j];
            }
        }
    }
    cout << answer;
}