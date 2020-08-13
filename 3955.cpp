#include <iostream>
#include <vector>

using namespace std;

int t;
vector<pair<int, int>> input;

typedef struct _gcdresult{
    long long s;
    long long t;
    long long r;
}gcdresult;

gcdresult eGcd(long long a, long long b){
    long long s0 = 1, t0 = 0, r0 = a;
    long long s1 = 0, t1 = 1, r1 = b;
    long long tmp;
    while(r1!=0){
        long long q = r0 / r1;
        tmp = r0 - r1 * q;
        r0 = r1;
        r1 = tmp;
        tmp = s0 - s1 * q;
        s0 = s1;
        s1 = tmp;
        tmp = t0 - t1 * q;
        t0 = t1;
        t1 = tmp;
    }
    gcdresult g;
    g.s = s0;
    g.t = t0;
    g.r = r0;
    return g;
}

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        input.push_back(tmp);
    }

    for(int i=0; i<t; i++){
        int k = input[i].first;
        int c = input[i].second;
        long long x0, y0;
        gcdresult res = eGcd(-k, c);
        if((1%res.r)!=0){
            cout << "IMPOSSIBLE" << "\n";
        }
        else{
            x0 = res.s * (1/res.r);
            y0 = res.t * (1/res.r);
            while(y0<=0 || x0<=0){
                x0+=c;
                y0-=-k;
                if(y0>1e9){
                    break;
                }
            }
            if(y0>1e9){
                cout << "IMPOSSIBLE" << "\n";
            }
            else{
                cout << y0 << "\n";
            }
        }
    }
}