/*
ID: grant.s1
TASK: task
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
#define MAX_N 100000007
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

int N;
bool p[MAX_N];

void sieve() {
	FOR(i, 2, N+1) p[i] = true;

	for(int i = 2; i*i <= N; i++) {
		if(p[i]) {
			for(int j = i*i; j <= N; j+=i) {
				p[i] = false;
			}
		}
	}
}

int main()
{
	setIO("");
	cin >> N;
	sieve();
	
	return 0;
}
