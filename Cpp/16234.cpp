#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<int>> visit;

void init_visit(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[i][j] = 0;
        }
    }
}
bool is_in_map(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }
    else{
        return false;
    }
}

bool check_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cx = i;
            int cy = j;
            int nx, ny;
            for(int k=0; k<4; k++){
                nx = cx + dx[k];
                ny = cy + dy[k];
                if(is_in_map(nx, ny)){
                    if(abs(map[cx][cy] - map[nx][ny]) >= l && abs(map[cx][cy] - map[nx][ny]) <= r){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

vector<pair<int, int>> bfs(int x, int y){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push(make_pair(x, y));
    visit[x][y] = 1;

    while(!q.empty()){
        pair<int, int> cur_loc = q.front();
        q.pop();
        v.push_back(cur_loc);
        int cx = cur_loc.first;
        int cy = cur_loc.second;
        int nx, ny;

        for(int i=0; i<4; i++){
            nx = cx + dx[i];
            ny = cy + dy[i];
            if(is_in_map(nx, ny) && !visit[nx][ny]){
                if(abs(map[cx][cy] - map[nx][ny]) >= l && abs(map[cx][cy] - map[nx][ny]) <= r){
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = 1;
                }
            }
        }
    }

    return v;
}

void update_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                vector<pair<int, int>> v;
                v = bfs(i, j);
                int sum = 0;
                for(int k=0; k<v.size(); k++){
                    sum += map[v[k].first][v[k].second];
                }
                sum /= v.size();
                for(int k=0; k<v.size(); k++){
                    map[v[k].first][v[k].second] = sum;
                }
            }
        }
    }
    return;
}

int main(){
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        vector<int> tmp_map;
        vector<int> tmp_visit;
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            tmp_map.push_back(tmp);
            tmp_visit.push_back(0);
        }
        map.push_back(tmp_map);
        visit.push_back(tmp_visit);
    }
    int cnt = 0;
    while(true){
        if(!check_map()){
            break;
        }
        init_visit();
        update_map();
        cnt++;
    }
    cout << cnt;
}