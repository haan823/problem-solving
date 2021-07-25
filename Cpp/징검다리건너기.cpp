#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0;
    vector<int> stones_index;
    for (int i = 0; i < stones.size(); i++)
    {
        stones_index.push_back(i);
    }
    while (true)
    {
        int i, prev_i = -1;
        vector<int> nxt_stones_index;
        for (i = 0; i < stones_index.size(); i++)
        {
            if (stones_index[i] - prev_i > k)
            {
                return answer;
            }
            else
            {
                prev_i = stones_index[i];
            }
            stones[stones_index[i]]--;
            if (stones[stones_index[i]] > 0)
            {
                nxt_stones_index.push_back(stones_index[i]);
            }
        }
        stones_index = nxt_stones_index;
        answer++;
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(stones, k);
}