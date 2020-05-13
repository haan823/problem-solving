#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool strcmp(string a, string b)
{
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (b[i] == '*')
            {
                continue;
            }
            else if (a[i] == b[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    return answer;
}

int main()
{
    string a = "frodo";
    string b = "fr*de";
    bool answer = strcmp(a, b);
    cout << answer;
}