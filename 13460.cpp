#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

char board[10][10];
char status[10][10][10][10];
pair<int, int> red;
pair<int, int> blue;
pair<int, int> goal;
queue<pair<int, pair<pair<int, int>, pair<int, int>>>> s;

pair<pair<int, int>, pair<int, int>> right(pair<pair<int, int>, pair<int, int>> now)
{
    pair<pair<int, int>, pair<int, int>> tmp = now;
    bool red_goal = false;
    bool blue_goal = false;
    while (true)
    {
        if (board[tmp.first.first][tmp.first.second + 1] == '#' && board[tmp.second.first][tmp.second.second + 1] == '#')
        {
            break;
        }
        else if(red_goal && blue_goal){
            break;
        }
        else if(board[tmp.first.first][tmp.first.second + 1] == '#' && blue_goal){
            break;
        }
        else if(board[tmp.second.first][tmp.second.second + 1] == '#' && red_goal){
            break;
        }
        if (board[tmp.first.first][tmp.first.second + 1] != '#' && !red_goal)
        {
            tmp.first.second++;
        }
        if (board[tmp.second.first][tmp.second.second + 1] != '#' && !blue_goal)
        {
            tmp.second.second++;
        }
        if (tmp.first.first == goal.first && tmp.first.second == goal.second)
        {
            red_goal = true;
        }
        if (tmp.second.first == goal.first && tmp.second.second == goal.second)
        {
            blue_goal = true;
        }
    }
    if(red_goal && blue_goal){
        return tmp;
    }
    else if (tmp.first.first == tmp.second.first && tmp.first.second == tmp.second.second)
    {
        if (now.first.second < now.second.second)
        {
            tmp.first.second--;
            return tmp;
        }
        else if (now.first.second > now.second.second)
        {
            tmp.second.second--;
            return tmp;
        }
    }
    else
    {
        return tmp;
    }
}

pair<pair<int, int>, pair<int, int>> left(pair<pair<int, int>, pair<int, int>> now)
{
    pair<pair<int, int>, pair<int, int>> tmp = now;
    bool red_goal = false;
    bool blue_goal = false;
    while (true)
    {
        if (board[tmp.first.first][tmp.first.second - 1] == '#' && board[tmp.second.first][tmp.second.second - 1] == '#')
        {
            break;
        }
        else if(red_goal && blue_goal){
            break;
        }
        else if(board[tmp.first.first][tmp.first.second + 1] == '#' && blue_goal){
            break;
        }
        else if(board[tmp.second.first][tmp.second.second + 1] == '#' && red_goal){
            break;
        }
        if (board[tmp.first.first][tmp.first.second - 1] != '#' && !red_goal)
        {
            tmp.first.second--;
        }
        if (board[tmp.second.first][tmp.second.second - 1] != '#' && !blue_goal)
        {
            tmp.second.second--;
        }
        if (tmp.first.first == goal.first && tmp.first.second == goal.second)
        {
            red_goal = true;
        }
        if (tmp.second.first == goal.first && tmp.second.second == goal.second)
        {
            blue_goal = true;
        }
    }
    if(red_goal && blue_goal){
        return tmp;
    }
    else if (tmp.first.first == tmp.second.first && tmp.first.second == tmp.second.second)
    {
        if (now.first.second < now.second.second)
        {
            tmp.second.second++;
            return tmp;
        }
        else if (now.first.second > now.second.second)
        {
            tmp.first.second++;
            return tmp;
        }
    }
    else
    {
        return tmp;
    }
}

pair<pair<int, int>, pair<int, int>> up(pair<pair<int, int>, pair<int, int>> now)
{
    pair<pair<int, int>, pair<int, int>> tmp = now;
    bool red_goal = false;
    bool blue_goal = false;
    while (true)
    {
        if (board[tmp.first.first - 1][tmp.first.second] == '#' && board[tmp.second.first - 1][tmp.second.second] == '#')
        {
            break;
        }
        else if(red_goal && blue_goal){
            break;
        }
        else if(board[tmp.first.first][tmp.first.second + 1] == '#' && blue_goal){
            break;
        }
        else if(board[tmp.second.first][tmp.second.second + 1] == '#' && red_goal){
            break;
        }
        if (board[tmp.first.first - 1][tmp.first.second] != '#' && !red_goal)
        {
            tmp.first.first--;
        }
        if (board[tmp.second.first - 1][tmp.second.second] != '#' && !blue_goal)
        {
            tmp.second.first--;
        }
        if (tmp.first.first == goal.first && tmp.first.second == goal.second)
        {
            red_goal = true;
        }
        if (tmp.second.first == goal.first && tmp.second.second == goal.second)
        {
            blue_goal = true;
        }
    }
    if(red_goal && blue_goal){
        return tmp;
    }
    else if (tmp.first.first == tmp.second.first && tmp.first.second == tmp.second.second)
    {
        if (now.first.first < now.second.first)
        {
            tmp.second.first++;
            return tmp;
        }
        else if (now.first.first > now.second.first)
        {
            tmp.first.first++;
            return tmp;
        }
    }
    else
    {
        return tmp;
    }
}

