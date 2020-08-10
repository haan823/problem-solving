#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;
vector<vector<char>> map;
vector<vector<int>> dp(50, vector<int>(50, 0));
pair<int, int> start;
vector<pair<int, int>> water;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visit[50][50];
int water_visit[50][50];
int min_num = 987654321;

class node{
public:
    int x;
    int y;
    char type;
};

queue<node> q;

bool is_in_map(int x, int y){
    if(x>=0 && x<r && y>=0 && y<c){
        return true;
    }
    else{
        return false;
    }
}

void bfs(){
    while(!q.empty()){
        node now = q.front();
        q.pop();
        int cx = now.x;
        int cy = now.y;
        int ct = now.type;

        if(map[cx][cy] == 'D'){
            min_num = dp[cx][cy];
            return;
        }

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            node n;
            n.x = nx;
            n.y = ny;
            n.type = ct;
            if(ct == 'S'){
                if(is_in_map(nx, ny) && !visit[nx][ny] && map[nx][ny] != 'X' && map[nx][ny] != '*'){
                    q.push(n);
                    visit[nx][ny] = 1;
                    dp[nx][ny] = dp[cx][cy] + 1;
                }
            }
            else if(ct == '*'){
                if(is_in_map(nx, ny) && !water_visit[nx][ny] && map[nx][ny] != 'X' && map[nx][ny] != 'D'){
                    q.push(n);
                    water_visit[nx][ny] = 1;
                    map[nx][ny] = '*';
                }
                
            }
        }
    }
    
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        vector<char> tmp_map;
        for(int j=0; j<c; j++){
            char tmp;
            cin >> tmp;
            tmp_map.push_back(tmp);
            if(tmp == 'S'){
                start.first = i;
                start.second = j;
            }
            else if(tmp == '*'){
                water.push_back(make_pair(i, j));
            }
        }
        map.push_back(tmp_map);
    }
    for(int i=0; i<water.size(); i++){
        node n;
        n.x = water[i].first;
        n.y = water[i].second;
        n.type = '*';
        q.push(n);
        water_visit[water[i].first][water[i].second] = 1;
    }

    node n;
    n.x = start.first;
    n.y = start.second;
    n.type = 'S';
    q.push(n);

    dp[start.first][start.second] = 0;
    visit[start.first][start.second] = 1;
  
    bfs();

    if(min_num!=987654321){
        cout << min_num;
    }
    else{
        cout << "KAKTUS";
    }
}