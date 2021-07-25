#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> v;
vector<int> sub1, sub2;
int sum;

int main(){
    cin >> n;
    for(int i=0; i<4; i++){
        v.push_back({});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            int tmp;
            cin >> tmp;
            v[j].push_back(tmp);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum = v[0][i] + v[1][j];
            sub1.push_back(sum);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum = v[2][i] + v[3][j];
            sub2.push_back(sum);
        }
    }
    sort(sub1.begin(), sub1.end());
    sort(sub2.begin(), sub2.end());

    long long res = 0;
    int d;

    for(int i=0; i<sub1.size(); i++){
        d = -sub1[i];
        auto lb = lower_bound(sub2.begin(), sub2.end(), d);
        auto ub = upper_bound(sub2.begin(), sub2.end(), d);
        res += (ub-lb);
    }
    cout << res;
}