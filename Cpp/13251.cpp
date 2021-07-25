#include <iostream>
#include <vector>

using namespace std;

int m, k, sum=0;
vector<int> color;

int main(){
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        color.push_back(tmp);
        sum += tmp;
    }
    cin >> k;

    double res = 0;

    for(int i=0; i<m; i++){
        double tmp_res = 1;
        for(int j=0; j<k; j++){
            tmp_res *= ((double)(color[i]-j)/(double)(sum-j));
        }
        res += tmp_res;
    }
    printf("%.12f", res);
}