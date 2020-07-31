#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt = 987654321;
int map[8][8];
int tmp_map[8][8];
vector<int> start;
vector<int> last;
vector<pair<int, pair<int, int>>> to_do;

void map_to_tmp()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp_map[i][j] = map[i][j];
        }
    }
}
void up(int x, int y)
{
    for (int i = x; i >= 0; i--)
    {
        if (tmp_map[i][y] == 0)
        {
            tmp_map[i][y] = 7;
        }
        else if (tmp_map[x][i] == 6)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void right(int x, int y)
{
    for (int i = y; i < m; i++)
    {
        if (tmp_map[x][i] == 0)
        {
            tmp_map[x][i] = 7;
        }
        else if (tmp_map[x][i] == 6)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void down(int x, int y)
{
    for (int i = x; i < n; i++)
    {
        if (tmp_map[i][y] == 0)
        {
            tmp_map[i][y] = 7;
        }
        else if (tmp_map[x][i] == 6)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void left(int x, int y)
{
    for (int i = y; i >= 0; i--)
    {
        if (tmp_map[x][i] == 0)
        {
            tmp_map[x][i] = 7;
        }
        else if (tmp_map[x][i] == 6)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}

void cctv(int num, int x, int y, int dir)
{
    if (num == 1)
    {
        if (dir == 0)
        {
        }
        else if (dir == 1)
        {
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6)
            {
                to_do.push_back(make_pair(map[i][j], make_pair(i, j)));
            }
        }
    }

    map_to_tmp();

    int size = to_do.size();
    for (int i = 0; i < to_do.size(); i++)
    {
    }
    do
    {
        cout <<
    } while (next_permutation(start, last));
}