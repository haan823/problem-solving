#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m, h; // 세로선, 가로선, 높이
int min_num = 987654321;
vector<vector<int>> map;

// 들어가는 곳으로 나오는지 확인
bool sadari(vector<vector<int>> &board, int &index)
{
    int current_index = index;
    for (int i = 1; i <= h; i++)
    {
        if (board[i][current_index] == 1)
        {
            current_index++;
        }
        else if (board[i][current_index] == -1)
        {
            current_index--;
        }
    }
    return index == current_index;
}

bool sadari2(vector<vector<int>> &board)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (sadari(board, i))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int bfs(vector<vector<int>> &board)
{
    stack<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(board, 0));

    while (!q.empty())
    {
        pair<vector<vector<int>>, int> current_board;
        current_board = q.top();
        q.pop();

        if (sadari2(current_board.first))
        {
            if (current_board.second < min_num)
            {
                return current_board.second;
            }
        }
        if (current_board.second < 3)
        {
            for (int i = 1; i <= h; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (current_board.first[i][j] == 0 && current_board.first[i][j + 1] == 0)
                    {
                        vector<vector<int>> next_board = current_board.first;
                        next_board[i][j] = 1;
                        next_board[i][j + 1] = -1;
                        q.push(make_pair(next_board, current_board.second + 1));
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i <= h; i++)
    {
        vector<int> tmp;
        for (int j = 0; j <= n; j++)
        {
            tmp.push_back(0);
        }
        map.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[x][y + 1] = -1;
    }

    int answer = bfs(map);

    cout << answer;
}