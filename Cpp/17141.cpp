#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, empty_size, mint = 987654321;
int map[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> can_put_virus;
vector<int> permu;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                can_put_virus.push_back(make_pair(i, j));
            }
            if(map[i][j] != 1){
                empty_size++;
            }
        }
    }
    for(int i=0; i<m; i++){
        permu.push_back(1);
    }
    for(int i=m; i<can_put_virus.size(); i++){
        permu.push_back(0);
    }
    do{
        int cnt = 0;
        int visit[50][50] = {0, };
        queue<pair<int, pair<int, int>>> q;
        vector<pair<int, int>> virus;
        for(int i=0; i<permu.size(); i++){
            if(permu[i]){
                virus.push_back(can_put_virus[i]);
            }
        }
        for(int i=0; i<virus.size(); i++){
            q.push(make_pair(0, virus[i]));
            visit[virus[i].first][virus[i].second] = 1;
        }
        while(!q.empty()){
            int ct = q.front().first;
            int cx = q.front().second.first;
            int cy = q.front().second.second;
            q.pop();
            cnt++;
            if(empty_size == cnt){
                if(ct < mint){
                    mint = ct;
                }
                for(int i=0; i<virus.size(); i++){
                }
                break;
            }
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visit[nx][ny] && map[nx][ny] != 1){
                    q.push(make_pair(ct+1, make_pair(nx, ny)));
                    visit[nx][ny] = 1;
                }
            }
        }
    }while(prev_permutation(permu.begin(), permu.end()));
    if(mint == 987654321){
        cout << -1;
    }
    else{
        cout << mint;
    }
}