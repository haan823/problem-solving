#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[11];
int op[4];
long max_num = -1000000000;
long min_num = 1000000000;
vector<int> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
        if(op[i] > 0){
            if(i == 0){
                for(int j=0; j<op[i]; j++){
                    v.push_back(1);
                }
            }
            else if(i == 1){
                for(int j=0; j<op[i]; j++){
                    v.push_back(2);
                }
            }
            else if(i == 2){
                for(int j=0; j<op[i]; j++){
                    v.push_back(3);
                }
            }
            else{
                for(int j=0; j<op[i]; j++){
                    v.push_back(4);
                }
            }
        }
        else{
            continue;
        }
    }

    do{
        int tmp = a[0];
        for(int i=1; i<n; i++){
            if(v[i-1] == 1){
                tmp += a[i];
            }
            else if(v[i-1] == 2){
                tmp -= a[i];
            }
            else if(v[i-1] == 3){
                tmp *= a[i];
            }
            else if(v[i-1] == 4){
                if(tmp<0 && a[i]>0){
                    tmp = -tmp;
                    tmp /= a[i];
                    tmp = -tmp;
                }
                else{
                    tmp /= a[i];
                }
            }
        }
        if(tmp >= max_num){
            max_num = tmp;
        }
        if(tmp <= min_num){
            min_num = tmp;
        }
    }while(next_permutation(v.begin(), v.end()));

    cout << max_num << "\n" << min_num;
}