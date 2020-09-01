#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[25][25];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, mv = 987654321;
vector<vector<int>> map;

void bfs(int x, int y, int dir, int cost)
{
    queue<vector<int>> q;
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
            int ndir;
            int ncost;
            if(dir == -1 || dir == (i%2)){
                ncost = cost + 100;
            }
            else{
                ncost = cost + 600;
            }
            if(nx>=0 && nx<n && ny>=0 && ny<n && map[nx][ny] == 0){

            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    n = board.size();
    map = board;
    answer = mv;
    return answer;
}

int main()
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}};
    cout << solution(board);
}