#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 0XFFFFFFFFFFFFFFF
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

struct Canidate {
    ll u, d, gas, e;

    bool operator > (const Canidate c) const {
        return this->d > c.d;
    }
};

int main() {

    ll n, m, t, big;
    cin >> n >> m >> t >> big;

    uset <ll> stations;
    for (int i = 0; i < t; i++) {
        ll cur;
        cin >> cur;
        //cout << cur << endl;
        stations.insert(cur-1);
    }

    vector<vector<pair<ll, ll>>> adj (n);

    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        //cout << u << v << w << endl;
        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    }

    
    vector<ll> dist(n, INF);
    dist[0] = 0;

    priority_queue<Canidate, vector<Canidate>, greater<Canidate>> pq;
    pq.push({0, 0, big, 0});

    vector<umap<ll, uset<ll>>> seen(n);

    while (!pq.empty()) {
        Canidate cur = pq.top();
        pq.pop();
        ll u = cur.u, d = cur.d, gas = cur.gas, e = cur.e;
        //cout << u << " " << d  << " " << gas  << " " << e << endl; 

        if (seen[u][d].count(gas) || gas < 0 || e > m) continue;
        seen[u][d].insert(d);
        if (stations.count(u)) gas = big;
        //cout << "Passed: " <<  u << " " << d  << " " << gas  << " " << e << endl; 

        dist[u] = min(dist[u], d);

        for (int i = 0; i < adj[u].size(); i++) {
            ii temp = adj[u][i];
            int v = temp.first, w = temp.second;

            if (gas-w >= 0)
                pq.push({v, d+w, gas-w, e+1});
            
        }
    }

    if (dist[n-1] == INF) cout << "stuck" << endl;
    else cout << dist[n-1] << endl;


    

    return 0;
}
