#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF INT_MAX
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        vvii adj(n);

        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<ii, vii, greater<ii>> pq;
        vi dist(n, INF);
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            ii p = pq.top();
            int u = p.first, d = p.second;
            pq.pop();
            if (p.first > dist[p.second]) continue;
            if (p.second == T) break;

            for (auto n : adj[p.second]) {
                int cur = n.second + p.first;
                if (cur < dist[n.first]) {
                    dist[n.first] = cur;
                    pq.push({cur, n.first});
                }
            }
        }

        printf("Case #%d: ", i+1);
        if(dist[T] != INF) 
            cout << dist[T] << endl;
        else
            cout << "unreachable" << endl;

    }

    return 0;
}
