#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<long long> v(91, 0);

int main(){
    cin >> n;
    v[1] = 1;
    for(int i=1; i<n; i++){
        v[i+1] = v[i-1] + v[i];
    }
    cout << v[n];
}