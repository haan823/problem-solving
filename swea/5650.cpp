/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x, y, dir, score;
int map[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> whall[11];

void finball(int sx, int sy, int sdir)
{
    int x = sx, y = sy, dir = sdir;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];
        if (x >= 0 && x < N && y >= 0 && y < N)
        {
            if (map[x][y] == 1)
            {
                score++;
                if (dir == 0 || dir == 1)
                {
                    dir = (dir + 2) % 4;
                }
                else if (dir == 2)
                {
                    dir = 1;
                }
                else if (dir == 3)
                {
                    dir = 0;
                }
            }
            else if (map[x][y] == 2)
            {
                score++;
                if (dir == 1 || dir == 2)
                {
                    dir = (dir + 2) % 4;
                }
                else if (dir == 0)
                {
                    dir = 1;
                }
                else if (dir == 3)
                {
                    dir = 2;
                }
            }
            else if (map[x][y] == 3)
            {
                score++;
                if (dir == 2 || dir == 3)
                {
                    dir = (dir + 2) % 4;
                }
                else if (dir == 0)
                {
                    dir = 3;
                }
                else if (dir == 1)
                {
                    dir = 2;
                }
            }
            else if (map[x][y] == 4)
            {
                score++;
                if (dir == 0 || dir == 3)
                {
                    dir = (dir + 2) % 4;
                }
                else if (dir == 1)
                {
                    dir = 0;
                }
                else if (dir == 2)
                {
                    dir = 3;
                }
            }
            else if (map[x][y] == 5)
            {
                score++;
                dir = (dir + 2) % 4;
            }
            else if (map[x][y] >= 6 && map[x][y] <= 10)
            {
                for (int i = 0; i < 2; i++)
                {
                    if (whall[map[x][y]][i].first != x || whall[map[x][y]][i].second != y)
                    {
                        int nx = whall[map[x][y]][i].first;
                        int ny = whall[map[x][y]][i].second;
                        x = nx;
                        y = ny;
                        break;
                    }
                }
            }
            else if (map[x][y] == -1)
            {
                return;
            }
        }
        else
        {
            score++;
            dir = (dir + 2) % 4;
        }
        if (x == sx && y == sy)
        {
            return;
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    int T;
    vector<pair<int, int>> start_loc;

    freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        int maxv = 0;
        start_loc.clear();
        for (int i = 0; i < 11; i++)
        {
            whall[i].clear();
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 0)
                {
                    start_loc.push_back(make_pair(i, j));
                }
                else if (map[i][j] >= 6 && map[i][j] <= 10)
                {
                    whall[map[i][j]].push_back(make_pair(i, j));
                }
            }
        }
        for (int i = 0; i < start_loc.size(); i++)
        {
            int sx = start_loc[i].first, sy = start_loc[i].second;
            for (int dir = 0; dir < 4; dir++)
            {
                score = 0;
                finball(sx, sy, dir);
                maxv = max(score, maxv);
            }
        }
        cout << "#" << test_case << " " << maxv << "\n";
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}