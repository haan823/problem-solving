#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, c;
int dp[21][21];
int fact[21];
int visit[21];
vector<int> input;

int main(){
    fact[0] = 1;
    for(int i=1; i<=20; i++){
        fact[i] = fact[i-1] * i;
    }
    cin >> n >> c;
    if(c == 1){
        long k;
        cin >> k;
        string sb = "";
        for(int i=0; i<n; i++){
            for(int j=1; j<=n; j++){
                if(visit[j]){
                    continue;
                }
                if(k > fact[n-i+1]){
                    k -= fact[n-i+1];
                }
                else{
                    cout << j;
                    sb.append(to_string(j));
                    sb.append(" ");
                    visit[j] = 1;
                    break;
                }
            }
        }
        cout << sb;
    }
    else{
        vector<int> nums;
        for(int i=1; i<=n; i++){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        long res = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<nums[i]; j++){
                if(!visit[j]){
                    res += fact[n-i-1];
                }
            }
            visit[nums[i]] = 1;
        }
        cout << res+1;
    }
}