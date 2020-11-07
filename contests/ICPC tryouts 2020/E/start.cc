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
 
int N, E;
int dist[MAX_N];
vpi adj[MAX_N];

void djikstra() {
    F0R(i, N+1) dist[i] = INF;
    dist[0] = 0;

    priority_queue<pi, vpi, greater<pi>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto cur = pq.top();
        int d = cur.f;
        int v = cur.s;
        pq.pop();

        if (d > dist[v]) continue;

        trav(next, adj[v]) {
            int u = next.f;
            int w = next.s;

            if (w + d < dist[u]) {
                dist[u] = w + d;
                pq.push({dist[u], u});
            }
        }
    }

}

int main() {
    cin >> N >> E;

    F0R(i, N) {
        int c;
         cin >> c;
         adj[0].pb({i+1, c});
    }
    F0R(i, E) {
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        adj[u].pb({v, w});
    }

    djikstra();

    ll res = 0;
    F0R(i, N) {
        int c;
        cin >> c;
        res += c * dist[i+1];
    }
    cout << res << endl;
    return 0;
}
