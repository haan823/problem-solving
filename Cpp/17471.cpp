#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, total, minv = 987654321;
int map[11];
vector<int> l[11];

bool is_in(vector<int> v, int n){
    for(int i=0; i<v.size(); i++){
        if(v[i] == n){
            return true;
        }
    }
    return false;
}

int sum(vector<int> v){
    int res = 0;
    for(int i=0; i<v.size(); i++){
        res += map[v[i]];
    }
    return res;
}

bool check(vector<int> one, vector<int> two){
    int visit[11] = {0, };
    queue<int> q;
    // 선거구1 체크
    int os = one[0];
    q.push(os);
    visit[os] = 1;
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        for(int i=0; i<l[cn].size(); i++){
            int nn = l[cn][i];
            if(!visit[nn] && is_in(one, nn)){
                q.push(nn);
                visit[nn] = 1;
            }
        }
    }
    int sungugoo[11] = {0, };
    int sungugoo2[11] = {0, };
    for(int i=0; i<one.size(); i++){
        if(visit[one[i]]){
            sungugoo[one[i]] = 1;
            sungugoo2[one[i]] = 1;
        }
    }
    // 선거구2 체크
    int ts = two[0];
    q.push(ts);
    sungugoo[ts] = 2;
    while(!q.empty()){
        int cn = q.front();
        q.pop();
        for(int i=0; i<l[cn].size(); i++){
            int nn = l[cn][i];
            if(!sungugoo[nn] && is_in(two, nn)){
                q.push(nn);
                sungugoo[nn] = 2;
            }
        }
    }
    for(int i=0; i<two.size(); i++){
        if(sungugoo[two[i]] == 2){
            sungugoo2[two[i]] = 2;
        }
    }
    for(int i=1; i<=n; i++){
        if(sungugoo2[i] == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> map[i];
        total += map[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int tmp;
            cin >> tmp;
            l[i].push_back(tmp);
        }
    }
    for(int i=1; i<n; i++){
        vector<int> permu;
        for(int j=0; j<i; j++){
            permu.push_back(1);
        }
        for(int j=i; j<n; j++){
            permu.push_back(2);
        }
        do{
            vector<int> one, two; // 선거구1, 선거구2
            for(int j=0; j<n; j++){
                if(permu[j]==1){
                    one.push_back(j+1);
                }
                else{
                    two.push_back(j+1);
                }
            }
            if(check(one, two)){
                int tmp = abs(sum(one) - sum(two));
                if(tmp < minv){
                    minv = tmp;
                }
            }

        }while(next_permutation(permu.begin(), permu.end()));
    }
    if(minv == 987654321){
        cout << -1;
    }
    else{
        cout << minv;
    }
}