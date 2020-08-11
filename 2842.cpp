#include <iostream>
#include <vector>

using namespace std;

int n, sx, sy;
vector<vector<char>> maeul;
vector<vector<int>> godo;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        vector<char> tmp_maeul;
        for(int j=0; j<n; j++){
            char tmp;
            cin >> tmp;
            tmp_maeul.push_back(tmp);
            if(tmp == 'P'){
                sx = i;
                sy = j;
            }
        }
        maeul.push_back(tmp_maeul);
    }
    for(int i=0; i<n; i++){
        vector<int> tmp_godo;
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            tmp_godo.push_back(tmp);
        }
        godo.push_back(tmp_godo);
    }


}