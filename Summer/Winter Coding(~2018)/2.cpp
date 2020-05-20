#include <string>
#include <iostream>
using namespace std;

int m[11][11];

int solution(string dirs)
{
    int answer = 0;
    m[5][5] = 1;
    int x = 5;
    int y = 5;
    for (char c : dirs)
    {
        if (c == 'L')
        {
            if (y >= 1)
            {
                if (m[x][y] == 0 || m[x][y - 1] == 0)
                {
                    answer += 1;
                    cout << c;
                }
                y -= 1;
                m[x][y] = 1;
            }
        }
        else if (c == 'R')
        {
            if (y <= 9)
            {
                if (m[x][y] == 0 || m[x][y + 1] == 0)
                {
                    answer += 1;
                    cout << c;
                }
                y += 1;
                m[x][y] = 1;
            }
        }
        else if (c == 'U')
        {
            if (x >= 1)
            {
                if (m[x][y] == 0 || m[x - 1][y] == 0)
                {
                    answer += 1;
                    cout << c;
                }
                x -= 1;
                m[x][y] = 1;
            }
        }
        else if (c == 'D')
        {
            if (x <= 9)
            {
                if (m[x][y] == 0 || m[x + 1][y] == 0)
                {
                    answer += 1;
                    cout << c;
                }
                x += 1;
                m[x][y] = 1;
            }
        }
    }

    return answer;
}

int main()
{
    string dirs = "ULURRDLLU";
    solution(dirs);
}