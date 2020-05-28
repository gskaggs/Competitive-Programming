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

int T, N, ans[MAX_N];
pair<int, pi> A[MAX_N];

bool solve() {
    int k= 0, p = 0;
    F0R(i, 2*N) {
        auto cur = A[i].s;
        int t = cur.f, id = cur.s;
        if (!t) { k--; p = ans[id]; }
        else { ans[id] = p; k++; p = (p+1)%2;}
        if (k > 2) return false;
    }
    return true;
}

int main() {

    cin >> T;
    F0R(t, T) {
        cin >> N;
        F0R(i, N) {
            int x, y;
            cin >> x >> y;
            A[2*i] = {x, {1, i}};
            A[2*i + 1] = {y, {0, i}};
        }

        sort(A, A+2*N);

        printf("Case #%d: ", t+1);

        if(!solve()) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        F0R(i, N) cout << ((ans[i] == 0) ? "C" : "J");
        cout << endl;
    }
    return 0;
}
