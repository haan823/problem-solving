#include <iostream>
#include <vector>

using namespace std;

vector<int> input(10, 0);
vector<pair<int, int>> status(4, make_pair(3, 0));
int max_num;
vector<vector<int>> map = {{0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40},
                           {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40},
                           {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40},
                           {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40}};

void dfs(vector<pair<int, int>> now_status, int depth, int sum)
{
    if (depth >= 10)
    {
        if (max_num < sum)
        {
            max_num = sum;
        }
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (now_status[i].second >= map[now_status[i].first].size())
            {
                continue;
            }
            else
            {
                vector<pair<int, int>> nxt_status(4, make_pair(3, 0));
                for (int j = 0; j < 4; j++)
                {
                    nxt_status[j].first = now_status[j].first;
                    nxt_status[j].second = now_status[j].second;
                }
                nxt_status[i].second += input[depth];
                if (nxt_status[i].second < map[nxt_status[i].first].size())
                {
                    if (nxt_status[i].second == 5 && nxt_status[i].first == 3)
                    {
                        nxt_status[i].first = 0;
                    }
                    else if (nxt_status[i].second == 10 && nxt_status[i].first == 3)
                    {
                        nxt_status[i].first = 1;
                    }
                    else if (nxt_status[i].second == 15 && nxt_status[i].first == 3)
                    {
                        nxt_status[i].first = 2;
                    }
                    int cnt = 0;
                    for (int j = 0; j < 4; j++)
                    {
                        if (nxt_status[i].first == nxt_status[j].first && map[nxt_status[j].first][nxt_status[j].second] == map[nxt_status[i].first][nxt_status[i].second])
                        {
                            cnt++;
                        }
                        else if (nxt_status[i].second >= map[nxt_status[i].first].size() - 4 && nxt_status[j].second >= map[nxt_status[j].first].size() - 4)
                        {
                            if (map[nxt_status[j].first][nxt_status[j].second] == map[nxt_status[i].first][nxt_status[i].second])
                            {
                                cnt++;
                            }
                        }
                    }
                    if (cnt > 1)
                    {
                        continue;
                    }
                    else
                    {
                        int tmp = depth + 1;
                        int tmp_sum = sum + map[nxt_status[i].first][nxt_status[i].second];
                        dfs(nxt_status, tmp, tmp_sum);
                    }
                }
                else
                {
                    int tmp = depth + 1;
                    dfs(nxt_status, tmp, sum);
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> input[i];
    }

    dfs(status, 0, 0);

    cout << max_num;
}