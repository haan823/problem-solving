#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> tree;
vector<long long> nums;
int leafSize, depth;

void Init(vector<long long> inputs){
    nums = inputs;
    depth = 0;
    while(pow(2, depth) < nums.size()-1){
        depth++;
    }
    leafSize = pow(2, depth);
    for(int i=0; i<pow(2, depth+1); i++){
        tree.push_back(0);
    }
}

long long makeTree(int node, int left, int right){
    if(left == right){
        if(left <= nums.size()-1){
            return tree[node] = nums[left];
        }
        else{
            return tree[node] = 0;
        }
    }
    int mid = (left + right) / 2;
    tree[node] = makeTree(node*2, left, mid);
    tree[node] += makeTree(node*2+1, mid+1, right);
    return tree[node];
}

long long query(int node, int left, int right, int qleft, int qright){
    if(qright < left || qleft > right){
        return 0;
    }
    else if(qleft <= left && right <= qright){
        return tree[node];
    }
    else{
        int mid = (left + right) / 2;
        return query(node*2, left, mid, qleft, qright) + query(node*2+1, mid+1, right, qleft, qright);
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
    int n, m, k;
    vector<long long> input;
    vector<vector<long long>> map;
    cin >> n >> m >> k;
    input.push_back(0);
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    Init(input);
    makeTree(1, 1, leafSize);
    for(int i=0; i<m+k; i++){
        vector<long long> tmp_map;
        for(int j=0; j<3; j++){
            int tmp;
            cin >> tmp;
            tmp_map.push_back(tmp);
        }
        map.push_back(tmp_map);
    }
    for(int i=0; i<m+k; i++){
        if(map[i][0] == 1){
            int targetIndex = map[i][1];
            long long targetValue = map[i][2];
            long long diff = targetValue - nums[targetIndex];
            update(1, 1, leafSize, targetIndex, diff);
            nums[targetIndex] = targetValue;
        }
        else if(map[i][0] == 2){
            int qleft = map[i][1];
            int qright = map[i][2];
            cout << query(1, 1, leafSize, qleft, qright) << "\n";
        }
    }
}