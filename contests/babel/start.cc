#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1000000000 
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int main() {

    while (1) {
        int N;
        cin >> N;
        if (!N) break;

        string start, finish;
        cin >> start >> finish;
        umap<string, uset<string>> adj;
        umap<string, uset<string>> dict;

        for (int i = 0; i < N; i++) {
            string u, v, w;
            cin >> u >> v >> w;

            for (auto s : dict[u]) {
                adj[s].insert(w);
                adj[w].insert(s);
            }

            for (auto s : dict[v]) {
                adj[s].insert(w);
                adj[w].insert(s);
            }

            dict[u].insert(w);
            dict[v].insert(w);
        }


        for (auto u : dict[start]) {
            adj["S"].insert(u);
        }

        for (auto u : dict[finish]) {
            adj[u].insert("");
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, "S"});

        umap<string, int> dist;
        dist["S"] = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            string u = cur.second;
            int d = cur.first;
            pq.pop();

            if (d > dist[u]) 
                continue;

            if (u == "") break;

            for (auto v : adj[u]) {
                if ((!dist.count(v) || v.size() + dist[u] < dist[v]) && (!v.size() || v[0] != u[0])) {
                    dist[v] = v.size() + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }
        if (!dist.count("")) cout << "impossivel" << endl;
        else cout << dist[""] << endl;
    }

    


    return 0;
}
