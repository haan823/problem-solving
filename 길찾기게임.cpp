#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre, post;

typedef struct _node
{
    int x;
    int y;
    int num;
    _node * left;
    _node * right;
} node;

bool compare(node &a, node &b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    else{
        return a.y>b.y;
    }
}

void insertnode(node * parent, node * child){
    if(parent->x > child->x){
        if(parent->left == NULL){
            parent->left = child;
        }
        else{
            insertnode(parent->left, child);
        }
    }
    else{
        if(parent->right == NULL){
            parent->right = child;
        }
        else{
            insertnode(parent->right, child);
        }
    }
}

void prefix(node * root){
    if(root){
        pre.push_back(root->num);
        prefix(root->left);
        prefix(root->right);
    }
}

void postfix(node * root){
    if(root){
        postfix(root->left);
        postfix(root->right);
        post.push_back(root->num);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    vector<node> nodes;
    for(int i=0; i<nodeinfo.size(); i++){
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i+1});
    }
    sort(nodes.begin(), nodes.end(), compare);
    node * root = &nodes[0];
    for(int i=1; i<nodes.size(); i++){
        insertnode(root, &nodes[i]);
    }
    prefix(root);
    postfix(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    vector<vector<int>> answer = solution(nodeinfo);
    for (int i = 0; i < answer[0].size(); i++)
    {
        cout << answer[0][i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < answer[1].size(); i++)
    {
        cout << answer[1][i] << " ";
    }
}