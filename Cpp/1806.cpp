#include <iostream>
#include <vector>

using namespace std;

int n, s, min_num=987654321;
vector<int> v;

int main(){
    cin >> n >> s;
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    int l = 0;
    int h = 0;
    int sum = v[0];
    int len;
    while(h<n){
        if(sum == s){
            len = h-l+1;
            if(len<min_num){
                min_num = len;
            }
            h++;
            sum += v[h];
        }
        else if(sum > s){
            len = h-l+1;
            if(len<min_num){
                min_num = len;
            }
            sum -= v[l];
            l++;
        }
        else{
            h++;
            sum += v[h];
        }
    }
    if(min_num == 987654321){
        cout << 0;
    }
    else{
        cout << min_num;
    }
}