#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> input;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        if(input[i]){
            pq.push(input[i]);
        }
        else{
            if(pq.size()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else{
                cout << 0 << "\n";
            }
        }
    }
    
}