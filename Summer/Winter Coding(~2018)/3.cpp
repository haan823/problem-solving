#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;


    vector<vector<int>> v;
    vector<int> tmp;
    for (int i = 0; i < N + 1; i++)
    {
        tmp.push_back(0);
    }
    for (int i = 0; i < N + 1; i++)
    {
        v.push_back(tmp);
    }

    for (vector<int> i : road)
    {
        if (v[i[0]][i[1]] != 0 && v[i[0]][i[1]] < i[2])
        {
            continue;
        }
        v[i[0]][i[1]] = i[2];
        v[i[1]][i[0]] = i[2];
    }

    set<int> s;
    queue<pair<int, int>> st;

    st.push(make_pair(1, K));

    while (!st.empty())
    {
        pair<int, int> tmp = st.front();
        s.insert(tmp.first);
        st.pop();
        for (int i = 1; i < N + 1; i++)
        {
            if (v[tmp.first][i] > 0 && v[tmp.first][i] <= tmp.second)
            {
                if (tmp.second - v[tmp.first][i] >= 0)
                {
                    st.push(make_pair(i, tmp.second - v[tmp.first][i]));
                    v[tmp.first][i] = 0;
                    v[i][tmp.first] = 0;
                }
            }
        }
    }

    answer = s.size();

    return answer;
}
