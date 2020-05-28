#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto& a : x)
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
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

    int N, M;
    cin >> N >> M;

    vvi adj(N, vi(N, INF));

    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> adj[i][j];
        }
    }

    rep(k, 0, N) 
        rep(i, 0, N) 
            rep(j, 0, N) 
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);


    vi p(M);
    vi s(M);

    rep(i, 0, M)
        cin >> p[i];

    rep(i, 0, M)
        cin >> s[i];

    vi pairedS(M, 0);
    vi pairedP(M, 0);
    ll res = 0;

    rep(k, 0, M) {
        int bp = -1, bs = -1;

        rep(i, 0, M) {
            if (pairedP[i]) continue;
            rep(j, 0, M) {
                if (pairedS[j]) continue;

                if (bp == -1 || adj[p[i]][s[j]] < adj[p[bp]][s[bs]]) {
                    bp = i;
                    bs = j;
                }
            }
        }

        res += adj[p[bp]][s[bs]];
        pairedS[bs] = 1;
        pairedP[bp] = 1;
    }

    cout << res << endl;

    return 0;
}
