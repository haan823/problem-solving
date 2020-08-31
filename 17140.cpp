#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, k, rn = 3, cn = 3;
int map[100][100];

vector<int> sort(vector<int> v)
{
    int tmp[101] = {
        0,
    };
    for (int i = 0; i < v.size(); i++)
    {
        tmp[v[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq[101];
    for (int i = 1; i <= 100; i++)
    {
        if (tmp[i] != 0)
        {
            pq[tmp[i]].push(i);
        }
    }
    vector<int> res;
    for (int i = 1; i <= 100; i++)
    {
        int s = pq[i].size();
        for (int j = 0; j < s; j++)
        {
            res.push_back(pq[i].top());
            res.push_back(i);
            pq[i].pop();
        }
    }
    return res;
}

void r_calc()
{
    int nxt_cn = cn;
    for (int i = 0; i < rn; i++)
    {
        vector<int> cur_row;
        for (int j = 0; j < cn; j++)
        {
            cur_row.push_back(map[i][j]);
        }
        vector<int> nxt_row = sort(cur_row);
        if (nxt_row.size() > 100)
        {
            for (int j = 0; j < 100; j++)
            {
                map[i][j] = nxt_row[j];
            }
            nxt_cn = 100;
        }
        else
        {
            for (int j = 0; j < nxt_row.size(); j++)
            {
                map[i][j] = nxt_row[j];
            }
            if (nxt_row.size() > nxt_cn)
            {
                nxt_cn = nxt_row.size();
            }
        }
    }
    cn = nxt_cn;
}

void c_calc()
{
    int nxt_rn = rn;
    for (int i = 0; i < cn; i++)
    {
        vector<int> cur_column;
        for (int j = 0; j < rn; j++)
        {
            cur_column.push_back(map[j][i]);
        }
        vector<int> nxt_column = sort(cur_column);
        if (nxt_column.size() > 100)
        {
            for (int j = 0; j < 100; j++)
            {
                map[j][i] = nxt_column[j];
            }
            nxt_rn = 100;
        }
        else
        {
            for (int j = 0; j < nxt_column.size(); j++)
            {
                map[i][j] = nxt_column[j];
            }
            if (nxt_column.size() > nxt_rn)
            {
                nxt_rn = nxt_column.size();
            }
        }
    }
    rn = nxt_rn;
}

void solve()
{
    if (rn >= cn)
    {
        r_calc();
    }
    else
    {
        c_calc();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    while(true){
        if(cnt > 100){
            cout << -1;
            return 0;
        }
        if(map[r-1][c-1] == k){
            cout << cnt;
            return 0;
        }
        solve();
        cnt++;
    }
}