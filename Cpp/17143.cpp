#include <iostream>
#include <vector>

using namespace std;

int r, c, m, sum;
int input[10000][5];
int map[101][101];
vector<int> alive;

void count_fish()
{
    for (int k = 1; k <= c; k++)
    {
        for (int a = 1; a <= r; a++)
        {
            if (map[a][k] != -1)
            {
                sum += input[map[a][k]][4];
                alive[map[a][k]] = 0;
                map[a][k] = -1;
                break;
            }
        }
        for (int x = 0; x < 101; x++)
        {
            for (int y = 0; y < 101; y++)
            {
                map[x][y] = -1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            // 살아있나?
            if (alive[i])
            {
                // 현재 x, 현재 y, 현재 direction,현재 velocity, 다음 x, 다음 y, 다음 direction, 다음 velocity
                int cx, cy, cd, cv, nx, ny, nd, nv;
                cx = input[i][0];
                cy = input[i][1];
                cv = input[i][2];
                cd = input[i][3];

                if (cd == 1 || cd == 2)
                {
                    for (int j = 0; j < cv; j++)
                    {
                        if (cd == 1)
                        {
                            if (cx == 1)
                            {
                                cx = 2;
                                cd = 2;
                            }
                            else
                            {
                                cx--;
                            }
                        }
                        else if (cd == 2)
                        {
                            if (cx == r)
                            {
                                cx = r - 1;
                                cd = 1;
                            }
                            else
                            {
                                cx++;
                            }
                        }
                    }
                }
                else if (cd == 3 || cd == 4)
                {
                    for (int j = 0; j < cv; j++)
                    {
                        if (cd == 4)
                        {
                            if (cy == 1)
                            {
                                cy = 2;
                                cd = 3;
                            }
                            else
                            {
                                cy--;
                            }
                        }
                        else if (cd == 3)
                        {
                            if (cy == c)
                            {
                                cy = c - 1;
                                cd = 4;
                            }
                            else
                            {
                                cy++;
                            }
                        }
                    }
                }

                nx = cx;
                ny = cy;
                nd = cd;
                nv = cv;

                // map에 이미 존재하는가?
                if (map[nx][ny] != -1)
                {
                    if (input[map[nx][ny]][4] < input[i][4])
                    {
                        alive[map[nx][ny]] = 0;
                        map[nx][ny] = i;
                    }
                    else
                    {
                        alive[i] = 0;
                        continue;
                    }
                }
                else
                {
                    map[nx][ny] = i;
                }

                input[i][0] = nx;
                input[i][1] = ny;
                input[i][3] = nd;
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    for (int x = 0; x < 101; x++)
    {
        for (int y = 0; y < 101; y++)
        {
            map[x][y] = -1;
        }
    }

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> input[i][j];
        }
        alive.push_back(1);
        map[input[i][0]][input[i][1]] = i;
    }

    count_fish();

    cout << sum;
}