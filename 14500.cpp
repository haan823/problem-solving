#include <iostream>
using namespace std;

void t1(int **x, int n, int m)
{
    int **tmp = x;
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            if (j < m - 3)
            {
                sum = tmp[i][j] + tmp[i][j + 1] + tmp[i][j + 2] + tmp[i][j + 3];
                if (sum >= max1)
                {
                    max1 = sum;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            if (i < n - 3)
            {
                sum = tmp[i][j] + tmp[i + 1][j] + tmp[i + 2][j] + tmp[i + 3][j];
                if (sum >= max1)
                {
                    max1 = sum;
                }
            }
        }
    }
    cout << "max1: " << max1 << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **map = new int *[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    t1(map, n, m);
}