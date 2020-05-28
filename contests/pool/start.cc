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

int N, Q, res;
vvi back;
vi dp;

void updateDP(int u) {
    
    for (auto n : back[u]) {
        dp[n] = max(dp[n], dp[u] + 1);
        res = max(res, dp[n]);
        updateDP(n);
    }

}

int main() {
    cin >> N >> Q;
    res = 0;
    back.clear();
    back.resize(N);

    dp.clear();
    dp.assign(N, 0);

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        
        back[v].push_back(u);
        dp[u] = max(dp[u], dp[v] + 1);
        res = max(res, dp[u]);
        updateDP(u);
        cout << res << endl;
    }


    return 0;
}
