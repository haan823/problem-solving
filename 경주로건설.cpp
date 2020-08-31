#include <string>
#include <vector>

using namespace std;

int visit[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, mv = 987654321;
vector<vector<int>> map;

void dfs(int x, int y, int dir, int cost)
{
    if (x == n - 1 && y == n - 1)
    {
        if (cost < mv)
        {
            mv = cost;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int ndir = (i % 2);
        int ncost;
        if (dir == -1)
        {
            ncost = cost + 100;
        }
        else
        {
            if (dir == ndir)
            {
                ncost = cost + 100;
            }
            else
            {
                ncost = cost + 600;
            }
        }
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0 && !visit[nx][ny])
        {
            visit[nx][ny] = 1;
            dfs(nx, ny, ndir, ncost);
            visit[nx][ny] = 0;
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    n = board.size();
    map = board;
    visit[0][0] = 1;
    dfs(0, 0, -1, 0);
    answer = mv;
    return answer;
}
