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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        if (t!=0) cout << endl;
        int N, E, time, M;
        cin >> N >> E >> time >> M;

        vvii adj(N+1);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
        }

        vi dist(N+1, INF);
        dist[E] = 0;

        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({0, E});

        while (!pq.empty()) {
            ii p = pq.top();
            int u = p.second, d = p.first;
            pq.pop();
            
            if (d > dist[u]) continue;

            for (auto n : adj[u]) {
                int cur = n.second + d;
                if (cur < dist[n.first]) {
                    dist[n.first] = cur;
                    pq.push({cur, n.first});
                }
            }
        }

        int count = 0;

        for (int i = 1; i <= N; i++) {
            if (dist[i] <= time) count++;
        }

        cout << count << endl;

    }

    return 0;
}
