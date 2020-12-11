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

const int INF = 1000000007;

void solve()
{
	int i, j, k, u, v, w;

	int barrels = 0, queries;
	cin >> barrels >> queries;

	vector<map<LL, LL>> data(barrels);
	vector<LL> prod(barrels);
	for (i = 0; i < barrels; ++i)
		prod[i] = 1;

	while (queries--)
	{
		cin >> u >> v >> w;
		--v;
		if (u)
		{
			prod[v] *= w;
			data[v][w]++;
			if (prod[v] > 100000)
			{
				prod[v] = 1;
				data[v].clear();
			}
		}
		else
		{
			--w;
			map<LL, LL> primes;
			for (i = v; i <= w; ++i)
			{
				for (auto it = data[i].begin(); it != data[i].end(); ++it)
				{
					primes[it->first] += it->second;
				}
			}

			LL bigbrain = 1;
			for (auto it = primes.begin(); it != primes.end(); ++it)
			{
				bigbrain = (bigbrain * (it->first - 1)) % INF;
				for (i = 1; i < it->second; ++i)
					bigbrain = (bigbrain * it->first) % INF;
			}
			cout << bigbrain << endl;
		}
	}

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