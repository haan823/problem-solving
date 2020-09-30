    #include <iostream>
    #include <vector>

    using namespace std;

    typedef struct _shark
    {
        bool alive = true;
        int x;
        int y;
        int dir;
    } shark;

    int n, m, k;
    shark sharks[401];
    int priority[401][4][4];
    int smell[20][20];
    int time[20][20];
    int map[20][20];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void print_shark()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (sharks[i].alive)
            {
                map[sharks[i].x][sharks[i].y] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }
    void print_smell()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << smell[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }
    void print_time()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << time[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
    }
    void update()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (time[i][j] != 0)
                {
                    time[i][j]--;
                    if (time[i][j] == 0)
                    {
                        smell[i][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (sharks[i].alive)
            {
                smell[sharks[i].x][sharks[i].y] = i;
                time[sharks[i].x][sharks[i].y] = k;
            }
        }
    }

    void move_shark()
    {
        for (int i = 1; i <= m; i++)
        {
            if (sharks[i].alive == false)
            {
                continue;
            }
            int x = sharks[i].x;
            int y = sharks[i].y;
            int dir = sharks[i].dir;
            bool flag = false; // 빈칸 있었는지 체크
            for (int j = 0; j < 4; j++)
            {
                int ndir = priority[i][dir][j];
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && smell[nx][ny] == 0)
                {
                    sharks[i].x = nx;
                    sharks[i].y = ny;
                    sharks[i].dir = ndir;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                for (int j = 0; j < 4; j++)
                {
                    int ndir = priority[i][dir][j];
                    int nx = x + dx[ndir];
                    int ny = y + dy[ndir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && smell[nx][ny] == i)
                    {
                        sharks[i].x = nx;
                        sharks[i].y = ny;
                        sharks[i].dir = ndir;
                        break;
                    }
                }
            }
        }
        // 상어 이동 끝내고 겹치는 부분 체크
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (sharks[i].alive)
            {
                if (map[sharks[i].x][sharks[i].y] == 0)
                {
                    map[sharks[i].x][sharks[i].y] = i;
                }
                else if (map[sharks[i].x][sharks[i].y] > i)
                {
                    sharks[map[sharks[i].x][sharks[i].y]].alive = false;
                    map[sharks[i].x][sharks[i].y] = i;
                }
                else if (map[sharks[i].x][sharks[i].y] < i)
                {
                    sharks[i].alive = false;
                }
            }
        }
    }

    bool check_shark()
    {
        bool flag1 = false, flag2 = false;
        if (sharks[1].alive)
        {
            flag1 = true;
        }
        for (int i = 2; i <= m; i++)
        {
            if (!sharks[i].alive)
            {
                flag2 = true;
            }
            else
            {
                flag2 = false;
                break;
            }
        }
        if (flag1 && flag2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int main()
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int shark;
                cin >> shark;
                if (shark != 0)
                {
                    sharks[shark].alive = true;
                    sharks[shark].x = i;
                    sharks[shark].y = j;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int dir;
            cin >> dir;
            sharks[i].dir = dir - 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int dir;
                    cin >> dir;
                    priority[i][j][k] = dir - 1;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            smell[sharks[i].x][sharks[i].y] = i;
            time[sharks[i].x][sharks[i].y] = k;
        }
        int t = 0;
        while (t <= 1000)
        {
            if (check_shark())
            {
                cout << t;
                return 0;
            }
            move_shark();
            update();
            t++;
        }
        cout << -1;
        return 0;
    }