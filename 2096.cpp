#include <iostream>
#include <vector>

using namespace std;

int n;
int map[100000][3];
int max_dp[3], min_dp[3];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> map[i][j];
        }
    }

    max_dp[0] = map[0][0]; max_dp[1] = map[0][1]; max_dp[2] = map[0][2];
    min_dp[0] = map[0][0]; min_dp[1] = map[0][1]; min_dp[2] = map[0][2];

    for(int i=1; i<n; i++){
        int tmp0 = max_dp[0], tmp2 = max_dp[2];
        max_dp[0] = max(max_dp[0], max_dp[1])+map[i][0];
        max_dp[2] = max(max_dp[1], max_dp[2])+map[i][2];
        max_dp[1] = max(max(tmp0, tmp2), max_dp[1])+map[i][1];

        tmp0 = min_dp[0]; tmp2 = min_dp[2];
        min_dp[0] = min(min_dp[0], min_dp[1])+map[i][0];
        min_dp[2] = min(min_dp[1], min_dp[2])+map[i][2];
        min_dp[1] = min(min(tmp0, tmp2), min_dp[1])+map[i][1];
    }

    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
}