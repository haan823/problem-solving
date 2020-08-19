#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int parent[1000001];
vector<vector<int>> input;

void init(){
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
}

int find(int p){
    if(parent[p] == p){
        return p;
    }
    else{
        return parent[p] = find(parent[p]);
    }
}

void u(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        vector<int> ti(3, 0);
        scanf("%d %d %d", &ti[0], &ti[1], &ti[2]);
        input.push_back(ti);
    }
    
    init();

    for(int i=0; i<m; i++){
        int a = input[i][1];
        int b = input[i][2];
        if(input[i][0] == 0){
            u(a, b);
        }
        else{
            if(find(a)==find(b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}