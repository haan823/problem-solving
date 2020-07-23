/* fail
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct
{
    vector<pair<int, int>> index;
    char status;
} snake;

int main()
{
    int n;
    int k;
    int l;
    queue<pair<int, char>> direction;

    int **apple2;
    int **dummy;

    cin >> n >> k;

    apple2 = new int *[n];
    for (int i = 0; i < n; i++)
    {
        apple2[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            apple2[i][j] = 0;
        }
    }

    dummy = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dummy[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dummy[i][j] = 0;
        }
    }
    dummy[0][0] = 1;

    for (int i = 0; i < k; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        apple2[tmp.first - 1][tmp.second - 1] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        pair<int, char> tmp;
        cin >> tmp.first >> tmp.second;
        direction.push(tmp);
    }

    snake bam;
    bam.index.push_back(make_pair(0, 0));
    bam.status = 'W';

    int t = 0;

    while (true)
    {
        int nx_x, nx_y;
        bool eat = false;

        if (bam.index.front().first == -1 || bam.index.front().second == -1 || bam.index.front().first == n || bam.index.front().second == n)
        {
            break;
        }

        if (bam.status == 'W')
        {
            nx_x = bam.index[0].first;
            nx_y = bam.index[0].second + 1;

            if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && apple2[nx_x][nx_y] == 1)
            {
                eat = true;
                apple2[nx_x][nx_y] = 0;
            }

            if (eat)
            {
                bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                dummy[nx_x][nx_y] = 1;
            }
            else
            {
                if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && dummy[nx_x][nx_y] == 1)
                {
                    t += 1;
                    break;
                }
                else if (nx_x == -1 || nx_y == -1 || nx_x == n || nx_y == n)
                {
                    t += 1;
                    break;
                }
                else
                {
                    bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                    dummy[nx_x][nx_y] = 1;
                    dummy[bam.index.back().first][bam.index.back().second] = 0;
                    bam.index.pop_back();
                }
            }
        }
        else if (bam.status == 'L')
        {
            nx_x = bam.index[0].first;
            nx_y = bam.index[0].second - 1;

            if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && apple2[nx_x][nx_y] == 1)
            {
                eat = true;
                apple2[nx_x][nx_y] = 0;
            }

            if (eat)
            {
                bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                dummy[nx_x][nx_y] = 1;
            }
            else
            {
                if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && dummy[nx_x][nx_y] == 1)
                {
                    t += 1;
                    break;
                }
                if (nx_x == -1 || nx_y == -1 || nx_x == n || nx_y == n)
                {
                    t += 1;
                    break;
                }
                else
                {
                    bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                    dummy[nx_x][nx_y] = 1;
                    dummy[bam.index.back().first][bam.index.back().second] = 0;
                    bam.index.pop_back();
                }
            }
        }
        else if (bam.status == 'U')
        {
            nx_x = bam.index[0].first - 1;
            nx_y = bam.index[0].second;

            if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && apple2[nx_x][nx_y] == 1)
            {
                eat = true;
                apple2[nx_x][nx_y] = 0;
            }

            if (eat)
            {
                bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                dummy[nx_x][nx_y] = 1;
            }
            else
            {
                if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && dummy[nx_x][nx_y] == 1)
                {
                    t += 1;
                    break;
                }
                if (nx_x == -1 || nx_y == -1 || nx_x == n || nx_y == n)
                {
                    t += 1;
                    break;
                }
                else
                {
                    bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                    dummy[nx_x][nx_y] = 1;
                    dummy[bam.index.back().first][bam.index.back().second] = 0;
                    bam.index.pop_back();
                }
            }
        }
        else if (bam.status == 'D')
        {
            nx_x = bam.index[0].first + 1;
            nx_y = bam.index[0].second;

            if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && apple2[nx_x][nx_y] == 1)
            {
                eat = true;
                apple2[nx_x][nx_y] = 0;
            }

            if (eat)
            {
                bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                dummy[nx_x][nx_y] = 1;
            }
            else
            {
                if (nx_x != -1 && nx_y != -1 && nx_x != n && nx_y != n && dummy[nx_x][nx_y] == 1)
                {
                    t += 1;
                    break;
                }
                if (nx_x == -1 || nx_y == -1 || nx_x == n || nx_y == n)
                {
                    t += 1;
                    break;
                }
                else
                {
                    bam.index.insert(bam.index.begin(), make_pair(nx_x, nx_y));
                    dummy[nx_x][nx_y] = 1;
                    dummy[bam.index.back().first][bam.index.back().second] = 0;
                    bam.index.pop_back();
                }
            }
        }

        if (!direction.empty() && t + 1 == direction.front().first)
        {
            if (direction.front().second == 'D')
            {
                if (bam.status == 'W')
                {
                    bam.status = 'D';
                }
                else if (bam.status == 'L')
                {
                    bam.status = 'U';
                }
                else if (bam.status == 'U')
                {
                    bam.status = 'W';
                }
                else if (bam.status == 'D')
                {
                    bam.status = 'L';
                }
            }
            else if (direction.front().second == 'L')
            {
                if (bam.status == 'W')
                {
                    bam.status = 'U';
                }
                else if (bam.status == 'L')
                {
                    bam.status = 'D';
                }
                else if (bam.status == 'U')
                {
                    bam.status = 'L';
                }
                else if (bam.status == 'D')
                {
                    bam.status = 'R';
                }
            }
            direction.pop();
        }

        t += 1;
    }

    std::cout << t;
}
*/