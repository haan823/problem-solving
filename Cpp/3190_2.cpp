#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#define MAX 100
using namespace std;

int main()
{
    int n, k, l;
    int MAP[MAX][MAX];

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    deque<pair<int, int>> deq;

    queue<pair<int, char>> que;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MAP[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        MAP[x - 1][y - 1] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        que.push(make_pair(x, y));
    }

    int t = 0;
    int d = 0;
    int x = 0;
    int y = 0;

    deq.push_back(make_pair(0, 0));
    MAP[x][y] = 2;

    while (true)
    {
        t += 1;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || MAP[nx][ny] == 2)
        {
            break;
        }
        else if (MAP[nx][ny] == 0)
        {
            MAP[nx][ny] = 2;
            MAP[deq.back().first][deq.back().second] = 0;
            deq.pop_back();
            deq.push_front(make_pair(nx, ny));
        }
        else if (MAP[nx][ny] == 1)
        {
            MAP[nx][ny] = 2;
            deq.push_front(make_pair(nx, ny));
        }

        if (t == que.front().first)
        {
            if (que.front().second == 'D')
            {
                d = (d + 1) % 4;
            }
            else if (que.front().second == 'L')
            {
                d = (d + 3) % 4;
            }
            que.pop();
        }

        x = nx;
        y = ny;
    }

    cout << t;
}