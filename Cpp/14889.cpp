#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[20][20];
int min_num = 987654321;
vector<int> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < (n / 2); i++)
    {
        v.push_back(0);
    }
    for (int i = (n / 2); i < n; i++)
    {
        v.push_back(1);
    }

    do
    {
        int team1 = 0, team2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i] == 0 && v[j] == 0)
                {
                    team1 += map[i][j];
                }
                else if (v[i] == 1 && v[j] == 1)
                {
                    team2 += map[i][j];
                }
            }
        }
        if (abs(team1 - team2) < min_num)
        {
            min_num = abs(team1 - team2);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << min_num;
}