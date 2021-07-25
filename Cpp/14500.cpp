#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[500][500];
int max = 0;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int max = 0;

    // ****
    for(int i=0; i<n; i++){
        for(int j=0; j<m-3; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
            if(sum>max){
                max = sum;
            }
        }
    }

    // *
    // *
    // * 
    // * 
    for(int i=0; i<n-3; i++){
        for(int j=0; j<m; j++){
            int sum;
            sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    // **
    // **
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    //  **
    // **
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j+1] + map[i][j+2] + map[i+1][j] + map[i+1][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    // **
    //  **
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }

    //  *
    // **
    // *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+2][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    // *
    // **
    //  *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    //  *
    // ***
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }

    // ***
    //  *
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    // *
    // **
    // *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    //  *
    // **
    //  *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    // **
    // *
    // *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+2][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    // *
    // *
    // **
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i+2][j+1] + map[i+1][j] + map[i+2][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    // **
    //  *
    //  *
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    //  *
    //  *
    // **
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int sum;
            sum = map[i+2][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
            if(sum>max){
                max = sum;
            }
        }
    }

    // ***
    //   *
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }

    // ***
    // *
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
            if(sum>max){
                max = sum;
            }
        }
    }

    // *
    // ***
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }

    //   *
    // ***
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int sum;
            sum = map[i][j+2] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
            if(sum>max){
                max = sum;
            }
        }
    }

    cout << max;
}