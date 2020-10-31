/*
ID: grant.s1
TASK: skidesign
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
#define MAX_N 1000
using namespace std;

int N, H[MAX_N], l, r;

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

int getCost(int i) {
	int cur = H[i];
	if (cur < l) return (l - cur) * (l - cur);
	if (cur > r) return (cur - r) * (cur - r);
	return 0;
}

int getCost() {
	int c = 0;
	F0R(i, N) {
		c += getCost(i);
	}
	return c;
}

int main()
{
	setIO("skidesign");
	cin >> N;
	F0R(i, N) cin >> H[i];

	l = 0; r = 17;
	int res = INF;
	while(r <= 100) {
		res = min(res, getCost());
		l++;
		r++;
	}

	cout << res << endl;
	return 0;
}
