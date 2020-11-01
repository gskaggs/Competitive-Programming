/*
ID: grant.s1
TASK: ariprog
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
#define MAX_M 251
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

int N, M, S[MAX_M * MAX_M + MAX_M * MAX_M], biggest;
set<pi> solns;

bool isValid(int a, int b) {
	F0R(i, N) {
		if(!S[a+i*b]) return false;
	}
	return true;
} 

void solve() {
	F0R(a, biggest+1) {
		if(!S[a]) continue;
		int b = 1;
		while(a + (N-1)*b <= biggest) {
			if (isValid(a, b)) solns.insert({b, a});
			b++;
		}
	}
}

int main()
{
	setIO("ariprog");
	cin >> N >> M;

	biggest = M*M + M*M;
	F0R(i, M+1) F0R(j, M+1) S[i * i + j * j] = 1;
	
	solve();
	if(!sz(solns)) cout << "NONE" << endl;
	trav(p, solns) cout << p.s << " " << p.f << endl;

	return 0;
}
