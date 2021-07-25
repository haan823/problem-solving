#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, b, c;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> b >> c;

    long cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        v[i] -= b;
        cnt += 1;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            int tmp;
            tmp = v[i] / c;
            if (v[i] % c == 0)
            {
                cnt += tmp;
            }
            else
            {
                cnt += (tmp + 1);
            }
        }
    }

    cout << cnt;
}