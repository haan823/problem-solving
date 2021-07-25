#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int res = 987654321;
vector<vector<vector<int>>> input(5, vector<vector<int>>(5, vector<int>(5, 0)));
vector<vector<vector<int>>> map(5, vector<vector<int>>(5, vector<int>(5, 0)));
vector<vector<vector<int>>> cur_map(5, vector<vector<int>>(5, vector<int>(5, 0)));
vector<int> permu = {0, 1, 2, 3, 4};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 0, 1, 0};
int dz[6] = {0, 0, 0, 1, 0, -1};

vector<vector<int>> rotate(vector<vector<int>> board, int cnt)
{
    if (cnt == 0)
    {
        return board;
    }
    else
    {
        vector<vector<int>> tmp_map(5, vector<int>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tmp_map[j][4 - i] = board[i][j];
            }
        }
        return rotate(tmp_map, --cnt);
    }
}

int bfs()
{
    int visit[5][5][5] = {
        0,
    };
    queue<vector<int>> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = 1;
    while (!q.empty())
    {
        int cx = q.front()[0];
        int cy = q.front()[1];
        int cz = q.front()[2];
        int ct = q.front()[3];
        q.pop();
        if (cx == 4 && cy == 4 && cz == 4)
        {
            return ct;
        }
        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5 && cur_map[nx][ny][nz] == 1 && !visit[nx][ny][nz])
            {
                q.push({nx, ny, nz, ct + 1});
                visit[nx][ny][nz] = 1;
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> input[i][j][k];
            }
        }
    }
    do
    {
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                for (int c = 0; c < 4; c++)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        for (int e = 0; e < 4; e++)
                        {
                            cur_map[0] = rotate(input[permu[0]], a);
                            cur_map[1] = rotate(input[permu[1]], b);
                            cur_map[2] = rotate(input[permu[2]], c);
                            cur_map[3] = rotate(input[permu[3]], d);
                            cur_map[4] = rotate(input[permu[4]], e);
                            if (cur_map[0][0][0] == 0 || cur_map[4][4][4] == 0)
                            {
                                continue;
                            }
                            int cur = bfs();
                            if (cur && cur < res)
                            {
                                res = cur;
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(permu.begin(), permu.end()));
    if (res != 987654321)
    {
        cout << res;
    }
    else
    {
        cout << -1;
    }
}