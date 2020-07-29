#include <iostream>

using namespace std;

int map1[100][100];
int map2[100][100];
int row[100];
int column[100];
int n, l, cnt, i, j;

int main()
{
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map1[i][j];
            map2[j][i] = map1[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        int tmp = 1;
        for (j = 0; j < n - 1; j++)
        {
            if (map1[i][j] == map1[i][j + 1])
            {
                tmp++;
            }
            else if (map1[i][j] + 1 == map1[i][j + 1] && tmp >= l)
            {
                tmp = 1;
            }
            else if (map1[i][j] - 1 == map1[i][j + 1] && tmp >= 0)
            {
                tmp = -l + 1;
            }
            else
            {
                break;
            }
        }
        if (j == n - 1 && tmp >= 0)
        {
            cnt++;
        }
    }

    for (i = 0; i < n; i++)
    {
        int tmp = 1;
        for (j = 0; j < n - 1; j++)
        {
            if (map2[i][j] == map2[i][j + 1])
            {
                tmp++;
            }
            else if (map2[i][j] + 1 == map2[i][j + 1] && tmp >= l)
            {
                tmp = 1;
            }
            else if (map2[i][j] - 1 == map2[i][j + 1] && tmp >= 0)
            {
                tmp = -l + 1;
            }
            else
            {
                break;
            }
        }
        if (j == n - 1 && tmp >= 0)
        {
            cnt++;
        }
    }

    cout << cnt;
}