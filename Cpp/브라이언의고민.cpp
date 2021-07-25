#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence)
{
    string answer = "";

    int count[26] = {
        0,
    };
    int used[26] = {
        0,
    };
    int start_index[26] = {
        0,
    };
    int end_index[26] = {
        0,
    };
    int checked[1000] = {
        0,
    };

    vector<int> order;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            count[sentence[i] - 'a']++;
            if (!used[sentence[i] - 'a'])
            {
                used[sentence[i] - 'a'] = 1;
                start_index[sentence[i] - 'a'] = i;
                order.push_back(sentence[i] - 'a');
            }
        }
        else if (sentence[i] == ' ')
        {
            return "invalid";
        }
    }

    for (int i = sentence.size(); i > 0; i--)
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            if (!end_index[sentence[i] - 'a'])
            {
                end_index[sentence[i] - 'a'] = i;
            }
        }
    }

    // 규칙1
    for (int i = 0; i < order.size(); i++)
    {
        if (count[order[i]] == 1 || count[order[i]] >= 3)
        {
            int start = start_index[order[i]] - 1;
            int end = end_index[order[i]] + 1;
            if (start < 0 || end >= sentence.size())
            {
                return "invalid";
            }
            else if (checked[start] != 0 || checked[end] != 0)
            {
                return "invalid";
            }
            else
            {

                // checked 배열에 규칙1 표시
                bool flag1 = false;
                bool flag2 = false;
                for (int j = start + 1; j <= end - 1; j += 2)
                {
                    if (sentence[j] == (order[i] + 'a'))
                    {
                        flag1 = true;
                    }
                    else
                    {
                        flag2 = false;
                        break;
                    }
                }
                for (int j = start; j <= end; j += 2)
                {
                    if (sentence[j] >= 'A' && sentence[j] <= 'Z')
                    {
                        flag2 = true;
                    }
                    else
                    {
                        flag2 = false;
                        break;
                    }
                }
                if (flag1 && flag2)
                {
                    for (int j = start; j <= end; j++)
                    {
                        checked[j] = 1;
                    }
                }
                else
                {
                    return "invalid";
                }
            }
        }
    }

    // 규칙 2
    for (int i = 0; i < order.size(); i++)
    {
        if (count[order[i]] == 2)
        {
            int start = start_index[order[i]] + 1;
            int end = end_index[order[i]] - 1;

            bool flag1 = false;
            bool flag2 = false;
            bool flag3 = false;
            bool flag4 = false;

            for (int j = start; j <= end; j++)
            {
                if (checked[j] == 1)
                {
                    flag1 = true;
                }
                else
                {
                    flag1 = false;
                    break;
                }
            }

            for (int j = start; j <= end; j++)
            {
                if (sentence[j] >= 'A' && sentence[j] <= 'Z')
                {
                    flag2 = true;
                }
                else
                {
                    flag2 = false;
                    break;
                }
            }
            if (i < order.size() - 1)
            {
                for (int j = start + 1; j <= end - 1; j += 2)
                {
                    if (sentence[j] == order[i + 1] + 'a')
                    {
                        flag3 = true;
                    }
                    else
                    {
                        flag3 = false;
                        break;
                    }
                }
                for (int j = start; j <= end; j += 2)
                {
                    if (sentence[j] >= 'A' && sentence[j] <= 'Z')
                    {
                        flag4 = true;
                    }
                    else
                    {
                        flag4 = false;
                        break;
                    }
                }
            }

            if (flag1)
            {
                checked[start - 1] = 2;
                checked[end + 1] = 2;
            }
            else if (flag2)
            {
                checked[start - 1] = 2;
                checked[end + 1] = 2;
                for (int j = start; j <= end; j++)
                {
                    checked[j] = 3;
                }
            }
            else if (flag3 && flag4)
            {
                checked[start - 1] = 2;
                checked[end + 1] = 2;
                for (int j = start; j <= end; j++)
                {
                    checked[j] = 1;
                }
                i++;
            }
            else
            {
                return "invalid";
            }
        }
    }

    vector<string> res;
    string tmp;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (checked[i] == 0)
        {
            tmp.push_back(sentence[i]);
            res.push_back(tmp);
            tmp.clear();
        }
        else if (checked[i] == 2)
        {
            int start = i;
            int end;

            for (int j = i + 1; j < sentence.size(); j++)
            {
                if (checked[j] == 2)
                {
                    end = j;
                    break;
                }
            }

            // 규칙2 사이가 규칙1로 차 있을 때
            if (checked[start + 1] == 1)
            {
                for (int j = start + 1; j < end; j += 2)
                {
                    tmp.push_back(sentence[j]);
                }
                res.push_back(tmp);
                tmp.clear();
            }

            // 규칙2 사이가 대문자로 차 있을 때
            else
            {
                for (int j = start + 1; j < end; j++)
                {
                    tmp.push_back(sentence[j]);
                }
                res.push_back(tmp);
                tmp.clear();
            }

            i = end;
        }
        else if (checked[i] == 1)
        {
            int start = i;
            int end = i + (count[sentence[i + 1] - 'a'] * 2);
            for (int j = start; j <= end; j += 2)
            {
                tmp.push_back(sentence[j]);
            }
            res.push_back(tmp);
            tmp.clear();

            i = end;
        }
        else
        {
            "something wrong";
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        answer += res[i];
        answer += " ";
    }

    if (!answer.empty())
    {
        answer.pop_back();
    }

    return answer;
}
