#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, max_time;
int d, dss;
int ss = 2, sx, sy; // 상어 크기, 상어 x 좌표, 상어 y 좌표
vector<vector<int>> map;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init_shark()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 9)
            {
                sx = i;
                sy = j;
                return;
            }
        }
    }
}

pair<int, int> shark_next(vector<int> shark_now)
{
    queue<vector<int>> q; // x좌표, y좌표, 깊이
    int visit[20][20] = {
        0,
    };
    q.push({shark_now[1], shark_now[2], 0});
    visit[shark_now[1]][shark_now[2]] = 1;
    int depth = 987654321;
    int x = 987654321, y = 987654321;

    while (!q.empty())
    {
        vector<int> tmp = q.front();
        q.pop();
        int cx = tmp[0];
        int cy = tmp[1];
        int cd = tmp[2]; // 현재 깊이
        int nx, ny, nd;
        nd = cd + 1;
        if(cd > depth){
            break;
        }
        if (map[cx][cy] > 0 && map[cx][cy] < shark_now[0] && map[cx][cy] != 9)
        {
            if (cd <= depth)
            {
                if (cx < x)
                {
                    x = cx;
                    y = cy;
                    depth = cd;
                }
                else if (cx == x)
                {
                    if (cy < y)
                    {
                        x = cx;
                        y = cy;
                        depth = cd;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] <= shark_now[0] && !visit[nx][ny])
            {
                q.push({nx, ny, nd});
                visit[nx][ny] = 1;
            }
        }
    }

    if(x!=987654321){
        map[sx][sy] = 0;
        sx = x;
        sy = y;
        map[sx][sy] = 9;
        d = depth;
    }
    return make_pair(x, y);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            tmp.push_back(input);
        }
        map.push_back(tmp);
    }

    init_shark();

    while (true)
    {
        pair<int, int> next;
        next = shark_next({ss, sx, sy});
        if(next.first != 987654321){
            dss++;
            if(ss == dss){
                ss++;
                dss = 0;
            }
            max_time += d;
        }
    
        else{
            break;
        }
    }

    cout << max_time;
}