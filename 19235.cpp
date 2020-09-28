#include <iostream>
#include <vector>

using namespace std;

int n, t, x, y, score, num, id = 1;
int green[6][4];
int blue[6][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void print_green()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << green[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void put_block_green(int t, int x, int y)
{
    if (t == 1)
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 5 || green[nx + 1][ny])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        green[nx][ny] = bid;
    }
    else if (t == 2)
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 5 || green[nx + 1][ny] || green[nx + 1][ny + 1])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        green[nx][ny] = bid;
        green[nx][ny + 1] = bid;
    }
    else
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 4 || green[nx + 1][ny] || green[nx + 2][ny])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        green[nx][ny] = bid;
        green[nx + 1][ny] = bid;
    }
}

void check_green()
{
    for (int i = 2; i < 6; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (green[i][j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < 4; j++)
            {
                green[i][j] = 0;
            }
            score++;
        }
    }
    vector<vector<int>> v; // {t, x, y}
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (green[i][j])
            {
                bool flag2 = false;
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < 6 && nj >= 0 && nj < 4)
                    {
                        if (green[i][j] == green[ni][nj])
                        {
                            flag2 = true;
                            if (k == 0)
                            {
                                v.push_back({3, ni, nj});
                                green[i][j] = 0;
                                green[ni][nj] = 0;
                                break;
                            }
                            else if (k == 1)
                            {
                                v.push_back({2, i, j});
                                green[i][j] = 0;
                                green[ni][nj] = 0;
                                break;
                            }
                            else if (k == 2)
                            {
                                v.push_back({3, i, j});
                                green[i][j] = 0;
                                green[ni][nj] = 0;
                                break;
                            }
                            else if (k == 3)
                            {
                                v.push_back({2, ni, nj});
                                green[i][j] = 0;
                                green[ni][nj] = 0;
                                break;
                            }
                        }
                    }
                }
                if (!flag2)
                {
                    v.push_back({1, i, j});
                    green[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i][0] << v[i][1] << v[i][2] << "\n";
        put_block_green(v[i][0], v[i][1], v[i][2]);
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (green[i][j])
            {
                cnt++;
                break;
            }
        }
    }
    for (int i = 5; i >= 2; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            green[i][j] = green[i - cnt][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            green[i][j] = 0;
        }
    }
    for (int i = 2; i < 6; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (green[i][j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            check_green();
        }
    }
}

void print_blue()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << blue[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void put_block_blue(int t, int x, int y)
{
    if (t == 1)
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 5 || blue[nx + 1][ny])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        blue[nx][ny] = bid;
    }
    else if (t == 2)
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 5 || blue[nx + 1][ny] || blue[nx + 1][ny + 1])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        blue[nx][ny] = bid;
        blue[nx][ny + 1] = bid;
    }
    else
    {
        int nx = x, ny = y;
        while (true)
        {
            if (nx == 4 || blue[nx + 1][ny] || blue[nx + 2][ny])
            {
                break;
            }
            nx++;
        }
        int bid = id++;
        blue[nx][ny] = bid;
        blue[nx + 1][ny] = bid;
    }
}

void check_blue()
{
    for (int i = 2; i < 6; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (blue[i][j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < 4; j++)
            {
                blue[i][j] = 0;
            }
            score++;
        }
    }
    vector<vector<int>> v; // {t, x, y}
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (blue[i][j])
            {
                bool flag2 = false;
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < 6 && nj >= 0 && nj < 4)
                    {
                        if (blue[i][j] == blue[ni][nj])
                        {
                            flag2 = true;
                            if (k == 0)
                            {
                                v.push_back({3, ni, nj});
                                blue[i][j] = 0;
                                blue[ni][nj] = 0;
                                break;
                            }
                            else if (k == 1)
                            {
                                v.push_back({2, i, j});
                                blue[i][j] = 0;
                                blue[ni][nj] = 0;
                                break;
                            }
                            else if (k == 2)
                            {
                                v.push_back({3, i, j});
                                blue[i][j] = 0;
                                blue[ni][nj] = 0;
                                break;
                            }
                            else if (k == 3)
                            {
                                v.push_back({2, ni, nj});
                                blue[i][j] = 0;
                                blue[ni][nj] = 0;
                                break;
                            }
                        }
                    }
                }
                if (!flag2)
                {
                    v.push_back({1, i, j});
                    blue[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i][0] << v[i][1] << v[i][2] << "\n";
        put_block_blue(v[i][0], v[i][1], v[i][2]);
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (blue[i][j])
            {
                cnt++;
                break;
            }
        }
    }
    for (int i = 5; i >= 2; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            blue[i][j] = blue[i - cnt][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            blue[i][j] = 0;
        }
    }
    for (int i = 2; i < 6; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (blue[i][j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            check_blue();
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> x >> y;
        put_block_green(t, 0, y);
        check_green();

        if(t==1){
            put_block_blue(1, 0, 3-x);
        }
        else if(t==2){
            put_block_blue(3, 0, 3-x);
        }
        else{
            put_block_blue(2, 0, 2-x);
        }
        check_blue();
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if(green[i][j]){
                num++;
            }
            if(blue[i][j]){
                num++;
            }
        }
    }
    cout << score << "\n" << num;
}