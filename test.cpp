#include <string>
#include <vector>

using namespace std;

int map[15][15];
int visit[15][15];
int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {-1, 0, 1, 1, 0, -1};

vector<int> solution(vector<vector<int>> blocks)
{
    vector<int> answer;
    int total = 0;
    for (int i = 0; i < blocks.size(); i++)
    {
        for (int j = i; j <= i; j++)
        {
            total++;
        }
    }
    for (int i = 0; i < blocks.size(); i++)
    {
        map[i][blocks[i][0]] = blocks[i][1];
        visit[i][blocks[i][0]] = 1;
        total--;
    }

    while (total > 0)
    {
        for (int i = 0; i < blocks.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 * &&nx < blocks.size() && ny >= 0 && ny <= nx && !visit[nx][ny])
                    {
                        if (k == 0 && visit[i][j - 1])
                        {
                            map[nx][ny] = map[i][j] + map[i][j - 1];
                        }
                        else if (k == 1 && visit[i][j + 1])
                        {
                            map[nx][ny] = map[i][j] + map[i][j + 1];
                        }
                        else if (k == 2 && visit[i - 1][j])
                        {
                            map[nx][ny] = map[i - 1][j] - map[i][j];
                        }
                        else if (k == 3 && visit[i + 1][j])
                        {
                            map[nx][ny] = map[i][j] - map[i + 1][j];
                        }
                        else if (k == 4 && visit[i + 1][j + 1])
                        {
                            map[nx][ny] = map[i][j] - map[i + 1][j + 1];
                        }
                        else if (k == 5 && visit[i - 1][j - 1])
                        {
                            map[nx][ny] = map[i - 1][j - 1] - map[i][j];
                        }
                        visit[nx][ny] = 1;
                        total--;
                    }
                }
            }
        }
    }
    for (int i = 0; i < blocks.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(map[i][j]);
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> blocks = {{0, 50}, {0, 22}, {2, 10}, {1, 4}, {4, -13}};
    vector<int> answer = solution(blocks);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}