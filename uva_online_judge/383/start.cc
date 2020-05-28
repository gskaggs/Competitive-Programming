#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

int bfs(string start, string finish, umap <string, vector<string> > & adj) {
    queue<pair<string, int> > q;
    q.push({start, 0});
    uset<string> seen;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        string u = p.first;
        int count = p.second;

        if (u == finish) return count;
        if (seen.count(u)) continue;
        seen.insert(u);
        
        //vector<string> l = adj[u];
        for (auto next : adj[u]) 
            q.push({next, count+1});
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    cout << "SHIPPING ROUTES OUTPUT" << endl << endl;

    for (int i = 1; i <= t; i++) {
        cout << "DATA SET  " << i << endl << endl;
        int m, n, p;
        cin >> m >> n >> p;

        for (int j = 0; j < m; j++){
            string s; 
            cin >> s;
        }

        umap <string, vector<string> > adj;
        for (int j = 0; j < n; j++) {
            string u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int size = -1;
        for (int j = 0; j < p; j++) {
            string start, finish;
            cin >> size >> start >> finish;

            int res = bfs(start, finish, adj);
            if (res == -1) 
                cout << "NO SHIPMENT POSSIBLE" << endl;
            else
                printf("$%d\n", size*res*100);
        }
        cout << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
