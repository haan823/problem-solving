#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i=0; i<10; i++){
        cout << v[i] << " " << i << "\n";
        if(v[i] == 2){
            v.erase(v.begin() + i);
            i--;
        }
    }
    cout << v.size();
}