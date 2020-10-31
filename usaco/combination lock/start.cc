/*
ID: grant.s1
TASK: combo
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

int N, j[3], m[3];
uset<int> solns;

void addSolns(int* A) {
	FOR(i, -2, 3) FOR(j, -2, 3) FOR(k, -2, 3) {
		int c1 = (A[0] + i + N) % N;
		int c2 = (A[1] + j + N) % N;
		int c3 = (A[2] + k + N) % N;
		solns.insert( N * N * c1 + N * c2 + c3 );
	}
}

int solve() {
	addSolns(j);
	addSolns(m);
	return sz(solns);
}

int main()
{
	setIO("combo");
	cin >> N;
	F0R(i, 3) { cin >> j[i]; j[i]--; }
	F0R(i, 3) { cin >> m[i]; m[i]--; }
	cout << solve() << endl;
	return 0;
}
