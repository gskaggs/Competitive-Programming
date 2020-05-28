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
        
        if (v == u)  return true;

        if (count[v] > count[u]) 
            swap(v, u);

        nums[u] = v;
        count[v] += count[u];

        return false;
    }
};

int main() {

    while (true) {
        int m, n;
        cin >> m >> n;

        if (m + n == 0) break;

        vector<pair<int, ii>> edges(n);
        int total = 0;

        rep(i, 0, n) {
            int w, u, v;
            scanf("%d %d %d\n", &u, &v, & w);;
            edges[i] = {w, {u, v}};
            total += w;
        }

        sort(edges.begin(), edges.end());
        UnionFind UF(m);
        int msp = 0;
        int count = 0;

        rep(i, 0, n) {
            auto cur = edges[i];
            int w = cur.first, v = cur.second.second, u = cur.second.first;

            if (!UF.unionSet(v, u)) {
                msp += w;
                count++;
                if (count == m-1) {
                    break;
                }
            }
        }

        printf("%d\n", total - msp);

    }


    return 0;
}
