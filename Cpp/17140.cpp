#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, k, t, rnum = 3, cnum = 3;
int map[101][101];
priority_queue<pair<int, int>> pq;

struct compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second > b.second;
        }
    }
};

void solution()
{
    while (t <= 100)
    {

        if (map[r][c] == k)
        {
            cout << t;
            return;
        }

        if (rnum >= cnum)
        {
            int new_cnum = 0;
            for (int i = 1; i <= rnum; i++)
            {
                int current_cnum;
                vector<int> cnt(101, 0);
                priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
                for (int j = 1; j <= cnum; j++)
                {
                    if (map[i][j] != 0)
                    {
                        cnt[map[i][j]]++;
                    }
                }
                for (int j = 1; j <= 100; j++)
                {
                    if (cnt[j] != 0)
                    {
                        pq.push(make_pair(j, cnt[j]));
                    }
                }
                vector<int> tmp;
                while (!pq.empty())
                {
                    tmp.push_back(pq.top().first);
                    tmp.push_back(pq.top().second);
                    pq.pop();
                }
                if (tmp.size() > 100)
                {
                    for (int j = 1; j <= 100; j++)
                    {
                        map[i][j] = tmp[j - 1];
                    }
                    current_cnum = 100;
                }
                else
                {
                    for (int j = 1; j <= tmp.size(); j++)
                    {
                        map[i][j] = tmp[j - 1];
                    }
                    current_cnum = tmp.size();
                    if (current_cnum < cnum)
                    {
                        for (int j = current_cnum + 1; j <= cnum; j++)
                        {
                            map[i][j] = 0;
                        }
                    }
                }
                if (current_cnum > new_cnum)
                {
                    new_cnum = current_cnum;
                }
            }
            cnum = new_cnum;
        }
        else if (rnum < cnum)
        {
            int new_rnum = 0;
            for (int i = 1; i <= cnum; i++)
            {
                int current_rnum;
                vector<int> cnt(101, 0);
                priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
                for (int j = 1; j <= rnum; j++)
                {
                    if (map[j][i] != 0)
                    {
                        cnt[map[j][i]]++;
                    }
                }
                for (int j = 1; j <= 100; j++)
                {
                    if (cnt[j] != 0)
                    {
                        pq.push(make_pair(j, cnt[j]));
                    }
                }
                vector<int> tmp;
                while (!pq.empty())
                {
                    tmp.push_back(pq.top().first);
                    tmp.push_back(pq.top().second);
                    pq.pop();
                }
                if (tmp.size() > 100)
                {
                    for (int j = 1; j <= 100; j++)
                    {
                        map[j][i] = tmp[j - 1];
                    }
                    current_rnum = 100;
                }
                else
                {
                    for (int j = 1; j <= tmp.size(); j++)
                    {
                        map[j][i] = tmp[j - 1];
                    }
                    current_rnum = tmp.size();
                    if (current_rnum < rnum)
                    {
                        for (int j = current_rnum + 1; j <= rnum; j++)
                        {
                            map[j][i] = 0;
                        }
                    }
                }
                if (current_rnum > new_rnum)
                {
                    new_rnum = current_rnum;
                }
            }
            rnum = new_rnum;
        }
        t++;
    }
    cout << -1;
    return;
}

int main()
{
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> map[i][j];
        }
    }
    solution();
}