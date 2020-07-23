#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gidung_map[101][101];
int bo_map[101][101];

void make_gidung(int x, int y){
    if(x==0){
        gidung_map[x][y] = 0;
        return;

    }
    else{
        if(y==0){
            if(gidung_map[x-1][y] == 0 || bo_map[x][y] == 1){
                gidung_map[x][y] = 0;
                return;
            }
            else{
                return;
            }
        }
        else if(gidung_map[x-1][y] == 0 || bo_map[x][y-1] == 1 || bo_map[x][y] == 1){
            gidung_map[x][y] = 0;
            return;
        }
    }
}

void make_bo(int x, int y){
    if(gidung_map[x-1][y] == 0 || gidung_map[x-1][y+1] || (bo_map[x][y-1]) == 1 && bo_map[x][y+1] == 1){
        bo_map[x][y] = 1;
    }
    else{
        return;
    }
}

void remove_gidung(int x, int y){

}

void remove_bo(int x, int y){

}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    for(int i=0; i<build_frame.size(); i++){
        if(build_frame[i][2] == 0){
            make_gidung(build_frame[i][0], build_frame[i][1]);
        }
        else if(build_frame[i][2] == 1){
            make_bo(build_frame[i][0], build_frame[i][1]);
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout << gidung_map[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout << bo_map[i][j] << " ";
        }
        cout << "\n";
    }

    return answer;
}

int main()
{
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            gidung_map[i][j] = -1;
            bo_map[i][j] = -1;
        }
    }


    int n = 5;
    vector<vector<int>> build_frame = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
    vector<vector<int>> answer;
    answer = solution(n, build_frame);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
        }
        cout << "\n";
    }
}