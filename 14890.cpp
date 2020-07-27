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
        int tmp = map[i][0];
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == tmp)
            {
                tmp = map[i][j];
                continue;
            }
            else if (map[i][j] == tmp - 1)
            {
                if (j + l - 1 < n)
                {
                    int tmp2 = map[i][j];
                    bool flag = false;
                    for (int k = 0; k < l; k++)
                    {
                        if (tmp2 == map[i][j + k] && slide[i][j + k] == 0)
                        {
                            flag = true;
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int k = 0; k < l; k++)
                        {
                            slide[i][j + k] = 1;
                        }
                        i = j + l - 1;
                        tmp = tmp - 1;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else if (map[i][j] == tmp + 1)
            {
            }
            else
            {
                break;
            }
        }
    }
}