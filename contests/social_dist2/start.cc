
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
#define MAX_N 10005
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int N, nh, ns, h[MAX_N], s[MAX_N], v[MAX_N], R;

void dfs(int i) {
    if (v[i]) return;
    v[i] = true;
    F0R(j, ns) if (abs(s[j] - s[i]) < R) dfs(j);
}

int main() {
    setIO("socdist2");
    cin >> N;

    F0R(i, N) {
        int d, si;
        cin >> d >> si;
        if (si) s[ns++] = d;
        else h[nh++] = d;
    }

    R = INF;
    F0R(i, nh) F0R(j, ns) R = min(R, abs(h[i] - s[j]));

    int res = 0;
    F0R(i, ns) if (!v[i]) {
        res++;
        dfs(i);
    }

    cout << res << endl;


    return 0;
}
