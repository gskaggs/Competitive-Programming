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

int N, A[MAX_N]; 
ll ft[MAX_N], ans[MAX_N], in[MAX_N];

ll cf(int a) {
    ll res = 0;
    for(; a; a -= a&-a) res += ft[a];
    return res;
}
void inc(int a) {
    for (; a < MAX_N; a += a&-a) ft[a]++;
}

int main() {
    setIO("haircut"); 
    cin >> N;
    F0R(i, N) cin >> A[i];

    F0R(i, N) {
        in[i] = i - cf(A[i]+1);
        ans[A[i]+1] += in[i];
        inc(A[i]+1);
    }

    F0R(i, N) if(i) ans[i] += ans[i-1]; 
    F0R(i, N) cout << ans[i] << endl;

    return 0;
}
