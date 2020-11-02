/*
ID: grant.s1
TASK: numtri
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

int N, A[MAX_N][MAX_N], mem[MAX_N][MAX_N];

int solve(int i, int j) {
	if (i == N) return 0;
	if (mem[i][j] != -1) return mem[i][j]; 
	int res = A[i][j];
	res += max(solve(i+1, j), solve(i+1, j+1));
	return mem[i][j] = res;
}

int main()
{
	setIO("numtri");
	cin >> N;
	F0R(i, N) F0R(j, i+1) { cin >> A[i][j]; mem[i][j] = -1; }
	cout << solve(0, 0) << endl;
	return 0;
}
