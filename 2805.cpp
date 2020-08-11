#include <iostream>
#include <vector>

using namespace std;

long long n, m, max_h, l, r, mid, res;
vector<long long> v;

int main(){
    cin >> n >> m;
    for(long long i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(tmp > max_h){
            max_h = tmp;
        }
    }
    l = 0;
    r = max_h;
    while(l<=r){
        long long sum = 0;
        mid = (l+r)/2;
        for(long long i=0; i<n; i++){
            if(v[i]>mid){
                sum += v[i]-mid;
            }
        }
        if(sum >= m){
            if(res < mid){
                res = mid;
            }
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << res;
}