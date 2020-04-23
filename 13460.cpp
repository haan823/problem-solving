#include <iostream>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

typedef struct
{
    int x;
    int y;
} index;

class bfs
{
public:
    int a, b;
    index red, blue, goal;
    queue<index> red_q, blue_q;
    vector<int> *board;
    vector<int> *red_visit;
    vector<int> *blue_visit;
    void Init()
    {
        cin >> a >> b;
        board = new vector<int>[a];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                char x;
                cin >> x;
                if (x == '#')
                {
                    board[i].push_back(1);
                }
                else if (x == 'R')
                {
                    red.x = i;
                    red.y = j;
                }
                else if (x == 'B')
                {
                    blue.x = i;
                    blue.y = j;
                }
                else if (x == 'O')
                {
                    goal.x = i;
                    goal.y = j;
                }
                else
                {
                    board[i].push_back(0);
                }
            }
        }
    };

    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < b; j++)
    //     {
    //         printf("%d", board[i][j]);
    //     }
    //     printf("\n");
    // }

    void left(index red, index blue)
    {
        int red_t = 0, blue_t = 0;
        while (true)
        {
            if (red.y - 1 == 0)
            {
                red.y -= 1;
                red_t += 1;
            }
        }
        while (true)
        {
            if (blue.y - 1 == 0)
            {
                blue.y -= 1;
                blue_t += 1;
            }
        }
        if (red.x == blue.x && red.y == blue.y)
        {
            if (red_t > blue_t)
            {
                red.y += 1;
            }
            else
            {
                blue.y += 1;
            }
        }
    }

    void right()
    {
        int red_t = 0, blue_t = 0;
        while (true)
        {
            if (red.y + 1 == 0)
            {
                red.y += 1;
                red_t += 1;
            }
        }
        while (true)
        {
            if (blue.y + 1 == 0)
            {
                blue.y += 1;
                blue_t += 1;
            }
        }
        if (red.x == blue.x && red.y == blue.y)
        {
            if (red_t > blue_t)
            {
                red.y -= 1;
            }
            else
            {
                blue.y -= 1;
            }
        }
    }

    void up()
    {
        int red_t = 0, blue_t = 0;
        while (true)
        {
            if (red.x - 1 == 0)
            {
                red.x -= 1;
                red_t += 1;
            }
        }
        while (true)
        {
            if (blue.x - 1 == 0)
            {
                blue.x -= 1;
                blue_t += 1;
            }
        }
        if (red.x == blue.x && red.y == blue.y)
        {
            if (red_t > blue_t)
            {
                red.x += 1;
            }
            else
            {
                blue.x += 1;
            }
        }
    }

    void down()
    {
        int red_t = 0, blue_t = 0;
        while (true)
        {
            if (red.x + 1 == 0)
            {
                red.x += 1;
                red_t += 1;
            }
        }
        while (true)
        {
            if (blue.x + 1 == 0)
            {
                blue.x += 1;
                blue_t += 1;
            }
        }
        if (red.x == blue.x && red.y == blue.y)
        {
            if (red_t > blue_t)
            {
                red.x -= 1;
            }
            else
            {
                blue.x -= 1;
            }
        }
    }

    int result()
    {
    }
};

int main()
{
}