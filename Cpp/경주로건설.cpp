#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[25][25];
int road_cost[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, mv = 987654321;
vector<vector<int>> map;

void bfs(int x, int y, int dir, int cost)
{
    queue<vector<int>> q;
    road_cost[x][y] = cost;
    q.push({x, y, dir, cost});
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int dir = q.front()[2];
        int cost = q.front()[3];
        q.pop();
        if(x == n-1 && y == n-1){
            mv = min(mv, cost);
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndir = (i%2);
            int ncost;
            if(dir == -1 || dir == ndir){
                ncost = cost + 100;
            }
            else{
                ncost = cost + 600;
            }
            if(nx>=0 && nx<n && ny>=0 && ny<n && map[nx][ny] == 0){
                if(ncost <= road_cost[nx][ny]){
                    road_cost[nx][ny] = ncost;
                    q.push({nx, ny, ndir, ncost});
                }
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    n = board.size();
    map = board;
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            road_cost[i][j] = 987654321;
        }
    }
    bfs(0, 0, -1, 0);
    answer = mv;
    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 0}};
    cout << solution(board) << "\n";
}