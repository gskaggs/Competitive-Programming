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

int N, L;
vpi neg, pos;

int solve(vpi& D) {
	int res = 0;
	while (!D.empty()) {
		res += 2*D.back().f;
		int cur = L;
		while (cur > 0 && !D.empty()) {
			int d = D.back().f, l = D.back().s;
			int delta = min(l, cur);
			cur -= delta;
			l -= delta;
			if(l == 0) D.pop_back();
			else {
				D[D.size()-1] = {d, l};
			}

		}

	}

	return res;
}


int main() {
	cin >> N >> L;

	F0R(i, N) {
		int d, l;
		cin >> d >> l;
		if (d < 0) neg.push_back({-d, l});
		else pos.pb({d, l});
	}

	sort(all(neg));
	sort(all(pos));
	
	cout << solve(neg) + solve(pos) << endl;

    return 0;
}
