#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gidung_map[101][101];
int bo_map[101][101];
int tmp_gidung_map[101][101];
int tmp_bo_map[101][101];
int m;

void copy_map_to_tmp(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            tmp_gidung_map[i][j] = gidung_map[i][j];
            tmp_bo_map[i][j] = bo_map[i][j];
        }
    }
}

void copy_tmp_to_map(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            gidung_map[i][j] = tmp_gidung_map[i][j];
            bo_map[i][j] = tmp_bo_map[i][j];
        }
    }
}

bool gidung_create_possible(int x, int y){
    if(x == 0){
        return true;
    }
    else if(y == 0){
        if(gidung_map[x-1][y] == 1){
            return true;
        }
        else if(bo_map[x][y] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else if(x > 0){
        if(gidung_map[x-1][y] == 1){
            return true;
        }
        else if(bo_map[x][y-1] == 1 || bo_map[x][y] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool bo_create_possible(int x, int y){
    if(gidung_map[x-1][y] == 1 || gidung_map[x-1][y+1] == 1){
        return true;
    }
    else if(y>0 && y<m-1){
        if(bo_map[x][y-1] == 1 && bo_map[x][y+1] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool gidung_delete_possible(int x, int y){
    bool flag1 = false, flag2 = false, flag3 = false;
    copy_map_to_tmp();
    gidung_map[x][y] = 0;
    if(gidung_map[x+1][y] == 1){
        if(gidung_create_possible(x+1, y)){
            flag1 = true;
        }
        else{
            flag1 = false;
        }
    }
    else{
        flag1 = true;
    }
    if(bo_map[x+1][y] == 1){
        if(bo_create_possible(x+1, y)){
            flag2 = true;
        }
        else{
            flag2 = false;
        }
    }
    else{
        flag2 = true;
    }
    if(bo_map[x+1][y-1] == 1){
        if(bo_create_possible(x+1, y-1)){
            flag3 = true;
        }
        else{
            flag3 = false;
        }
    }
    else{
        flag3 = true;
    }

    copy_tmp_to_map();

    if(flag1 && flag2 && flag3){
        return true;
    }
    else{
        return false;
    }
}

bool bo_delete_possible(int x, int y){
    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    copy_map_to_tmp();
    bo_map[x][y] = 0;
    if(gidung_map[x][y] == 1){
        if(gidung_create_possible(x, y)){
            flag1 = true;
        }
        else{
            flag1 = false;
        }
    }
    else{
        flag1 = true;
    }
    if(gidung_map[x][y+1] == 1){
        if(gidung_create_possible(x, y+1)){
            flag2 = true;
        }
        else{
            flag2 = false;
        }
    }
    else{
        flag2 = true;
    }
    if(y>0){
        if(bo_map[x][y-1] == 1){
            if(bo_create_possible(x, y-1)){
                flag3 = true;
            }
            else{
                flag3 = false;
            }
        }
        else{
            flag3 = true;
        }
    }
    else{
        flag3 = true;
    }
    
    if(y<m-1){
        if(bo_map[x][y+1] == 1){
            if(bo_create_possible(x, y+1)){
                flag4 = true;
            }
            else{
                flag4 = false;
            }
        }
        else{
            flag4 = true;
        }
    }
    else{
        flag4 = true;
    }

    copy_tmp_to_map();

    if(flag1 && flag2 && flag3 && flag4){
        return true;
    }
    else{
        return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    m = n;
    for(int i=0; i<build_frame.size(); i++){
        int x, y, type, task;
        x = build_frame[i][1];
        y = build_frame[i][0];
        type = build_frame[i][2];
        task = build_frame[i][3];
        if(type == 0){
            if(task == 0){
                if(gidung_delete_possible(x, y)){
                    gidung_map[x][y] = 0;
                }
            }
            else{
                if(gidung_create_possible(x, y)){
                    gidung_map[x][y] = 1;
                }
            }
        }
        else{
            if(task == 0){
                if(bo_delete_possible(x, y)){
                    bo_map[x][y] = 0;
                }
            }
            else{
                if(bo_create_possible(x, y)){
                    bo_map[x][y] = 1;
                }
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(gidung_map[j][i] == 1){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if(bo_map[j][i] == 1){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }

    return answer;
}




int main()
{
    m = 5;
    vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    vector<vector<int>> answer;
    answer = solution(m, build_frame);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
        }
        cout << "\n";
    }

    // for (int i=0; i<n+1; i++){
    //     for(int j=0; j<n+1; j++){
    //         cout << gidung_map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for (int i=0; i<n+1; i++){
    //     for(int j=0; j<n+1; j++){
    //         cout << bo_map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}