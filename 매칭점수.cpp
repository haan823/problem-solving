#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string, int> m;
vector<int> st[20];
vector<double> score[20];      // {기본 점수, 링크 점수}
vector<pair<int, int>> result; // index, score

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}
string lower(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

int find_word(string word, string page)
{
    page = lower(page);
    int cnt = 0;
    while (page.find(word) != string::npos)
    {
        int start_pos = page.find(word);
        int end_pos = start_pos + word.size() - 1;
        cnt++;
        if ((start_pos - 1 >= 0 && page[start_pos - 1] >= 'a' && page[start_pos - 1] <= 'Z') || (end_pos + 1 <= page.size() - 1 && page[end_pos + 1] >= 'a' && page[end_pos + 1] <= 'Z'))
        {
            cnt--;
        }
        page = page.substr(end_pos + 1);
    }
    return cnt;
}

int solution(string word, vector<string> pages)
{
    int answer = 0, max_num = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        int basic_score, link_score;
        // url
        int start_pos = pages[i].find("<meta");
        string tmp = pages[i].substr(start_pos);
        tmp = tmp.substr(tmp.find("https://"));
        tmp = tmp.substr(0, tmp.find("\"/>"));
        m[tmp] = i;
    }
    for (int i = 0; i < pages.size(); i++)
    {
        // href
        while (pages[i].find("<a href") != string::npos)
        {
            int start_pos = pages[i].find("<a href");
            string tmp = pages[i].substr(start_pos);
            tmp = tmp.substr(tmp.find("https://"));
            tmp = tmp.substr(0, tmp.find("\"/>"));
            st[i].push_back(m[tmp]);
        }
        // word
        page = lower(page);
        int cnt = 0;
        while (page.find(word) != string::npos)
        {
            int start_pos = page.find(word);
            int end_pos = start_pos + word.size() - 1;
            cnt++;
            if ((start_pos - 1 >= 0 && page[start_pos - 1] >= 'a' && page[start_pos - 1] <= 'Z') || (end_pos + 1 <= page.size() - 1 && page[end_pos + 1] >= 'a' && page[end_pos + 1] <= 'Z'))
            {
                cnt--;
            }
            page = page.substr(end_pos + 1);
        }
        return cnt;
        score[i].push_back(find_word(word, pages[i]));
        score[i].push_back(0);
    }

    for (int i = 0; i < pages.size(); i++)
    {
        if (st[i].size() == 0)
        {
            continue;
        }
        else
        {
            double tmp = score[i][0] / st[i].size();
            for (int j = 0; j < st[i].size(); j++)
            {
                score[st[i][j]][1] += tmp;
            }
        }
    }

    for (int i = 0; i < pages.size(); i++)
    {
        double tmp = score[i][0] + score[i][1];
        result.push_back({i, tmp});
    }
    sort(result.begin(), result.end(), compare);
    answer = result.front().first;
    return answer;
}