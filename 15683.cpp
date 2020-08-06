#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> map;
int min_num = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int total_cctv_num;
vector<vector<int>> cctv_loc;

bool is_in_board(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sagak(vector<vector<int>> board) // 사각 지대 카운트
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

vector<vector<int>> cctv(vector<vector<int>> board, int x, int y, int dir)
{
    vector<vector<int>> next_board = board;
    int cx = x;
    int cy = y;
    int nx, ny;

    while (true)
    {
        nx = cx + dx[dir];
        ny = cy + dy[dir];
        if (is_in_board(nx, ny))
        {
            if (board[nx][ny] == 0)
            {
                next_board[nx][ny] = 9;
                cx = nx;
                cy = ny;
            }
            else if (board[nx][ny] >= 1 && board[nx][ny] < 6)
            {
                cx = nx;
                cy = ny;
                continue;
            }
            else if (board[nx][ny] == 6)
            {
                break;
            }
            else
            {
                cx = nx;
                cy = ny;
                continue;
            }
        }
        else
        {
            break;
        }
    }

    return next_board;
}

vector<vector<int>> cctv2(vector<vector<int>> board, int x, int y, int cctv_num, int k)
{
    if (cctv_num == 1)
    {
        return cctv(board, x, y, k);
    }
    else if (cctv_num == 2)
    {
        vector<vector<int>> tmp = cctv(board, x, y, k);
        return cctv(tmp, x, y, (k + 2) % 4);
    }
    else if (cctv_num == 3)
    {
        vector<vector<int>> tmp = cctv(board, x, y, k);
        return cctv(tmp, x, y, (k + 1) % 4);
    }
    else if (cctv_num == 4)
    {
        vector<vector<int>> tmp = cctv(board, x, y, k);
        tmp = cctv(tmp, x, y, (k + 1) % 4);
        return cctv(tmp, x, y, (k + 3) % 4);
    }
    else
    {
        vector<vector<int>> tmp = cctv(board, x, y, k);
        tmp = cctv(tmp, x, y, (k + 1) % 4);
        tmp = cctv(tmp, x, y, (k + 2) % 4);
        return cctv(tmp, x, y, (k + 3) % 4);
    }
}

void dfs(vector<vector<int>> board, int cnt)
{
    if (cnt == total_cctv_num)
    {
        if (sagak(board) < min_num)
        {
            min_num = sagak(board);
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> next_board = cctv2(board, cctv_loc[cnt][1], cctv_loc[cnt][2], cctv_loc[cnt][0], i);
        dfs(next_board, cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp_v;
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            tmp_v.push_back(tmp);
            if (tmp >= 1 && tmp < 6)
            {
                cctv_loc.push_back({tmp, i, j});
            }
        }
        map.push_back(tmp_v);
    }

    total_cctv_num = cctv_loc.size();

    dfs(map, 0);

    cout << min_num;
}