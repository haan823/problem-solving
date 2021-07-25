#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> input;
vector<char> aeiou = {'a', 'e', 'i', 'o', 'u'};
vector<int> visit(26, 0);

void dfs(vector<char> now, int index, vector<int> visit){
    if(now.size() == l){
        int cnt = 0;
        for(int i=0; i<now.size(); i++){
            bool flag = false;
            for(int j=0; j<5; j++){
                if(now[i] == aeiou[j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        if(cnt >= 1 && cnt <= l-2){
            for(int i=0; i<now.size(); i++){
                cout << now[i];
            }
            cout << "\n";
        }
        return;
    }
    else{
        for(int i=0; i<c; i++){
            if(!visit[input[i]-'a'] && i>index){
                vector<char> next = now;
                vector<int> next_visit = visit;
                next.push_back(input[i]);
                next_visit[input[i]-'a'] = 1;
                dfs(next, i, next_visit);
            }
        }
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    

    vector<char> start;
    start.clear();

    dfs(start, -1, visit);
}