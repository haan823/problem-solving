#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res;
vector<pair<int, pair<int, int>>> edges;
int parent[1001];

void init(){
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
}

int find(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);
    }
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x>y){
        swap(x, y);
    }
    parent[y] = x;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        vector<int> ti(3, 0);
        scanf("%d %d %d", &ti[0], &ti[1], &ti[2]);
        edges.push_back(make_pair(ti[2], make_pair(ti[0], ti[1])));
    }
    init();
    sort(edges.begin(), edges.end());
    for(int i=0; i<m; i++){
        if(find(edges[i].second.first)==find(edges[i].second.second)){
            continue;
        }
        else{
            merge(edges[i].second.first, edges[i].second.second);
            res+=edges[i].first;
        }
    }
    printf("%d", res);
}