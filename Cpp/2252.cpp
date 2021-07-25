#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y, cur, nxt;
queue<int> q;
int ind[32001];
vector<int> v[32001];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        ind[y]++;
    }
    for(int i=1; i<=n; i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        cur = q.front();
        q.pop();
        printf("%d ", cur);
        for(int i=0; i<v[cur].size(); i++){
            nxt = v[cur][i];
            ind[nxt]--;
            if(ind[nxt]==0){
                q.push(nxt);
            }
        }
    }
}