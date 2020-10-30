/*
ID: grant.s1
TASK: barn1
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

int M, S, C;
vi cows;

int solve() {
	if (M >= C) return C;
	int res = cows.back() - cows.front() + 1;

	vi diffs;
	F0R(i, C-1) {
		diffs.pb(cows[i+1] - cows[i] - 1);
	}

	sort(all(diffs));
	reverse(all(diffs));

	F0R(i, M-1) {
		res -= diffs[i];
	}
	return res;
}

int main()
{
	setIO("barn1");
	cin >> M >> S >> C;
	F0R(i, C) {
		int c;
		cin >> c;
		cows.pb(c);
	}
	sort(all(cows));
	cout << solve() << endl;
	return 0;
}
