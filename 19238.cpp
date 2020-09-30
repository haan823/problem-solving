#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, fuel;
int map[20][20];
int visit[20][20];
vector<vector<int>> passenger;
vector<vector<int>> route;
int tx, ty;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int find_min_distance(int sx, int sy, int gx, int gy)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = 0;
        }
    }
    queue<vector<int>> q;
    q.push({0, sx, sy});
    visit[sx][sy] = 1;
    while (!q.empty())
    {
        int d = q.front()[0];
        int cx = q.front()[1];
        int cy = q.front()[2];
        q.pop();
        if (cx == gx && cy == gy)
        {
            return d;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0 && !visit[nx][ny])
            {
                q.push({d + 1, nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }
    return -1;
}

pair<int, int> find_next_passenger()
{
    int p = 0;
    int d = 987654321;
    for (int i = 0; i < passenger.size(); i++)
    {
        int nd = find_min_distance(tx, ty, passenger[i][0], passenger[i][1]);
        if (nd == -1)
        {
            continue;
        }
        else
        {
            if (nd < d)
            {
                p = i;
                d = nd;
            }
            else if (nd == d)
            {
                if (passenger[p][0] > passenger[i][0])
                {
                    p = i;
                    d = nd;
                }
                else if (passenger[p][0] == passenger[i][0])
                {
                    if (passenger[p][1] > passenger[i][1])
                    {
                        p = i;
                        d = nd;
                    }
                }
            }
        }
    }
    return make_pair(p, d);
}

int main()
{
    cin >> n >> m >> fuel;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    tx = x - 1;
    ty = y - 1;
    for (int i = 0; i < m; i++)
    {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        passenger.push_back({sx - 1, sy - 1, gx - 1, gy - 1});
    }
    while (true)
    {
        if (passenger.size() == 0)
        {
            cout << fuel;
            return 0;
        }
        else
        {
            pair<int, int> next_passenger = find_next_passenger();
            int p = next_passenger.first;
            int dtp = next_passenger.second;
            if(dtp==987654321){
                cout << -1;
                return 0;
            }
            int dtg = find_min_distance(passenger[p][0], passenger[p][1], passenger[p][2], passenger[p][3]);
            if(dtg==-1){
                cout << -1;
                return 0;
            }
            if (fuel >= dtp + dtg)
            {
                tx = passenger[p][2];
                ty = passenger[p][3];
                fuel -= (dtp + dtg);
                fuel += (dtg * 2);
                passenger.erase(passenger.begin() + p);
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }
}