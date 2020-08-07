#include <iostream>
#include <vector>

using namespace std;

int n, m, h; // 세로선, 가로선, 높이
int min_num = 987654321;
vector<vector<int>> map;

bool sadari2()
{
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        for (int j = 1; j <= h; j++)
        {
            if (map[j][k])
            {
                k++;
            }
            else if (k > 1 && map[j][k - 1])
            {
                k--;
            }
        }
        if (i != k)
        {
            return false;
        }
    }
    return true;
}

void dfs(pair<int, int> visit, int depth)
{
    if (depth >= min_num)
    {
        return;
    }
    else if (sadari2())
    {
        if (depth < min_num)
        {
            min_num = depth;
            return;
        }
    }
    if (depth == 3)
    {
        return;
    }
    int x = visit.first;
    int y = visit.second + 2;
    for (int i = x; i <= h; i++, y = 1)
    {
        for (int j = y; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                j++;
            }
            else
            {
                map[i][j] = 1;
                dfs({i, j}, depth + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i <= h; i++)
    {
        vector<int> tmp;
        for (int j = 0; j <= n; j++)
        {
            tmp.push_back(0);
        }
        map.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    dfs({1, -1}, 0);
    if (min_num == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << min_num;
    }
}