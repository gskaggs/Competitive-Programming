/*
ID: grant.s1
TASK: milk
LANG: C++                 
*/

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define umap unordered_map
#define uset unordered_set
#define INF 1000000007
#define MAX_N 100005
using namespace std;

void setIO(string name)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int N, M;

int main()
{
	setIO("milk");
	cin >> N >> M;

	// price, units
	vpi farmers(M);
	F0R(i, M) {
		int p, u;
		cin >> p >> u;
		farmers[i] = {p, u};
	}

	if (M) sort(all(farmers));
	int cost = 0;
	trav(farmer, farmers) {
		if (!N) break;
		int units = min(N, farmer.s);
		cost += farmer.f * units;
		N -= units;
	}

	cout << cost << endl;
	return 0;
}
