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
        
        int X;
        cin >> X;
        X /= 100;
        
        vvi W (10, vi (X));

        for (int i = 0; i < 10; i++) {
            for (int x = 0; x < X; x++) {
                cin >> W[i][x];
            }
        }

        reverse(W.begin(), W.end());

        vi dp(10, INF);
        dp[0] = 0;

        for (int i = X-1; i >= 0; i--) {
            vi cur (10);
            for (int r = 0; r < 10; r++) {
                int w = W[r][i];
                int res = dp[r] == INF ? INF : dp[r] + 30 - w;

                if (r != 9 && dp[r+1] != INF) res = min(res, dp[r+1] + 60 - w); 
                if (r != 0 && dp[r-1] != INF) res = min(res, dp[r-1] + 20 - w);

                cur[r] = res;
            }

            swap(dp, cur);
        }

        cout << dp[0] << endl << endl;

    }

    return 0;
}
