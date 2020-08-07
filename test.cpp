#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> start = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};

int main()
{
    int k=2;
    do
    {
        do
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << start[i][j] << " ";
                }
                cout << "\n";
            }
        }while(next_permutation(start[k].begin(), start[k].end()));
        k--;
    } while (next_permutation(start.begin(), start.end()));
}
