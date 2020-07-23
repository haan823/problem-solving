#include <string>
#include <iostream>
#include <vector>
using namespace std;

int m[11][11][11][11];

int solution(string dirs)
{
    int answer = 0;
    int sx = 5;
    int sy = 5;
    int ex = 5;
    int ey = 5;
    for (char c : dirs)
    {
        sx = ex;
        sy = ey;

        if (c == 'U')
        {
            ex--;
        }
        else if (c == 'D')
        {
            ex++;
        }
        else if (c == 'R')
        {
            ey++;
        }
        else if (c == 'L')
        {
            ey--;
        }

        if (ex < 0)
        {
            ex = 0;
            continue;
        }
        if (ex > 10)
        {
            ex = 10;
            continue;
        }
        if (ey < 0)
        {
            ey = 0;
            continue;
        }
        if (ey > 10)
        {
            ey = 10;
            continue;
        }

        if (!m[sx][sy][ex][ey])
        {
            answer++;
        }

        m[sx][sy][ex][ey] = 1;
        m[ex][ey][sx][sy] = 1;
    }

    return answer;
}
