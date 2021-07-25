#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, total, res = 987654321;
int map[21][21];
int region[21][21];

void check_s5(int x, int y, int d1, int d2){
    for(int i=1; i<=20; i++){
        for(int j=1; j<=20; j++){
            region[i][j] = 0;
        }
    }
    for(int i=1; i<=d1; i++){
        region[x+i][y-i] = 1;
        region[x+d2+i][y+d2-i] = 1;
    }
    for(int i=1; i<=d2; i++){
        region[x+i][y+i] = 1;
        region[x+d1+i][y-d1+i] = 1;
    }
    region[x][y] = 2;
    region[x+d1+d2][y-d1+d2] = 2;

}

void solve()
{
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int d1 = 1; d1 <= 18; d1++)
            {
                for (int d2 = 1; d2 <= 18; d2++)
                {
                    if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n)
                    {
                            check_s5(x, y, d1, d2);
                            // for(int i=1; i<=n; i++){
                            //     for(int j=1; j<=n; j++){
                            //         cout << region[i][j] << " ";
                            //     }
                            //     cout << "\n";
                            // }
                            int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5;
                            for (int r = 1; r <= n; r++)
                            {
                                for (int c = 1; c <= n; c++)
                                {
                                    if(region[r][c] == 2){
                                        continue;
                                    }
                                    else if(region[r][c] == 1){
                                        c++;
                                        while(region[r][c] == 0){
                                            c++;
                                        }
                                        continue;
                                    }
                                    if (r < x + d1 && c <= y)
                                    {
                                        s1 += map[r][c];
                                    }
                                    else if (r <= x + d2 && y < c)
                                    {
                                        s2 += map[r][c];
                                    }
                                    else if (x + d1 <= r && c < y - d1 + d2)
                                    {
                                        s3 += map[r][c];
                                    }
                                    else if (x + d2 < r && y - d1 + d2 <= c)
                                    {
                                        s4 += map[r][c];
                                    }
                                }
                            }
                            s5 = total - (s1 + s2 + s3 + s4);
                            vector<int> s;
                            s.push_back(s1);
                            s.push_back(s2);
                            s.push_back(s3);
                            s.push_back(s4);
                            s.push_back(s5);
                            sort(s.begin(), s.end());
                            int minv = s.front();
                            int maxv = s.back();
                            int diff = maxv - minv;
                            if (diff < res)
                            {
                                res = diff;
                            }
                        
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            total += map[i][j];
        }
    }
    solve();
    cout << res;
}