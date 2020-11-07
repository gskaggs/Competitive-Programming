#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
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

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;
typedef vector<vi>    vvi;

vvi to, from;
int N, M, S;
uset<int> seen;

void dfs(vvi& A, int u) {
	if (seen.count(u)) return;
	seen.insert(u);

	trav(v, A[u]) dfs(A, v);
}

int main() {
	cin >> N >> M >> S;
	S--;
	to.resize(N);
	from.resize(N);

	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		to[u].pb(v);
		from[v].pb(u);
	}

	int res = 0;
	dfs(to, S);
	res += N - sz(seen);

	seen.clear();

	dfs(from, S);
	res += N - sz(seen);

	cout << res << endl;

    return 0;
}
