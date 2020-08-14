#include <iostream>
#include <vector>

using namespace std;

int c;
vector<int> input;

int euler(int n){
    int res = 1;
    for(int p=2; p*p<=n; p++){
        if(n%p==0){
            int pm = 1;
            while(n%p==0){
                n/=p;
                pm*=p;
            }
            res *= (pm - (pm/p));
        }
    }
    if(n!=1){
        res *= n - 1;
    }
    return res;
}

int main(){
    cin >> c;
    for(int i=0; i<c; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    for(int i=0; i<c; i++){
        int n = input[i];
        int res = 0;
        for(int j=2; j<=n; j++){
            res += euler(j);
        }
        res *= 2;
        res += 3;

        cout << res << "\n";
    }
}