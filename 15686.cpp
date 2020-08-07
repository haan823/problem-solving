#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, first_chicken_num;
int min_num = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<int>> house_loc;
vector<vector<int>> chicken_loc;
vector<int> permu;

int count_chicken_distance(vector<vector<int>> chicken_loc, int x, int y)
{
    int min_distance = 987654321;
    for (int i = 0; i < chicken_loc.size(); i++)
    {
        int distance = abs(x - chicken_loc[i][0]) + abs(y - chicken_loc[i][1]);
        if (distance < min_distance)
        {
            min_distance = distance;
        }
    }
    return min_distance;
}

int count_total_chicken_distance(vector<vector<int>> chicken_loc, vector<vector<int>> house_loc)
{
    int sum = 0;
    for (int i = 0; i < house_loc.size(); i++)
    {
        sum += count_chicken_distance(chicken_loc, house_loc[i][0], house_loc[i][1]);
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmpv;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            tmpv.push_back(tmp);
            if (tmp == 1)
            {
                house_loc.push_back({i, j});
            }
            else if (tmp == 2)
            {
                chicken_loc.push_back({i, j});
            }
        }
        map.push_back(tmpv);
    }

    first_chicken_num = chicken_loc.size();

    for (int i = 0; i < first_chicken_num - m; i++)
    {
        permu.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        permu.push_back(1);
    }

    do
    {
        vector<vector<int>> new_chicken_loc;
        int now_total_chicken_distance;
        for (int i = 0; i < permu.size(); i++)
        {
            if (permu[i] == 1)
            {
                new_chicken_loc.push_back(chicken_loc[i]);
            }
        }
        now_total_chicken_distance = count_total_chicken_distance(new_chicken_loc, house_loc);
        if (min_num > now_total_chicken_distance)
        {
            min_num = now_total_chicken_distance;
        }

    } while (next_permutation(permu.begin(), permu.end()));

    cout << min_num;
}