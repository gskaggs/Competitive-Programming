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


int main() {
    int num = 1; 
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        uset<int> nodes;
        umap <int, uset<int> > adjList;
        for (int i = 0;  i < N; i++) {
            int u, v;
            cin >> u >> v;
            nodes.insert(u);
            nodes.insert(v);
            adjList[u].insert(v);
            adjList[v].insert(u);
        }


        while (true) {
            int start, TTL;
            cin >> start >> TTL;
            if (start == 0 && TTL == 0)
                break;
            
            uset<int> cur(nodes);
            queue<ii> q;
            q.push({start, TTL});

            while (!q.empty()) {
                ii elem = q.front();
                q.pop();
                int u = elem.first, count = elem.second;

                if (!cur.count(u)) continue;
                cur.erase(u);

                if (count == 0) continue;

                for (int v : adjList[u])
                    q.push({v, count-1});
            }

            int diff = cur.size();
            printf("Case %d: %d nodes not reachable from %d with TTL = %d.\n", num++, diff, start, TTL);
        }
    
    } 
    
    return 0;
}
