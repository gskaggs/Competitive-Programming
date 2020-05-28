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

int N, M, A[MAX_N], B[MAX_N], ans[MAX_N], in[MAX_N];
set<int> c;

int main() {
    setIO("cereal");

    cin >> N >> M;

    F0R(i, N) cin >> A[i] >> B[i];
    F0R(i, MAX_N) in[i] = -1;

    R0F(i, N) {
        int a = A[i];
        c.insert(a);

        int j = in[a];
        while (j != -1) {
            c.insert(B[j]);
            if (in[B[j]] < j) break;

            int temp = in[B[j]];
            in[B[j]] = -1;
            j = temp;
        }
        
        in[a] = i;
        ans[i] = sz(c);
    }
    
    F0R(i, N) cout << ans[i] << endl;

    return 0;
}
