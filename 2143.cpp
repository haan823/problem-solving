#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
vector<int> a, b;
vector<int> subA, subB;

int main(){
    cin >> t >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        int sum = a[i];
        subA.push_back(sum);
        for(int j=i+1; j<n; j++){
            sum += a[j];
            subA.push_back(sum);
        }
    }
    for(int i=0; i<m; i++){
        int sum = b[i];
        subB.push_back(sum);
        for(int j=i+1; j<m; j++){
            sum += b[j];
            subB.push_back(sum);
        }
    }
    sort(subB.begin(), subB.end());

    long long res = 0;

    for(long long item : subA){
        long long d = t - item;
        auto ub = upper_bound(subB.begin(), subB.end(), d);
        auto lb = lower_bound(subB.begin(), subB.end(), d);
        res += (ub - lb);
    }
    cout << res;
}