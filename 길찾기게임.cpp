#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct _node
{
    int x;
    int y;
    int number;
} node;

struct compare
{
    bool operator()(const node &a, const node &b)
    {
        if (a.y > b.y)
        {
            return true;
        }
        else
        {
            return (a.x < b.x);
        }
    }
} bool compare(node &a, node &b)
{
}

node tree[10001];

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    priority_queue<node, vector<node>, compare> pq;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        pq.push({nodeinfo[i][0], nodeinfo[i][1], i + 1});
    }

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo;
    vector<vector<int>> answer = solution(nodeinfo);
    for (int i = 0; i < answer[0].size(); i++)
    {
        cout << answer[0][i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < answer[1].size(); i++)
    {
        cout << answer[1][i] << " ";
    }
}