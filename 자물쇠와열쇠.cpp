#include <iostream>
#include <string>
#include <vector>

using namespace std;

int key1[20][20];
int key2[20][20];
int key3[20][20];
int key4[20][20];

int map[39][39];
int tmp[39][39];
int lhc;

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = true;

    int n = key.size();
    int m = lock.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            key1[i][j] = key[i][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            key2[j][n - i - 1] = key[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            key3[n - i - 1][n - j - 1] = key[i][j];
        }
    }

    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            key4[n - j - 1][i] = key[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lock[i][j] == 0)
            {
                lhc++;
            }
            map[i + n - 1][j + n - 1] = lock[i][j];
            tmp[i + n - 1][j + n - 1] = lock[i][j];
        }
    }

    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;
    bool flag4 = false;

    // for (int k = 0; k < m + n - 1; k++)
    // {
    //     for (int l = 0; l < m + n - 1; l++)
    //     {
    //         for (int x = k; x < k + n; x++)
    //         {
    //             for (int y = l; y < l + n; y++)
    //             {
    //                 tmp[x][y] += key1[x - k][y - n];
    //             }
    //         }
    //     }
    // }
    for (int i = n - 1; i <= m + n - 1; i++)
    {

        for (int j = n - 1; j <= m + n - 1; j++)
        {
            if (map[i][j] % 2 == 1)
            {
                flag1 = true;
                break;
            }
        }
        if (flag1 || flag2 || flag3 || flag4)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    solution(key, lock);
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key[i].size(); j++)
        {
            cout << key1[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key[i].size(); j++)
        {
            cout << key2[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key[i].size(); j++)
        {
            cout << key3[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key[i].size(); j++)
        {
            cout << key4[i][j] << " ";
        }
        cout << "\n";
    }
}