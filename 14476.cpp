#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
pair<int, int> answer = make_pair(-1, 0);
vector<int> input;
vector<int> gcdLtoR;
vector<int> gcdRtoL;

int find_gcd(int a, int b){
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    gcdLtoR.push_back(input.front());
    for(int i=1; i<n; i++){
        gcdLtoR.push_back(find_gcd(gcdLtoR[i-1], input[i]));
    }
    stack<int> s;
    s.push(input.back());
    for(int i=n-2; i>=0; i--){
        s.push(find_gcd(s.top(), input[i]));
    }
    while(!s.empty()){
        gcdRtoL.push_back(s.top());
        s.pop();
    }


    for(int i=0; i<n; i++){
        int k, gcd;
        if(i == 0){
            k = input[i];
            gcd = gcdRtoL[i+1];
            if(k % gcd == 0){
                continue;
            }
            else{
                if(gcd>answer.first){
                    answer.first = gcd;
                    answer.second = k;
                }
            }
        }
        else if(i == n-1){
            k = input[i];
            gcd = gcdLtoR[i-1];
            if(k % gcd == 0){
                continue;
            }
            else{
                if(gcd>answer.first){
                    answer.first = gcd;
                    answer.second = k;
                }
            }
        }
        else{
            k = input[i];
            gcd = find_gcd(gcdLtoR[i-1], gcdRtoL[i+1]);
            if(k % gcd == 0){
                continue;
            }
            else{
                if(gcd>answer.first){
                    answer.first = gcd;
                    answer.second = k;
                }
            }
        }
    }
    if(answer.first == -1){
        cout << -1;
    }
    else{
        cout << answer.first << " " << answer.second;
    }
}