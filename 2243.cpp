#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree;
vector<int> nums(1000001, 0);
int leafSize, depth;

void Init(){
    depth = 0;
    while(pow(2, depth) < nums.size()-1){
        depth++;
    }
    leafSize = pow(2, depth);
    for(int i=0; i<pow(2, depth+1); i++){
        tree.push_back(0);
    }
}

int query(int node, int left, int right, int target){
    if(left == right){
        return left;
    }
    else{
        int mid = (left + right) / 2;
        if(tree[node*2]>=target){
            return query(node*2, left, mid, target);
        }
        else{
            target -= tree[node*2];
            if(tree[node*2+1]>=target){
                return query(node*2+1, mid+1, right, target);
            }
            else{
                return 0;
            }
        }
    }
}

void update(int node, int left, int right, int index, long long diff){
    if(index < left || right < index){
        return;
    }
    else{
        tree[node] += diff;
        if(left!=right){
            int mid = (left + right) / 2;
            update(node*2, left, mid, index, diff);
            update(node*2+1, mid+1, right, index, diff);
        }
    }
}

int main(){
    int n;
    vector<int> input;
    vector<vector<int>> map(100000, vector<int>(3, 0));
    cin >> n ;
    Init();

    for(int i=0; i<n; i++){
        cin >> map[i][0];
        if(map[i][0] == 1){
            for(int j=1; j<2; j++){
                cin >> map[i][j];
            }
        }
        else{
            for(int j=1; j<3; j++){
                cin >> map[i][j];
            }
        }
    }
    for(int i=0; i<n; i++){
        if(map[i][0] == 1){
            int candy = query(1, 1, leafSize, map[i][1]);
            update(1, 1, leafSize, candy, -1);
            nums[candy]-=1;
            cout << candy << "\n";
        }
        else if(map[i][0] == 2){
            update(1, 1, leafSize, map[i][1], map[i][2]);
            nums[map[i][1]]+=map[i][2];
        }
    }
}