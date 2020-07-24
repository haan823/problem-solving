#include <iostream>

using namespace std;

int map[100][100];
int slide[100][100];
int row[100];
int column[100];
int n, l, cnt;

int main()
{
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // row search
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if ((map[i][j] == map[i][j - 1] + 1) && (map[i][j] == map[i][j - 2] + 1) && slide[i][j - 2] == 0 && slide[i][j - 1] == 0)
            {
                slide[i][j - 2] = 1;
                slide[i][j - 1] = 1;
            }
            else if ()
        }
    }
}