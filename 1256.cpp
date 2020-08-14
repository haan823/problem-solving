#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
int dp[201][201];
string answer = "";

int combination(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    else if(dp[n][r] != 0){
        return dp[n][r];
    }
    else{
        return dp[n][r] = min(combination(n-1, r-1) + combination(n-1, r), 1000000000);
    }
}

void query(int n, int m, int k){
    if(n + m == 0){
        return;
    }
    else if(n == 0){
        answer.append("z");
        query(n, m-1, k);
    }
    else if(m == 0){
        answer.append("a");
        query(n-1, m, k);
    }
    else{
        int acnt = combination(n+m-1, m);
        if(acnt >= k){
            answer.append("a");
            query(n-1, m, k);
        }
        else{
            answer.append("z");
            query(n, m-1, k-acnt);
        }
    }
}
int main(){
    cin >> n >> m >> k;

    if(k>combination(n+m, n)){
        cout << "-1";
    }
    else{
        query(n, m, k);
        cout << answer;
    }
}