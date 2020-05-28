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

int N, M;
pair<ll, ll> in[MAX_N];

bool valid(ll D) {
    ll cur = 0, count = 0;
    F0R(i, M) {
        ll a = in[i].f, b = in[i].s;
        while(b >= cur) {
            cur = max(cur, a);
            count++;
            cur += D;
            if (count >= N) return true;
        }
    }
    return false;
}

ll solve() {
    ll lo = 0, hi = (1e18)+5;
    
    while(lo + 1 < hi) {
        ll mid = (hi - lo) / 2 + lo;
        if (valid(mid)) lo = mid;
        else hi = mid;
    }

    return lo;
}

int main() {
    setIO("socdist");

    cin >> N >> M;
    F0R(i, M) {
        ll a, b;
        cin >> a >> b;
        in[i] = {a, b};
    }

    sort(in, in + M);

    cout << solve() << endl;

    return 0;
}
