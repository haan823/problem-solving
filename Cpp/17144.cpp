#include <iostream>
#include <vector>

using namespace std;

int r, c, t, res;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map(50, vector<int>(50, 0));
vector<pair<int, int>> cleaner_loc;

bool is_in_map(int x, int y){
    if(x>=0 && x<r && y>=0 && y<c){
        return true;
    }
    else{
        return false;
    }
}

void cleaner(){
    int x, y;
    x = cleaner_loc[0].first;
    y = cleaner_loc[0].second;
    for(int i=x-1; i>0; i--){
        int j=y;
        map[i][j] = map[i-1][j];
    }
    for(int j=0; j<c-1; j++){
        int i=0;
        map[i][j] = map[i][j+1];
    }
    for(int i=0; i<x; i++){
        int j=c-1;
        map[i][j] = map[i+1][j];
    }
    for(int j=c-1; j>1; j--){
        int i=x;
        map[i][j] = map[i][j-1];
    }
    map[x][y+1] = 0;

    x += 1;

    for(int i=x+1; i<r-1; i++){
        int j=y;
        map[i][j] = map[i+1][j];
    }
    for(int j=0; j<c-1; j++){
        int i=r-1;
        map[i][j] = map[i][j+1];
    }
    for(int i=r-1; i>x; i--){
        int j=c-1;
        map[i][j] = map[i-1][j];
    }
    for(int j=c-1; j>1; j--){
        int i=x;
        map[i][j] = map[i][j-1];
    }
    map[x][y+1] = 0;
}

void diffusion(){
    vector<pair<int, pair<int, int>>> to_add;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] > 0){
                int cx = i;
                int cy = j;
                int nx, ny;
                int cnt=0;
                for(int k=0; k<4; k++){
                    nx = cx + dx[k];
                    ny = cy + dy[k];
                    if(is_in_map(nx, ny) && map[nx][ny] != -1){
                        cnt++;
                        to_add.push_back(make_pair(map[cx][cy]/5, make_pair(nx, ny)));
                    }
                }
                map[cx][cy] -= (cnt*(map[cx][cy]/5));
            }
        }
    }
    for(int i=0; i<to_add.size(); i++){
        // cout << "to add: " << to_add[i].first << " " << to_add[i].second.first << " " << to_add[i].second.second << "\n";
        map[to_add[i].second.first][to_add[i].second.second]+=to_add[i].first;
    }
}

int main(){
    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                cleaner_loc.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<t; i++){
        diffusion();
        cleaner();
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] > 0){
                res+=map[i][j];
            }
        }
    }
    
    cout << res;
}