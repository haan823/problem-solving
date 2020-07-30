#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int map[4][8];
int tmp[8];
int k;
int task[100][2];
int status[4];

void clock_wise(int num)
{
    for (int i = 0; i < 8; i++)
    {
        tmp[(i + 1) % 8] = map[num][i];
    }
    for (int i = 0; i < 8; i++)
    {
        map[num][i] = tmp[i];
    }
}

void counter_clock_wise(int num)
{
    for (int i = 0; i < 8; i++)
    {
        tmp[(i + 7) % 8] = map[num][i];
    }
    for (int i = 0; i < 8; i++)
    {
        map[num][i] = tmp[i];
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++)
        {
            map[i][j] = tmp[j] - '0';
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> task[i][0] >> task[i][1];
    }

    for (int i = 0; i < k; i++)
    {
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        vector<int> visit(4, 0);
        q.push(make_pair(task[i][0], task[i][1]));
        visit[task[i][0] - 1] = 1;
        while (!q.empty())
        {
            v.push_back(q.front());
            int now_number = q.front().first;
            int now_task = q.front().second;
            q.pop();
            status[now_number - 1] = now_task;
            visit[now_number - 1] = 1;
            if (now_number + 1 <= 4 && !visit[now_number + 1 - 1])
            {
                int nxt_number = now_number + 1;
                int nxt_task;
                if (map[now_number - 1][2] == map[nxt_number - 1][6])
                {
                    nxt_task = 0;
                }
                else
                {
                    if (now_task == 1)
                    {
                        nxt_task = -1;
                    }
                    else if(now_task == 0){
                        nxt_task = 0;
                    }
                    else
                    {
                        nxt_task = 1;
                    }
                }
                q.push(make_pair(nxt_number, nxt_task));
            }
            if (now_number - 1 >= 1 && !visit[now_number - 1 - 1])
            {
                int nxt_number = now_number - 1;
                int nxt_task;
                if (map[now_number - 1][6] == map[nxt_number - 1][2])
                {
                    nxt_task = 0;
                }
                else
                {
                    if (now_task == 1)
                    {
                        nxt_task = -1;
                    }
                    else if(now_task == 0){
                        nxt_task = 0;
                    }
                    else
                    {
                        nxt_task = 1;
                    }
                }
                q.push(make_pair(nxt_number, nxt_task));
            }
        }
        for(int j=0; j<v.size(); j++){
            if(v[j].second == 1){
                clock_wise(v[j].first-1);
            }
            else if(v[j].second == -1){
                counter_clock_wise(v[j].first-1);
            }
            else{
                continue;
            }
        }
    }

    int answer;
    answer = (map[0][0] * 1) + (map[1][0] * 2) + (map[2][0] * 4) + (map[3][0] * 8);
    cout << answer;
}