#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
set<int> s;
int len;
bool check[8];

void dfs(vector<string> &u_id, vector<string> &b_id, int i, int num)
{
    if (i == len)
    {
        s.emplace(num);
        return;
    }

    for (int j = 0; j < u_id.size(); j++)
    {
        int z;
        if (u_id[j].size() != b_id[i].size())
            continue;

        if (check[j] == true)
            continue;

        for (z = 0; z < u_id[j].size(); z++)
        {
            if (b_id[i][z] == '*')
                continue;
            if (u_id[j][z] != b_id[i][z])
                break;
        }

        if (z == u_id[j].size())
        {
            check[j] = true;
            dfs(u_id, b_id, i + 1, num | (1 << j));
            check[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}
int main()
{
    vector<string> u, b;
    u.push_back("frodo");
    u.push_back("fradi");
    u.push_back("crodo");
    u.push_back("abc123");
    u.push_back("frodoc");
    b.push_back("fr*d*");
    b.push_back("*rodo");
    b.push_back("******");
    b.push_back("******");
    solution(u, b);
    for (int i : s)
    {
        cout << i << " ";
    }
}