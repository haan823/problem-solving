#include <iostream>
#include <vector>

using namespace std;

int input[2][2];

int find_gcd(int a, int b){
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cin >> input[i][j];
        }
    }
    int gcd = find_gcd(input[0][1], input[1][1]);
    int x = input[1][1]/gcd;
    int y = input[0][1]/gcd;
    int a = (input[0][0]*x)+(input[1][0]*y);
    int b = (input[0][1]*input[1][1]/gcd);
    int gcd2 = find_gcd(a, b);
    cout << a/gcd2 << " " << b/gcd2;
}