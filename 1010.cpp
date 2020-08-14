#include <iostream>

using namespace std;

int t, n, m;
int dp[31][31];

int main(){
    for(int i=0; i<31; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || i==j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        cout << dp[m][n] << "\n";
    }
}