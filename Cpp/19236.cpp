#include <iostream>
#include <vector>

using namespace std;

int res;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int map[4][4];
vector<int> fishes[17]; // {x, y, dir}, dir : 0~7

void copy(int map[4][4], int tmp_map[4][4], vector<int> fishes[17], vector<int> tmp_fishes[17])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp_map[i][j] = map[i][j];
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        tmp_fishes[i] = fishes[i];
    }
}

void move_fishes()
{
    for (int i = 1; i <= 16; i++)
    {
        if (fishes[i][2] == -1)
        {
            continue;
        }
        int cfx = fishes[i][0], cfy = fishes[i][1], cfd = fishes[i][2];
        for (int j = 0; j < 8; j++)
        {
            int nfd = (cfd + j) % 8;
            int nfx = cfx + dx[nfd];
            int nfy = cfy + dy[nfd];
            if (nfx >= 0 && nfx < 4 && nfy >= 0 && nfy < 4)
            {
                if (map[nfx][nfy] >= 1 && map[nfx][nfy] <= 16)
                {
                    int k = map[nfx][nfy];
                    map[cfx][cfy] = map[nfx][nfy];
                    map[nfx][nfy] = i;
                    fishes[i][0] = nfx;
                    fishes[i][1] = nfy;
                    fishes[i][2] = nfd;
                    fishes[k][0] = cfx;
                    fishes[k][1] = cfy;
                    break;
                }
                else if (map[nfx][nfy] == 0)
                {
                    map[cfx][cfy] = 0;
                    map[nfx][nfy] = i;
                    fishes[i][0] = nfx;
                    fishes[i][1] = nfy;
                    fishes[i][2] = nfd;
                    break;
                }
            }
        }
    }
}

void dfs(int score, int sx, int sy, int sdir)
{
    res = max(res, score);
    vector<int> tmp_fishes[17];
    int tmp_map[4][4];
    copy(map, tmp_map, fishes, tmp_fishes);
    move_fishes();
    for (int i = 1; i <= 3; i++)
    {
        int nsx = sx + dx[sdir] * i;
        int nsy = sy + dy[sdir] * i;
        if (nsx >= 0 && nsx < 4 && nsy >= 0 && nsy < 4)
        {
            if (map[nsx][nsy] == 0)
            {
                continue;
            }
            int fish = map[nsx][nsy];
            int ndir = fishes[fish][2];
            map[nsx][nsy] = 100;
            fishes[fish][2] = -1;
            map[sx][sy] = 0;
            dfs(score + fish, nsx, nsy, ndir);
            map[nsx][nsy] = fish;
            fishes[fish][2] = ndir;
            map[sx][sy] = 100;
        }
        else
        {
            break;
        }
    }
    copy(tmp_map, map, tmp_fishes, fishes);
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num, dir;
            cin >> num >> dir;
            map[i][j] = num;
            fishes[num].push_back(i);
            fishes[num].push_back(j);
            fishes[num].push_back(dir - 1);
        }
    }
    int fish = map[0][0];
    int dir = fishes[fish][2];
    fishes[fish][2] = -1;
    map[0][0] = 100;
    dfs(fish, 0, 0, dir);
    cout << res;
}