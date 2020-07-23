#include <iostream>
using namespace std;

int n;
int d[16];
int t[16];
int p[16];
int res = 0;


int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }

    for(int i=1; i<=n+1; i++){
        for(int j=1; j<i; j++){
            if(d[j]>d[i]){
                d[i] = d[j];
            }
            if(j+t[j]==i){
                if(d[j]+p[j]>d[i]){
                    d[i] = d[j] + p[j];
                }
            }
        }

        if(d[i]>res){
            res = d[i];
        }
    }
    cout << res;
}