#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int w, h, rx, ry;
char map[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int find_distance(int sx, int sy, int gx, int gy)
{
    queue<pair<int, pair<int, int>>> q;
    int visit[20][20] = {0, };
    q.push(make_pair(0, make_pair(sx, sy)));
    visit[sx][sy] = 1;
    while (!q.empty())
    {
        int ct = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        if (cx == gx && cy == gy)
        {
            return ct;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visit[nx][ny] && map[nx][ny] != 'x')
            {
                q.push(make_pair(ct + 1, make_pair(nx, ny)));
                visit[nx][ny] = 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            return 0;
        }
        vector<pair<int, int>> dirty_loc;
        int min_num = 987654321;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'o')
                {
                    rx = i;
                    ry = j;
                }
                else if (map[i][j] == '*')
                {
                    dirty_loc.push_back(make_pair(i, j));
                }
            }
        }
        int road[11][11] = {-1, };
        vector<int> v;
        v.push_back(0);
        for(int i=0; i<dirty_loc.size(); i++){
            v.push_back(i+1);
            road[0][i+1] = find_distance(rx, ry, dirty_loc[i].first, dirty_loc[i].second);
        }
        for(int i=0; i<dirty_loc.size(); i++){
            for(int j=i; j<dirty_loc.size(); j++){
                if(i!=j){
                    road[i+1][j+1] = find_distance(dirty_loc[i].first, dirty_loc[i].second, dirty_loc[j].first, dirty_loc[j].second);
                    road[j+1][i+1] = road[i+1][j+1];
                }
            }
        }
        do{
            if(v[0]==0){
                int sum = 0;
                bool flag = true;
                for(int i=0; i<v.size()-1; i++){
                    if(road[v[i]][v[i+1]] < 1){
                        flag = false;
                        break;
                    }
                    sum+=road[v[i]][v[i+1]];
                }
                if(!flag){
                    break;
                }
                if(sum<min_num){
                    min_num=sum;
                }
            }
            else{
                continue;
            }
        }while(next_permutation(v.begin(), v.end()));

        if(min_num == 987654321){
            cout << "-1\n";
        }
        else{
            cout << min_num << "\n";
        }
    }
}