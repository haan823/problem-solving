#include <iostream>
#include <vector>
using namespace std;

int map[2][45];
int count;
int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx>=0 && cx<2 && cy>=0 && cy<n && map[cx][cy]==0){
            map[cx][cy] = 1;
            bool flag = false;
            for(int j=0; j<2; j++){
                for(int k=0; k<n; k++){
                    if(map[j][k] == 0){
                        flag = true;
                        map[j][k] = 1;
                        dfs(j, k);
                        map[j][k] = 0;
                    }
                }
            }
            if(!flag){
                count++;
                return;
            }
            map[cx][cy] = 0;
        }
    }
}


int solution(int N) {
    int answer = 0;
    n = N;
    map[0][0] = 1;
    dfs(0, 0);
    answer = count;
    return answer;
}

int main(){
    int N;
    cin >> N;
    cout << solution(N);
}