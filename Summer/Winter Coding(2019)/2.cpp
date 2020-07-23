#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<pair<int, int>> map;
    map.push_back(make_pair(1, 0));

    for (int j = 1; j < n; j++)
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i].first == 1)
            {
                tmp.push_back(make_pair(1, 0));
                tmp.push_back(make_pair(0, map[i].second));
                tmp.push_back(make_pair(1, 1));
            }
            else
            {
                tmp.push_back(make_pair(0, map[i].second));
            }
        }
        map = tmp;
    }

    for (int i = 0; i < map.size(); i++)
    {
        answer.push_back(map[i].second);
    }
    return answer;
}