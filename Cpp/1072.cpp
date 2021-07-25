#include <iostream>
#include <vector>

using namespace std;

long long x, y, z, res = -1;

int main(){
    cin >> x >> y;
    z = (y * 100) / x;

    int l, r, m;
    l = 0;
    r = 1000000000;

    long long nx, ny, nz;

    while(l<=r){
        m = (l+r)/2;
        nx = x + m;
        ny = y + m;
        nz = (ny * 100) / nx;
        if(z!=nz){
            r = m - 1;
            res = m;
        }
        else{
            l = m + 1;
        }
    }

    cout << res;
}