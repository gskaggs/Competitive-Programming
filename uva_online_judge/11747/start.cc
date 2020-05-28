#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
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

class UnionFind {
    vi nums; 
    vi count;
public:
    UnionFind(int N) : nums(N), count(N, 1) {
        rep(i, 0, N) 
            nums[i] = i;
    }

    int root(int n) {
        while (nums[n] != n) n = nums[n];
        return n;
    }

    bool sameSet(int u, int v) {
        return root(u) == root(v);
    }

    bool unionSet(int u, int v) {
        u = root(u);
        v = root(v);
        
        if (v == u)  return false;

        if (count[v] > count[u]) 
            swap(v, u);

        nums[u] = v;
        count[v] += count[u];

        return true;
    }
};

int main() {

    while (true) {
        int V, E;
        cin >> V >> E;

        if (V + E == 0) break;

        vector<pair<int, ii>> edges(E);

        rep(i, 0, E) {
            int w, u, v;
            cin >> u >> v >> w; 
            edges[i] = {w, {u, v}};
        }

        sort(edges.begin(), edges.end());
        UnionFind UF(V);
        int count = 0;

        rep(i, 0, E) {
            auto cur = edges[i];
            int w = cur.first, v = cur.second.second, u = cur.second.first;

            if (!UF.unionSet(v, u)) {
                if (count) cout << " ";
                cout << w;
                count++;
                }
            }

        if (!count) cout << "forest";
        cout << endl;

    }


    return 0;
}
