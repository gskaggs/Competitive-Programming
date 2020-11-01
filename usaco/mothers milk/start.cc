/*
ID: grant.s1
TASK: milk3
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
typedef pair<int, pi> ipi; // {a, {b, c}} saved problem state

int A, B, C;
set<ipi> seen;
set<int> solns;

vector<ipi> next(ipi cur) {
	int a = cur.f, b = cur.s.f, c = cur.s.s;
	if(!a) solns.insert(c);
	vector<ipi> res;

	int milk = min(A-a, b);
	res.pb({a+milk, {b-milk, c}});

	milk = min(a, B-b);
	res.pb({a-milk, {b+milk, c}});

	milk = min(A-a, c);
	res.pb({a+milk, {b, c-milk}});

	milk = min(a, C-c);
	res.pb({a-milk, {b, c+milk}});

	milk = min(B-b, c);
	res.pb({a, {b+milk, c-milk}});

	milk = min(b, C-c);
	res.pb({a, {b-milk, c+milk}});

	return res;
}

// BFS
void solve() {
	queue<ipi> q;
	q.push({0, {0, C}});
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		if(seen.count(cur)) continue;
		seen.insert(cur);
		trav(n, next(cur)) q.push(n);
	}
}

int main()
{
	setIO("milk3");
	cin >> A >> B >> C;
	solve();
	int count = sz(solns)-1;
	trav(c, solns) { 
		cout << c;
		if(count--) cout << " ";
	}
	cout << endl;
	return 0;
}