pair<pair<int, int>, pair<int, int>> down(pair<pair<int, int>, pair<int, int>> now)
{
    pair<pair<int, int>, pair<int, int>> tmp = now;
    bool red_goal = false;
    bool blue_goal = false;
    while (true)
    {
        if (board[tmp.first.first + 1][tmp.first.second] == '#' && board[tmp.second.first + 1][tmp.second.second] == '#')
        {
            break;
        }
        else if(red_goal && blue_goal){
            break;
        }
        else if(board[tmp.first.first][tmp.first.second + 1] == '#' && blue_goal){
            break;
        }
        else if(board[tmp.second.first][tmp.second.second + 1] == '#' && red_goal){
            break;
        }
        if (board[tmp.first.first + 1][tmp.first.second] != '#' && !red_goal)
        {
            tmp.first.first++;
        }
        if (board[tmp.second.first + 1][tmp.second.second] != '#' && !blue_goal)
        {
            tmp.second.first++;
        }
        if (tmp.first.first == goal.first && tmp.first.second == goal.second)
        {
            red_goal = true;
        }
        if (tmp.second.first == goal.first && tmp.second.second == goal.second)
        {
            blue_goal = true;
        }
    }
    if(red_goal && blue_goal){
        return tmp;
    }
    else if (tmp.first.first == tmp.second.first && tmp.first.second == tmp.second.second)
    {
        if (now.first.first < now.second.first)
        {
            tmp.second.first--;
            return tmp;
        }
        else if (now.first.first > now.second.first)
        {
            tmp.first.first--;
            return tmp;
        }
    }
    else
    {
        return tmp;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                red = make_pair(i, j);
            }
            else if (board[i][j] == 'B')
            {
                blue = make_pair(i, j);
            }
            else if (board[i][j] == 'O')
            {
                goal = make_pair(i, j);
            }
        }
    }

    pair<pair<int, int>, pair<int, int>> now = make_pair(red, blue);

    s.push(make_pair(0, now));
    while (!s.empty())
    {
        pair<pair<int, int>, pair<int, int>> tmp;
        pair<pair<int, int>, pair<int, int>> after_right;
        pair<pair<int, int>, pair<int, int>> after_left;
        pair<pair<int, int>, pair<int, int>> after_up;
        pair<pair<int, int>, pair<int, int>> after_down;
        tmp = s.front().second;
        int cnt = s.front().first;
        s.pop();
        status[tmp.first.first][tmp.first.second][tmp.second.first][tmp.second.second] = 1;
        cnt++;
        if (cnt <= 10)
        {
            after_right = right(tmp);
            if (status[after_right.first.first][after_right.first.second][after_right.second.first][after_right.second.second] == 0)
            {
                if (after_right.second.first == goal.first && after_right.second.second == goal.second)
                {
                    printf("-1");
                    return 0;
                }
                else if (after_right.first.first == goal.first && after_right.first.second == goal.second)
                {
                    printf("%d", cnt);
                    return 0;
                }
                else
                {
                    s.push(make_pair(cnt, after_right));
                }
            }
            after_left = left(tmp);
            if (status[after_left.first.first][after_left.first.second][after_left.second.first][after_left.second.second] == 0)
            {
                if (after_left.second.first == goal.first && after_left.second.second == goal.second)
                {
                    printf("-1");
                    return 0;
                }
                else if (after_left.first.first == goal.first && after_left.first.second == goal.second)
                {
                    printf("%d", cnt);
                    return 0;
                }
                else
                {
                    s.push(make_pair(cnt, after_left));
                }
            }
            after_up = up(tmp);
            if (status[after_up.first.first][after_up.first.second][after_up.second.first][after_up.second.second] == 0)
            {
                if (after_up.second.first == goal.first && after_up.second.second == goal.second)
                {
                    printf("-1");
                    return 0;
                }
                else if (after_up.first.first == goal.first && after_up.first.second == goal.second)
                {
                    printf("%d", cnt);
                    return 0;
                }
                else
                {
                    s.push(make_pair(cnt, after_up));
                }
            }
            after_down = down(tmp);
            if (status[after_down.first.first][after_down.first.second][after_down.second.first][after_down.second.second] == 0)
            {
                if (after_down.second.first == goal.first && after_down.second.second == goal.second) {
                    printf("-1");
                    return 0;
                }
                else if (after_down.first.first == goal.first && after_down.first.second == goal.second) {
                    printf("%d", cnt);
                    return 0;
                }
                else {
                    s.push(make_pair(cnt, after_down));
                }
            }
        }
    }
    printf("-1");
}