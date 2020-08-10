#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k, max_num;
vector<string> board;
vector<int> visit(26, 0);

void dfs(char x, int depth, vector<int> visit){
    if(depth == k){
        int cnt = 0;
        for(int i=0; i<board.size(); i++){
            bool flag = false;
            for(int j=0; j<board[i].size(); j++){
                if(visit[board[i][j]-'a']){
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        if(max_num < cnt){
            max_num = cnt;
        }
        return;
    }
    else{
        for(int i=(x-'a'); i<26; i++){
            if(!visit[i]){
                vector<int> next_visit = visit;
                next_visit[i] = 1;
                dfs('a'+i, depth+1, next_visit);
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
    string s = "antic";
    for(int i=0; i<s.size(); i++){
        visit[s[i]-'a'] = 1;
    }
    dfs('a', 5, visit);
    cout << max_num;
}