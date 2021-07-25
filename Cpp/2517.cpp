#include <iostream>
#include <vector>

using namespace std;

class runner{
public:
    int index;
    int value;
};

int n;
vector<runner> v;
vector<runner> tmp;
vector<int> map;

void merge(int s, int m, int e){
    int p1 = s;
    int p2 = m + 1;
    int k = s;
    int cnt = 0;
    while(p1<=m && p2<=e){
        if(v[p1].value < v[p2].value){
            tmp[k++] = v[p1++];
            cnt++;
        }
        else{
            map[v[p2].index] += cnt;
            tmp[k++] = v[p2++];
        }
    }
    while(p1<=m){
        tmp[k++] = v[p1++];
    }
    while(p2<=e){
        map[v[p2].index] += cnt;
        tmp[k++] = v[p2++];
    }

    for(int i=s; i<=e; i++){
        v[i] = tmp[i];
    }
}

void mergeSort(int s, int e){
    if(s < e){
        int mid = (s + e) / 2;
        mergeSort(s, mid);
        mergeSort(mid+1, e);
        merge(s, mid, e);
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        runner r;
        r.index = i;
        cin >> r.value;
        v.push_back(r);
        map.push_back(0);
    }

    tmp = v;

    mergeSort(0, n-1);
    
    for(int i=0; i<n; i++){
        cout << i + 1 - map[i] << "\n";
    }    
}