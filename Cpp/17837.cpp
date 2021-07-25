#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, k, t = 1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
stack<int> map[12][12]; // {horse number}
int board[12][12];      // 0:white / 1:red / 2:blue
vector<int> horse[11];  // {x, y, direction}

void go_white(int i, int x, int y, int nx, int ny)
{
    stack<int> s;
    while (true)
    {
        int tmp = map[x][y].top();
        horse[tmp][0] = nx;
        horse[tmp][1] = ny;
        if (tmp != i)
        {
            map[x][y].pop();
            s.push(tmp);
        }
        else
        {
            map[x][y].pop();
            s.push(tmp);
            break;
        }
    }
    int s_size = s.size();
    for (int j = 0; j < s_size; j++)
    {
        map[nx][ny].push(s.top());
        s.pop();
    }
}

void go_red(int i, int x, int y, int nx, int ny)
{
    while (true)
    {
        int tmp = map[x][y].top();
        horse[tmp][0] = nx;
        horse[tmp][1] = ny;
        if (tmp != i)
        {
            map[x][y].pop();
            map[nx][ny].push(tmp);
        }
        else
        {
            map[x][y].pop();
            map[nx][ny].push(tmp);
            break;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y, direction;
        cin >> x >> y >> direction;
        if (direction == 2)
        {
            direction = 3;
        }
        else if (direction == 3)
        {
            direction = 0;
        }
        else if (direction == 4)
        {
            direction = 2;
        }
        map[x - 1][y - 1].push(i);
        horse[i].push_back(x - 1);
        horse[i].push_back(y - 1);
        horse[i].push_back(direction);
    }

    while (t <= 1000)
    {
        for (int i = 1; i <= k; i++)
        {
            int x = horse[i][0];
            int y = horse[i][1];
            int direction = horse[i][2];
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (board[nx][ny] == 0) // white
                {
                    go_white(i, x, y, nx, ny);
                    if (map[nx][ny].size() >= 4)
                    {
                        cout << t;
                        return 0;
                    }
                }
                else if (board[nx][ny] == 1) // red
                {
                    go_red(i, x, y, nx, ny);
                    if (map[nx][ny].size() >= 4)
                    {
                        cout << t;
                        return 0;
                    }
                }
                else if (board[nx][ny] == 2) // blue
                {
                    nx = x - dx[direction];
                    ny = y - dy[direction];
                    horse[i][2] = (direction+2)%4;
                    if (board[nx][ny] == 2 || !(nx >= 0 && nx < n && ny >= 0 && ny < n))
                    {
                        continue;
                    }
                    else if (board[nx][ny] == 0)
                    {
                        go_white(i, x, y, nx, ny);
                        if (map[nx][ny].size() >= 4)
                        {
                            cout << t;
                            return 0;
                        }
                    }
                    else
                    {
                        go_red(i, x, y, nx, ny);
                        if (map[nx][ny].size() >= 4)
                        {
                            cout << t;
                            return 0;
                        }
                    }
                }
            }
            else
            {
                nx = x - dx[direction];
                ny = y - dy[direction];
                horse[i][2] = (direction+2)%4;
                if (board[nx][ny] == 2 || !(nx >= 0 && nx < n && ny >= 0 && ny < n))
                {
                    continue;
                }
                else if (board[nx][ny] == 0)
                {
                    go_white(i, x, y, nx, ny);
                    if (map[nx][ny].size() >= 4)
                    {
                        cout << t;
                        return 0;
                    }
                }
                else
                {
                    go_red(i, x, y, nx, ny);
                    if (map[nx][ny].size() >= 4)
                    {
                        cout << t;
                        return 0;
                    }
                }
            }
        }
        t++;
    }
    cout << -1;
    return 0;
}