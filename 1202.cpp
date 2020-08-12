#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<pair<int, int>> j;
vector<int> c;
priority_queue<int, vector<int>, less<int>> pq;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        j.push_back(make_pair(tmp1, tmp2));
    }
    for(int i=0; i<k; i++){
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(j.begin(), j.end());
    sort(c.begin(), c.end());
    long long sum = 0;
    int k=0;
    for(int i=0; i<c.size(); i++){
        int bag_size = c[i];
        for(; k<j.size(); k++){
            if(j[k].first <= c[i]){
                pq.push(j[k].second);
            }
            else{
                break;
            }
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}