#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, cnt;
vector<vector<int>> map;
vector<vector<int>> A;
vector<vector<vector<int>>> tree(10, vector<vector<int>>(10)); // 나이
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_in_map(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void spring_summer()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tree[i][j].size())
            {
                sort(tree[i][j].begin(), tree[i][j].end());
                int k = 0;
                for (k = 0; k < tree[i][j].size(); k++)
                {
                    if (map[i][j] >= tree[i][j][k])
                    {
                        map[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int h = k; h < tree[i][j].size(); h++)
                {
                    map[i][j] += (tree[i][j][h] / 2);
                }
                tree[i][j].erase(tree[i][j].begin()+k, tree[i][j].end());
            }
        }
    }
}

void fall()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < tree[i][j].size(); k++)
            {
                if (tree[i][j][k] % 5 == 0)
                {
                    int cx = i;
                    int cy = j;
                    int nx, ny;
                    for (int h = 0; h < 8; h++)
                    {
                        nx = cx + dx[h];
                        ny = cy + dy[h];
                        if (is_in_map(nx, ny))
                        {
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] += A[i][j];
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp_A;
        vector<int> tmp_map;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            tmp_A.push_back(tmp);
            tmp_map.push_back(5);
        }
        A.push_back(tmp_A);
        map.push_back(tmp_map);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x - 1][y - 1].push_back(age);
    }

    for (int i = 0; i < k; i++)
    {
        spring_summer();
        fall();
        winter();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt += tree[i][j].size();
        }
    }
    cout << cnt;
    }