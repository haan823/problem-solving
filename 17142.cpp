#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, empty_space, minv = 987654321;
int map[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus_location;
vector<int> permu;

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
        cout << "-----------------------------------\n";
        for(int i=0; i<permu.size(); i++){
            if(permu[i]){
                cout << virus_location[i].first << " " << virus_location[i].second << "\n";
            }
        }
        queue<pair<int, pair<int, int>>> q;
        int k = 0, time = 987654321;
        int visit[50][50];
        for (int i = 0; i < permu.size(); i++)
        {
            if (permu[i])
            {
                q.push(make_pair(0, virus_location[i]));
                visit[virus_location[i].first][virus_location[i].second] = 1;
            }
        }
        bool flag = false;
        while (!q.empty())
        {
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << map[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            if (flag)
            {
                break;
            }
            int ct = q.front().first;
            int cx = q.front().second.first;
            int cy = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && (map[nx][ny] == 0 || map[nx][ny] == 2))
                {
                    q.push(make_pair(ct + 1, make_pair(nx, ny)));
                    visit[nx][ny] = 1;
                    k++;
                    if (k == empty_space)
                    {
                        flag = true;
                        time = ct + 1;
                        break;
                    }
                }
            }
        }
        if (time < minv)
        {
            minv = time;
        }
    } while (next_permutation(permu.begin(), permu.end()));

    if(minv == 987654321){
        cout << -1;
    }
    else{
        cout << minv;
    }
}