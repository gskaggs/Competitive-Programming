#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <iomanip>
#include <fstream>
#if __cplusplus > 201103L 
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

struct point
{
	int x, y, z;

	point(int _x = 0, int _y = 0, int _z = 0) { x = _x, y = _y, z = _z; }

	int& operator[](const int index) 
	{
		if (index == 0)
			return x;
		if (index == 1)
			return y;
		else
			return z;
	}
};

const int MAXN = 15 + 2;
const int INF = 1000000007;
int dist[MAXN][MAXN][MAXN];

int caps[3], starts[3], goal[3];

point pour(point start, int from, int to)
{
	point end = start;
	if (start[from] + start[to] > caps[to])
	{
		end[to] = caps[to];
		end[from] = -caps[to] + start[from] + start[to];
	}
	else
	{
		end[to] = start[from] + start[to];
		end[from] = 0;
	}

	return end;
}

void solve()
{
	int i, j, k, u, v, w;

	cin >> caps[0] >> caps[1] >> caps[2] >> starts[0] >> starts[1] >> starts[2] >> goal[0] >> goal[1] >> goal[2];

	for (i = 0; i < MAXN; ++i)
		for (j = 0; j < MAXN; ++j)
			for (k = 0; k < MAXN; ++k)
				dist[i][j][k] = INF;

	dist[starts[0]][starts[1]][starts[2]] = 0;
	queue<point> aditya;
	aditya.push(point(starts[0], starts[1], starts[2]));

	while (!aditya.empty())
	{
		auto front = aditya.front();
		aditya.pop();

		for (i = 0; i < 3; ++i)
			for (j = 0; j < 3; ++j)
				if (i != j)
				{
					auto end = pour(front, i, j);
					if (dist[end[0]][end[1]][end[2]] != INF)
						continue;

					aditya.push(end);
					dist[end[0]][end[1]][end[2]] = dist[front[0]][front[1]][front[2]] + 1;
				}
	}

	if (dist[goal[0]][goal[1]][goal[2]] == INF)
		cout << -1 << endl;
	else
		cout << dist[goal[0]][goal[1]][goal[2]] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("", "r", stdin);
	//freopen("", "w", stdout);

	solve();

	return 0;
}