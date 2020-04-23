#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int **left(int **x, int n)
{
    int **tmp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
        }
    }

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            s.pop();
        }
        v.clear();
        for (int j = 0; j < n; j++)
        {
            if (x[i][j] == 0)
            {
                continue;
            }
            if (x[i][j] != 0)
            {
                if (s.empty())
                {
                    s.push(x[i][j]);
                }
                else if (s.top() == x[i][j])
                {
                    s.top() *= 2;
                    v.push_back(s.top());
                    s.pop();
                }
                else if (!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                    s.push(x[i][j]);
                }
            }
        }
        if (!s.empty())
        {
            v.push_back(s.top());
        }
        for (int j = 0; j < v.size(); j++)
        {
            tmp[i][j] = v[j];
        }
    }

    return tmp;
}

/*----------------------------------------------------------------*/
int **right(int **x, int n)
{
    int **tmp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
        }
    }

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            s.pop();
        }
        v.clear();
        for (int j = n - 1; j >= 0; j--)
        {
            if (x[i][j] == 0)
            {
                continue;
            }
            if (x[i][j] != 0)
            {
                if (s.empty())
                {
                    s.push(x[i][j]);
                }
                else if (s.top() == x[i][j])
                {
                    s.top() *= 2;
                    v.push_back(s.top());
                    s.pop();
                }
                else if (!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                    s.push(x[i][j]);
                }
            }
        }
        if (!s.empty())
        {
            v.push_back(s.top());
        }
        for (int j = 0; j < v.size(); j++)
        {
            tmp[i][n - j - 1] = v[j];
        }
    }

    return tmp;
}
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
int **up(int **x, int n)
{
    int **tmp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
        }
    }

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            s.pop();
        }
        v.clear();
        for (int j = 0; j < n; j++)
        {
            if (x[j][i] == 0)
            {
                continue;
            }
            if (x[j][i] != 0)
            {
                if (s.empty())
                {
                    s.push(x[j][i]);
                }
                else if (s.top() == x[j][i])
                {
                    s.top() *= 2;
                    v.push_back(s.top());
                    s.pop();
                }
                else if (!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                    s.push(x[j][i]);
                }
            }
        }
        if (!s.empty())
        {
            v.push_back(s.top());
        }
        for (int j = 0; j < v.size(); j++)
        {
            tmp[j][i] = v[j];
        }
    }

    return tmp;
}
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
int **down(int **x, int n)
{
    int **tmp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
        }
    }

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            s.pop();
        }
        v.clear();
        for (int j = n - 1; j >= 0; j--)
        {
            if (x[j][i] == 0)
            {
                continue;
            }
            if (x[j][i] != 0)
            {
                if (s.empty())
                {
                    s.push(x[j][i]);
                }
                else if (s.top() == x[j][i])
                {
                    s.top() *= 2;
                    v.push_back(s.top());
                    s.pop();
                }
                else if (!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                    s.push(x[j][i]);
                }
            }
        }
        if (!s.empty())
        {
            v.push_back(s.top());
        }
        for (int j = 0; j < v.size(); j++)
        {
            tmp[n - j - 1][i] = v[j];
        }
    }

    return tmp;
}
/*----------------------------------------------------------------*/

int main()
{
    int n;
    int **init;
    vector<int **> final;

    cin >> n;
    init = new int *[n];

    for (int i = 0; i < n; i++)
    {
        init[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> init[i][j];
        }
    }
    final.push_back(init);

    for (int i = 0; i < 5; i++)
    {
        vector<int **> v_tmp;
        v_tmp.clear();
        for (int j = 0; j < final.size(); j++)
        {
            v_tmp.push_back(left(final[j], n));
            v_tmp.push_back(right(final[j], n));
            v_tmp.push_back(up(final[j], n));
            v_tmp.push_back(down(final[j], n));
        }
        final = v_tmp;
    }

    int max = 0;

    for (int i = 0; i < final.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (final[i][j][k] >= max)
                {
                    max = final[i][j][k];
                }
            }
        }
    }

    printf("%d\n", max);
}