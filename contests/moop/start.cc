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

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int N;
pi c[MAX_N];
set<int> s;

int main() {
    setIO("moop");

    cin >> N;
    F0R(i, N) {
        int x, y;
        cin >> x >> y;
        c[i] = {x, y};
    }

    sort(c, c+N);
    int miny = INF;

    F0R(i, N) {
        int y = c[i].s;
        auto it = s.begin();
        miny = min(y, miny);

        while(it != s.end() && *it <= y) 
            s.erase(it++);

        s.insert(miny);
    }

    cout << sz(s) << endl;

    return 0;
}
