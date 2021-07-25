#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sx, sy, knum;
int s = 0;
int e = 0;
int answer = 987654321;
vector<vector<char>> maeul;
vector<vector<int>> godo;
vector<vector<int>> visit;
vector<int> range;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_in(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }
    else{
        return false;
    }
}

int dfs(int cx, int cy, int s, int e){
    int res = 0;

    if(godo[cx][cy] < range[s] || godo[cx][cy] > range[e]){
        return 0;
    }
    if(maeul[cx][cy] == 'K'){
        res = 1;
    }
    for(int i=0; i<8; i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(is_in(nx, ny) && !visit[nx][ny]){
            visit[nx][ny] = 1;
            res += dfs(nx, ny, s, e);
        }
    }
    return res;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        vector<char> tmp_maeul;
        vector<int> tmp_visit;
        for(int j=0; j<n; j++){
            char tmp;
            cin >> tmp;
            tmp_maeul.push_back(tmp);
            if(tmp == 'P'){
                sx = i;
                sy = j;
            }
            else if(tmp == 'K'){
                knum++;
            }
            tmp_visit.push_back(0);
        }
        maeul.push_back(tmp_maeul);
        visit.push_back(tmp_visit);
    }
    for(int i=0; i<n; i++){
        vector<int> tmp_godo;
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            tmp_godo.push_back(tmp);
            range.push_back(tmp);
        }
        godo.push_back(tmp_godo);
    }

    sort(range.begin(), range.end());

    int cnt = 1;
    for(int i=1; i<n*n; i++){
        if(range[i]!=range[i-1]){
            range[cnt++] = range[i];
        }
    }

    while(e < cnt){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visit[i][j] = 0;
            }
        }
        visit[sx][sy] = 1;
        if(dfs(sx, sy, s, e) == knum){
            if(answer > (range[e] - range[s])){
                answer = range[e] - range[s];
            }
            s++;
        }
        else{
            e++;
        }
    }

    cout << answer;

}