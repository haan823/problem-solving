#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[10][10];
int ax, ay, bx, by;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visit[10][10];

typedef struct _BC
{
	int x;
	int y;
	int c;
	int p;
} BC;

BC BCs[9];

void updateBCmap(BC BCs[9], int A)
{
	for (int i = 1; i <= A; i++)
	{
		int x = BCs[i].x;
		int y = BCs[i].y;
		int c = BCs[i].c;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				visit[j][k] = 0;
			}
		}
		queue<vector<int>> q;
		q.push({x, y, c});
		visit[x][y] = 1;
		while (!q.empty())
		{
			int cx = q.front()[0];
			int cy = q.front()[1];
			int cc = q.front()[2];
			q.pop();
			map[cx][cy].push_back(i);
			for (int j = 0; j < 4; j++)
			{
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && !visit[nx][ny] && cc > 0)
				{
					q.push({nx, ny, cc - 1});
					visit[nx][ny] = 1;
				}
			}
		}
	}
}

int find_maximum(int ax, int ay, int bx, int by)
{
	vector<int> a = map[ax][ay];
	vector<int> b = map[bx][by];
	int maxv = 0;
	if (a.size() == 0 && b.size() == 0)
	{
		maxv = 0;
	}
	else if (a.size() == 0)
	{
		for (int i = 0; i < b.size(); i++)
		{
			maxv = max(maxv, BCs[b[i]].p);
		}
	}
	else if (b.size() == 0)
	{
		for (int i = 0; i < a.size(); i++)
		{
			maxv = max(maxv, BCs[a[i]].p);
		}
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] == b[j])
				{
					maxv = max(maxv, (BCs[a[i]].p + BCs[b[j]].p) / 2);
				}
				else
				{
					maxv = max(maxv, BCs[a[i]].p + BCs[b[j]].p);
				}
			}
		}
	}
	return maxv;
}

int main(int argc, char **argv)
{
	int test_case;
	int T;
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map[i][j].clear();
			}
		}
		int M, A, sum = 0;
		int routeA[100];
		int routeB[100];
		cin >> M >> A;
		ax = 0, ay = 0, bx = 9, by = 9;
		for (int i = 0; i < M; i++)
		{
			int dir;
			cin >> dir;
			routeA[i] = dir - 1;
		}
		for (int i = 0; i < M; i++)
		{
			int dir;
			cin >> dir;
			routeB[i] = dir - 1;
		}
		for (int i = 1; i <= A; i++)
		{
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			BCs[i].x = y - 1;
			BCs[i].y = x - 1;
			BCs[i].c = c;
			BCs[i].p = p;
		}
		updateBCmap(BCs, A);
		sum += find_maximum(ax, ay, bx, by);
		for (int i = 0; i < M; i++)
		{
			ax = ax + dx[routeA[i]];
			ay = ay + dy[routeA[i]];
			bx = bx + dx[routeB[i]];
			by = by + dy[routeB[i]];
			sum += find_maximum(ax, ay, bx, by);
		}
		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}