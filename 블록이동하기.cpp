#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int visit[101][101][101][101];
int s, min_num = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct _robot
{
    pair<int, int> a;
    pair<int, int> b;
} robot;

bool robot_can_go(robot r)
{
    if (r.a.first >= 1 && r.a.first <= s && r.b.first >= 1 && r.b.first <= s && r.a.second >= 1 && r.a.second <= s && r.b.second >= 1 && r.b.second <= s)
    {
        if (map[r.a.first][r.a.second] == 0 && map[r.b.first][r.b.second] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    s = board.size();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            map[i + 1][j + 1] = board[i][j];
        }
    }
    robot r;
    r.a.first = 1;
    r.a.second = 1;
    r.b.first = 1;
    r.b.second = 2;

    queue<pair<robot, int>> st;
    st.push(make_pair(r, 0));
    visit[r.a.first][r.a.second][r.b.first][r.b.second] = 1;
    visit[r.b.first][r.b.second][r.a.first][r.a.second] = 1;

    while (!st.empty())
    {
        robot current_robot = st.front().first;
        int current_depth = st.front().second;
        st.pop();

        if ((current_robot.a.first == s && current_robot.a.second == s) || (current_robot.b.first == s && current_robot.b.second == s))
        {
            if (current_depth < min_num)
            {
                min_num = current_depth;
            }
        }

        // 가능한 이동 스택에 푸시
        for (int i = 0; i < 4; i++)
        {
            robot tmp;
            tmp.a.first = current_robot.a.first + dx[i];
            tmp.b.first = current_robot.b.first + dx[i];
            tmp.a.second = current_robot.a.second + dy[i];
            tmp.b.second = current_robot.b.second + dy[i];

            if (robot_can_go(tmp) && !visit[tmp.a.first][tmp.a.second][tmp.b.first][tmp.b.second] && !visit[tmp.b.first][tmp.b.second][tmp.a.first][tmp.a.second])
            {
                st.push(make_pair(tmp, current_depth + 1));
                visit[tmp.a.first][tmp.a.second][tmp.b.first][tmp.b.second] = 1;
                visit[tmp.b.first][tmp.b.second][tmp.a.first][tmp.a.second] = 1;
            }
        }

        // 가능한 회전 스택에 푸시
        if (current_robot.a.first == current_robot.b.first) // 로봇이 가로로 있을 때
        {
            int left_x, left_y, right_x, right_y;
            if (current_robot.a.second > current_robot.b.second)
            {
                left_x = current_robot.a.first;
                right_x = current_robot.b.first;
                left_y = current_robot.b.second;
                right_y = current_robot.a.second;
            }
            else
            {
                left_x = current_robot.a.first;
                right_x = current_robot.b.first;
                left_y = current_robot.a.second;
                right_y = current_robot.b.second;
            }
            robot tmp;

            // 위 체크
            tmp.a.first = left_x - 1;
            tmp.a.second = left_y;
            tmp.b.first = right_x - 1;
            tmp.b.second = right_y;
            if (robot_can_go(tmp))
            {
                robot tmp2, tmp3;
                tmp2.a.first = left_x;
                tmp2.a.second = left_y;
                tmp2.b.first = left_x - 1;
                tmp2.b.second = left_y;
                tmp3.a.first = right_x;
                tmp3.a.second = right_y;
                tmp3.b.first = right_x - 1;
                tmp3.b.second = right_y;
                if (!visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] && !visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second])
                {
                    st.push(make_pair(tmp2, current_depth + 1));
                    visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] = 1;
                    visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second] = 1;
                }
                if (!visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] && !visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second])
                {
                    st.push(make_pair(tmp3, current_depth + 1));
                    visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] = 1;
                    visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second] = 1;
                }
            }

            // 아래 체크
            tmp.a.first = left_x + 1;
            tmp.a.second = left_y;
            tmp.b.first = right_x + 1;
            tmp.b.second = right_y;
            if (robot_can_go(tmp))
            {
                robot tmp2, tmp3;
                tmp2.a.first = left_x;
                tmp2.a.second = left_y;
                tmp2.b.first = left_x + 1;
                tmp2.b.second = left_y;
                tmp3.a.first = right_x;
                tmp3.a.second = right_y;
                tmp3.b.first = right_x + 1;
                tmp3.b.second = right_y;
                if (!visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] && !visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second])
                {
                    st.push(make_pair(tmp2, current_depth + 1));
                    visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] = 1;
                    visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second] = 1;
                }
                if (!visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] && !visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second])
                {
                    st.push(make_pair(tmp3, current_depth + 1));
                    visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] = 1;
                    visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second] = 1;
                }
            }
        }
        else // 로봇이 세로로 있을 때
        {
            int top_x, top_y, bottom_x, bottom_y;
            if (current_robot.a.first > current_robot.b.first)
            {
                top_x = current_robot.b.first;
                bottom_x = current_robot.a.first;
                top_y = current_robot.a.second;
                bottom_y = current_robot.b.second;
            }
            else
            {
                top_x = current_robot.a.first;
                bottom_x = current_robot.b.first;
                top_y = current_robot.a.second;
                bottom_y = current_robot.b.second;
            }
            robot tmp;

            // 오른쪽 체크
            tmp.a.first = top_x;
            tmp.a.second = top_y + 1;
            tmp.b.first = bottom_x;
            tmp.b.second = bottom_y + 1;
            if (robot_can_go(tmp))
            {
                robot tmp2, tmp3;
                tmp2.a.first = top_x;
                tmp2.a.second = top_y;
                tmp2.b.first = top_x;
                tmp2.b.second = top_y + 1;
                tmp3.a.first = bottom_x;
                tmp3.a.second = bottom_y;
                tmp3.b.first = bottom_x;
                tmp3.b.second = bottom_y + 1;
                if (!visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] && !visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second])
                {
                    st.push(make_pair(tmp2, current_depth + 1));
                    visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] = 1;
                    visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second] = 1;
                }
                if (!visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] && !visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second])
                {
                    st.push(make_pair(tmp3, current_depth + 1));
                    visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] = 1;
                    visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second] = 1;
                }
            }

            // 왼쪽 체크
            tmp.a.first = top_x;
            tmp.a.second = top_y - 1;
            tmp.b.first = bottom_x;
            tmp.b.second = bottom_y - 1;
            if (robot_can_go(tmp))
            {
                robot tmp2, tmp3;
                tmp2.a.first = top_x;
                tmp2.a.second = top_y;
                tmp2.b.first = top_x;
                tmp2.b.second = top_y - 1;
                tmp3.a.first = bottom_x;
                tmp3.a.second = bottom_y;
                tmp3.b.first = bottom_x;
                tmp3.b.second = bottom_y - 1;
                if (!visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] && !visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second])
                {
                    st.push(make_pair(tmp2, current_depth + 1));
                    visit[tmp2.a.first][tmp2.a.second][tmp2.b.first][tmp2.b.second] = 1;
                    visit[tmp2.b.first][tmp2.b.second][tmp2.a.first][tmp2.a.second] = 1;
                }
                if (!visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] && !visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second])
                {
                    st.push(make_pair(tmp3, current_depth + 1));
                    visit[tmp3.a.first][tmp3.a.second][tmp3.b.first][tmp3.b.second] = 1;
                    visit[tmp3.b.first][tmp3.b.second][tmp3.a.first][tmp3.a.second] = 1;
                }
            }
        }
    }

    answer = min_num;
    return answer;
}

int main()
{
    // vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 0}};
    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0}};
    // vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 0}};
    int result = solution(board);
    cout << result;
}