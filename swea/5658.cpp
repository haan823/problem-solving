#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b)
{
    return a > b;
}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else
    {
        return (c - 'A') + 10;
    }
}

int hextoi(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += (ctoi(s[i]) * pow(16, s.size() - i - 1));
    }
    return res;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    //freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, k;
        string s = "";
        vector<int> v;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            char tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        int e = n / 4;
        for (int i = 0; i < e; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                string tmp = "";
                for (int m = e * j; m < e * j + e; m++)
                {
                    tmp.push_back(s[(m + i) % n]);
                }
                int tmpi = hextoi(tmp);
                v.push_back(tmpi);
            }
        }
        sort(v.begin(), v.end(), compare);
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << "#" << test_case << " " << v[k - 1] << "\n";
    }
    return 0;
}