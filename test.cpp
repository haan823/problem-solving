#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[2][45];
int count;
int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int i, int x, int y){
    if(i == n-1){
        for(int a=0; a<2; a++){
            for(int b=0; b<n; b++){
                cout << map[a][b] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        count++;
        return;
    }
    for(int j=0; j<4; j++){
        int cx = x + dx[j];
        int cy = y + dy[j];
        if(cx>=0 && cx<2 && cy>=0 && cy<n && map[x][y]==0){
            map[x][y] = 1;
            map[cx][cy] = 1;
            bool flag = false;
            int nx, ny;
            for(int a=0; a<2; a++){
                for(int b=0; b<n; b++){
                    if(map[a][b] == 0){
                        flag = true;
                        nx = a;
                        ny = b;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            dfs(i+1, nx, ny);
            map[x][y] = 0;
            map[cx][cy] = 1;
        }
    }
}

int solution(int N) {
    int answer = 0;
    n = N;
    dfs(0, 0, 0);
    answer = count;
    return answer;
}

int main(){
    int N;
    cin >> N;
    cout << solution(N);
}