#include <iostream>

using namespace std;

int map[4][8];
int k;
int task[100][2];

void clock_wise(int num)
{
}

void counter_clock_wise(int num)
{
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> task[i][0] >> task[i][1];
    }
}