#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string mtot(int m){
    string s = "";
    s += to_string((m/60)/10);
    s += to_string((m/60)%10);
    s += ':';
    s += to_string((m%60)/10);
    s += to_string((m%60)%10);
    return s;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq;
    int bus_t, s, result, nt;
    for (int i = 0; i < timetable.size(); i++)
    {
        int t = ((timetable[i][0] - '0') * 600) + ((timetable[i][1] - '0') * 60) + (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0') * 1;
        pq.push(t);
    }
    s = pq.size();
    for (int i = 0; i < n; i++)
    {
        bus_t = 540 + (i * t);
        for (int j = 0; j < m; j++)
        {
            if (!pq.empty())
            {
                if(pq.top()<=bus_t){
                    nt = pq.top();
                    pq.pop();
                }
            }
            else
            {
                result = (540 + ((n-1) * t));
                return mtot(result);
            }
        }
    }
    if(s == pq.size()){
        result = (540 + ((n-1) * t));
        return mtot(result);
    }
    else{
        result = nt - 1;
        return mtot(result);
    }
}

int main()
{
    int n = 1, t = 1, m = 1;
    vector<string> timetable = {"24:00"};
    cout << solution(n, t, m, timetable);
}