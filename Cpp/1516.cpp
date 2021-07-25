#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> in[501];
queue<int> q;
int time[501];
int visit[501];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int input, res = 0;
        vector<int> v;
        for(int j=1; j<=n; j++){
            visit[j] = 0;
        }
        while(true){
            scanf("%d", &input);
            if(input == -1){
                break;
            }
            v.push_back(input);
        }
        time[i] = v[0];
        for(int j=1; j<v.size(); j++){
            in[i].push_back(v[j]);
        }
        q.push(i);
        res+=time[i];
        visit[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int t=0;
            for(int j=0; j<in[cur].size(); j++){
                if(!visit[in[cur][j]]){
                    q.push(in[cur][j]);
                    visit[in[cur][j]]=1;
                    if(time[in[cur][j]]>t){
                        t=time[in[cur][j]];
                    }
                }
            }
            if(t){
                res+=t;
            }
        }
        printf("%d\n", res);
    }
}