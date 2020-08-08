#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<vector<int>> map;
vector<vector<int>> input;
int board[101][101];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

pair<int, int> rotate(pair<int, int> pivot, pair<int, int> loc)
{
    int x, y;
    if (pivot.first < loc.first)
    {
        y = pivot.second - (loc.first - pivot.first);
    }
    else if (pivot.first > loc.first)
    {
        y = pivot.second + (pivot.first - loc.first);
    }
    else
    {
        y = pivot.second;
    }

    if (pivot.second < loc.second)
    {
        x = pivot.first + (loc.second - pivot.second);
    }
    else if (pivot.second > loc.second)
    {
        x = pivot.first - (pivot.second - loc.second);
    }
    else
    {
        x = pivot.first;
    }

    return {x, y};
}

vector<pair<int, int>> dfs(vector<pair<int, int>> dragon, pair<int, int> pivot, int g)
{
    vector<pair<int, int>> new_dragon = dragon;
    pair<int, int> new_pivot = pivot;
    while (g--)
    {
        new_pivot = new_dragon.back();
        for (int i = new_dragon.size() - 2; i >= 0; i--)
        {
            new_dragon.push_back(rotate(new_pivot, new_dragon[i]));
        }
    }
    return new_dragon;
}

void check_board(vector<pair<int ,int>> dragon){
    pair<int, int> start, last;
    for(int i=0; i<dragon.size(); i++){
        start = dragon[i];
        board[start.first][start.second] = 1;
    }
}

int main()
{
    for (int i = 0; i < 101; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 101; j++)
        {
            tmp.push_back(0);
        }
        map.push_back(tmp);
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp_input;
        for (int j = 0; j < 4; j++)
        {
            int tmp;
            cin >> tmp;
            tmp_input.push_back(tmp);
        }
        input.push_back(tmp_input);
    }

    for(int i=0; i<input.size(); i++){
        vector<pair<int, int>> dragon;
        dragon.push_back(make_pair(input[i][1], input[i][0]));
        dragon.push_back(make_pair(input[i][1]+dx[input[i][2]], input[i][0]+dy[input[i][2]]));
        vector<pair<int, int>> new_dragon;
        new_dragon = dfs(dragon, dragon[1], input[i][3]);
        check_board(new_dragon);
    }

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]){
                cnt++;
            }
        }
    }

    cout << cnt;
}