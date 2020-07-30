#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> new_weak;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;

    for (int i = 0; i < weak.size(); i++)
    {
        vector<int> tmp;
        for (int j = i; j < weak.size(); j++)
        {
            tmp.push_back(weak[j]);
        }
        for (int j = 0; j < i; j++)
        {
            tmp.push_back(weak[j] + n);
        }
        new_weak.push_back(tmp);
    }

    for (int i = 1; i <= dist.size(); i++)
    {
        vector<int> tmp;
        for (int j = 0; j < dist.size() - i; j++)
        {
            tmp.push_back(0);
        }
        for (int j = 0; j < i; j++)
        {
            tmp.push_back(1);
        }
        do
        {
            vector<int> member;
            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j])
                {
                    member.push_back(dist[j]);
                }
            }
            do
            {
                for (int j = 0; j < new_weak.size(); j++)
                {
                    int now = new_weak[j][0];
                    for (int k = 0; k < member.size(); k++)
                    {
                        now += member[k];
                        bool flag = false;
                        for (int x = 0; x < new_weak[j].size(); x++)
                        {
                            if (new_weak[j][x] > now)
                            {
                                now = new_weak[j][x];
                                flag = true;
                                break;
                            }
                        }
                        if (!flag)
                        {
                            return i;
                        }
                    }
                }
            } while (next_permutation(member.begin(), member.end()));
        } while (next_permutation(tmp.begin(), tmp.end()));
    }

    return -1;
}

int main()
{
    int n = 12, answer;
    vector<int> weak = {1, 3, 4, 9, 10};
    vector<int> dist = {3, 5, 7};
    answer = solution(n, weak, dist);
    cout << answer;
}