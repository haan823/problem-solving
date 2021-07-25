#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<string> s = {"a", "b", "c", "d"};
    do
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(s.begin(), s.end()));
}