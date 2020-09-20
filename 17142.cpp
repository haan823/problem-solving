#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, empty_space, minv = 987654321;
int map[50][50];
int copy_map[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus_location;
vector<int> permu;

void solve(int fill)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            copy_map[i][j] = map[i][j];
        }
    }
    int time = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < permu.size(); i++)
    {
        if (permu[i])
        {
            q.push(virus_location[i]);
            copy_map[virus_location[i].first][virus_location[i].second] = 3;
        }
    }
    while(!q.empty()){
        int size = q.size();
        if(!fill){
            minv = min(minv, time);
            break;
        }
        time++;
        for(int i=0; i<size; i++){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                if(nx>=0 && nx<n && ny>=0 && ny<n && (copy_map[nx][ny]==0 || copy_map[nx][ny]==2)){
                    if(copy_map[nx][ny]==0){
                        fill--;
                    }
                    copy_map[nx][ny] = 3;
                    q.push({nx, ny});
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                virus_location.push_back({i, j});
            }
            else if (map[i][j] == 0)
            {
                empty_space++;
            }
        }
    }
    for (int i = 0; i < virus_location.size() - m; i++)
    {
        permu.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        permu.push_back(1);
    }

    do
    {
        solve(empty_space);

    } while (next_permutation(permu.begin(), permu.end()));

    if (minv == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << minv;
    }
}