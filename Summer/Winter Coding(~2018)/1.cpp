#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    stack<char> st;
    vector<char> vt;
    for (int i = skill.size() - 1; i >= 0; i--)
    {
        vt.push_back(skill[i]);
        st.push(skill[i]);
    }
    for (int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << " ";
    }
    for (string s : skill_trees)
    {
        stack<char> st_tmp = st;
        bool res;
        int t;
        for (t = 0; t < s.size(); t++)
        {
            if (find(vt.begin(), vt.end(), s[t]) == vt.end())
            {
                res = true;
            }
            else if (s[t] == st_tmp.top())
            {
                res = true;
                st_tmp.pop();
            }
            else
            {
                res = false;
                break;
            }
        }
        if (res && t == s.size())
        {
            answer += 1;
        }
    }
    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    solution(skill, skill_trees);
}