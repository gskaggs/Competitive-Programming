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
#define MAX_N 100
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

int adj[MAX_N][MAX_N];
int N, R, C;

void addEdge(int r1, int c1, int r2, int c2, int d) {
	adj[R*r1 + c1][R*r2 + c2] = d;
	adj[R*r2 + c2][R*r1 + c1] = d;
}

int rec(int u, bitset b) {
	
}

int solve() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> R >> C;

	
	F0R(r, MAX_N) F0R(c, MAX_N) adj[r][c] = -1;

	getline(cin, s);

	F0R(r, R) {
		getline(cin, s);
		FOR(c, 1, C) { 
			int d = (int) (s.at(2*c) - '0') ;
			addEdge(r, c-1, r, c-2, d);
		}
		cout << endl;

		
		if(r != R-1) {
			getline(cin, s);
			F0R(c, C) {
				int d = (int) (s.at(2*c+1) - '0');
				addEdge(r, c, r+1, c, d);
			}
		}
	}

	getline(cin, s);
	//cout << s;
	return 0;
}


int main() {
	string s;
	getline(cin, s);
	N = stoi(s);
	F0R(i, N) {
		cout << solve() << endl;
	}


    return 0;
}
