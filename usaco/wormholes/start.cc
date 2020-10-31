/*
ID: grant.s1
TASK: wormhole
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
#define MAX_N 12
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

int N, leave[MAX_N], enter[MAX_N];

int getEnter(int n) {
	F0R(i, N) if(enter[i] == n) return i & 1 ? enter[i-1] : enter[i+1];
	return -INF;
}

// returns true if safe
bool dfs(int i, vi& seen) {
	if (seen[i] == 2) return true;
	if (seen[i] == 1) return false;
	seen[i] = 1;
	bool res = true;
	if (leave[i] != -1) res = dfs(getEnter(leave[i]), seen);
	seen[i] = 2;
	return res;
}

// returns false if safe
bool isInfLoop() {
	vi seen(N);
	F0R(i, N) {
		if(seen[i]) continue;
		if(!dfs(i,seen)) return true;
	}
	return false;
}

int solve(int depth) {
	if (depth >= N) return isInfLoop() ? 1 : 0;
	int res = 0;
	FOR(i, depth-1, N) {
		swap(enter[depth-1], enter[i]);
		res += solve(depth+2);
		swap(enter[depth-1], enter[i]);
	}
	return res;
}

int main()
{
	setIO("wormhole");
	cin >> N;
	vpi w(N);
	F0R(i, N) cin >> w[i].f >> w[i].s;

	sort(all(w));
	F0R(i, N) enter[i] = i;
	
	F0R(i, N) {
		leave[i] = -1;
		FOR(j, i+1, N) {
			if (w[i].s == w[j].s) {
				leave[i] = j;
				break;
			}
		}
	}
	cout << solve(2) << endl;
	return 0;
}
