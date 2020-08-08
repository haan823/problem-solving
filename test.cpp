#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int>> network;
vector<vector<int>> repair;
vector<int> map;

int find(vector<int> &parent, int x)
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        return find(parent, parent[x]);
    }
}

void union_find(vector<int> &parent, int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);

    if (x != y)
    {
        if (x < y)
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
    }
}

bool sameparent(vector<int> &parent, int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);

    if (x == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_connected(vector<vector<int>> network)
{
    vector<int> u;
    for (int i = 0; i <= n; i++)
    {
        u.push_back(i);
    }
    for (int i = 0; i < network.size(); i++)
    {
        union_find(u, network[i][0], network[i][1]);
    }
    for (int i = 1; i < n; i++)
    {
        if (find(u, i) == find(u, i + 1))
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

int solution(int n, vector<vector<int>> network, vector<vector<int>> repair)
{
    int answer = -2;

    if (is_connected(network))
    {
        answer = 1;
    }
    else
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    n = 6;
    network = {{1, 2}, {3, 5}, {4, 2}, {5, 6}};
    repair = {{3, 2, 10}, {5, 4, 15}};

    cout << solution(n, network, repair);
}