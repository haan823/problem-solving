#include <cstdio>
#include <vector>

using namespace std;

int n, m, a, b, d[100001][17], l[10001];
vector<int> v[100001];

void dfs(int p, int f){
    for(int i=0; i<v[p].size(); i++){
        int c=v[p][i];
        if(f==c){
            continue;
        }
        l[c] = l[p] + 1;
        d[c][0] = p;
        for(int j=1; j<17; j++){
            d[c][j] = d[d[c][j-1]][j-1];
            dfs(c, p);
        }
    }
}

int lca(int a, int b){
    if(l[a]>l[b]){
        swap(a, b);
    }
    for(int i=16; i>=0; i--){
        if((1<<i)<=l[b]-l[a]){
            b = d[b][i];
        }
    }
    if(a==b) return a;
    for(int i=16; i>=0; i--){
        if(d[a][i]!=d[b][i]){
            a=d[a][i];
            b=d[b][i];
        }
    }
    return d[a][0];
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}