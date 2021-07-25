#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
    int front;
    int back;
    int up;
    int down;
    int right;
    int left;
} dice;

int main()
{
    int n, m, x, y, k;

    cin >> n >> m >> x >> y >> k;

    int **map;
    map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<int> move;

    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        move.push_back(tmp);
    }

    dice d;
    d.front = 0;
    d.back = 0;
    d.up = 0;
    d.down = 0;
    d.right = 0;
    d.left = 0;

    for (int i = 0; i < move.size(); i++)
    {
        if (move[i] == 1 && y != (m - 1))
        {
            y += 1;
            int tmp;
            tmp = d.up;
            d.up = d.left;
            d.left = d.down;
            d.down = d.right;
            d.right = tmp;
            if (map[x][y] == 0)
            {
                map[x][y] = d.down;
            }
            else
            {
                d.down = map[x][y];
                map[x][y] = 0;
            }
            cout << d.up << "\n";
        }
        else if (move[i] == 2 && y != 0)
        {
            y -= 1;
            int tmp;
            tmp = d.up;
            d.up = d.right;
            d.right = d.down;
            d.down = d.left;
            d.left = tmp;
            if (map[x][y] == 0)
            {
                map[x][y] = d.down;
            }
            else
            {
                d.down = map[x][y];
                map[x][y] = 0;
            }
            cout << d.up << "\n";
        }
        else if (move[i] == 3 && x != 0)
        {
            x -= 1;
            int tmp;
            tmp = d.up;
            d.up = d.front;
            d.front = d.down;
            d.down = d.back;
            d.back = tmp;
            if (map[x][y] == 0)
            {
                map[x][y] = d.down;
            }
            else
            {
                d.down = map[x][y];
                map[x][y] = 0;
            }
            cout << d.up << "\n";
        }
        else if (move[i] == 4 && x != (n - 1))
        {
            x += 1;
            int tmp;
            tmp = d.up;
            d.up = d.back;
            d.back = d.down;
            d.down = d.front;
            d.front = tmp;
            if (map[x][y] == 0)
            {
                map[x][y] = d.down;
            }
            else
            {
                d.down = map[x][y];
                map[x][y] = 0;
            }
            cout << d.up << "\n";
        }
    }
}