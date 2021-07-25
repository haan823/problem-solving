#include <iostream>

using namespace std;

int n, k;
int dp[11][11];

int main(){
    cin >> n >> k;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0 || i == j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
            }
        }
    }
    cout << dp[n][k];
}