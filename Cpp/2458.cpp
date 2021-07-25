#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, res;
queue<int> q1, q2;
vector<int> in[501];
vector<int> out[501];
int visit[501];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        out[x].push_back(y);
        in[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visit[j] = 0;
        }
        int cnt = 0;
        q1.push(i);
        q2.push(i);
        while(!q1.empty()){
            int cur = q1.front();
            q1.pop();
            for(int j=0; j<out[cur].size(); j++){
                int nxt = out[cur][j];
                if(!visit[nxt]){
                    q1.push(nxt);
                    visit[nxt] = 1;
                    cnt++;
                }
            }
        }
        while(!q2.empty()){
            int cur = q2.front();
            q2.pop();
            for(int j=0; j<in[cur].size(); j++){
                int nxt = in[cur][j];
                if(!visit[nxt]){
                    q2.push(nxt);
                    visit[nxt] = 1;
                    cnt++;
                }
            }
        }
        if(cnt==n-1){
            res++;
        }
    }
    printf("%d", res);
}