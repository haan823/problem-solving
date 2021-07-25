#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
int low, high;
vector<int> v;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    low = 0;
    high = 0;
    while(high<n){
        int sum = 0;
        for(int i=low; i<=high; i++){
            sum+=v[i];
        }
        if(sum == m){
            cnt++;
            low++;
        }
        else if(sum < m){
            high++;
        }
        else{
            low++;
        }
    }
    cout << cnt;
}