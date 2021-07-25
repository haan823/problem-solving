#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
    int time;
    int value;
    int reco;
    bool isin;
};

int s, k, min_index;
vector<int> input;
vector<node> now;
int map[101];

bool compare(node a, node b){
    if(a.reco > b.reco){
        return true;
    }
    else if(a.reco == b.reco){
        if(a.time > b.time){
            return true;
        }
        else if(a.time < b.time){
            return false;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool compare2(node a, node b){
    return a.value < b.value;
}

int main(){
    cin >> s >> k;
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    for(int i=0; i<input.size(); i++){
        if(map[input[i]]){
            for(int j=0; j<now.size(); j++){
                if(now[j].value == input[i]){
                    map[input[i]]++;
                    now[j].reco++;
                }
            }
        }
        else{
            node n;
            n.time = i;
            n.value = input[i];
            n.reco = 1;
            map[input[i]] = 1;
            if(now.size()<s){
                now.push_back(n);
            }
            else{
                sort(now.begin(), now.end(), compare);
                map[now.back().value] = 0;
                now.pop_back();
                now.push_back(n);
            }
        }
      
    }

    sort(now.begin(), now.end(), compare2);
    
    for(int i=0; i<now.size(); i++){
        cout << now[i].value << " ";
    }
}