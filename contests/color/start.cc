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
#define MAX_N 300005
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

int N, M, uf[MAX_N], in[MAX_N];
vi adj[MAX_N];
umap<int, int> s;

int root(int a) {
    while(uf[a] != a) a = uf[a];
    return a;
}

void aunion(int a, int b) {
    a = root(a);
    b = root(b);
    uf[a] = b;
   
    if (a == b) return;
    if (in[a] && !in[b]) in[b] = in[a];
    else if (in[b] && !in[a]) in[a] = in[b];
    else if (in[a] && in[b] && root(in[a]) != root(in[b])) aunion(in[a], in[b]);
}

void adjust(int v) {
    trav(u, adj[v]) {
        u = root(u);
        if (in[u])
            aunion(v, in[u]);
        else 
            in[u] = root(v);
    }
}

int main() {
    setIO("fcolor");
    cin >> N >> M;
    F0R(i, M) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    F0R(i, MAX_N) uf[i] = i;
    FOR(v,1, N+1) adjust(v);
FOR(v,1, N+1) adjust(v);
FOR(v,1, N+1) adjust(v);

    int t = 0;
    FOR(v, 1, N+1) {
        if (s.count(root(v))) cout << s[root(v)] << endl;
        else {
            cout << ++t << endl;
            s[root(v)] = t;
        }
    }
    return 0;
}
