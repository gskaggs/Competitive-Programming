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
        
        int N, K;
        cin >> N >> K;
        vvi dp (N + 1, vi(N + K + 1));

        for (int r = 2; r <= N; r++) {
            for (int c = 0; c <= N + K; c++) {
                if (r + c > N + K) continue; 
                int res = INT_MAX;
                int n, k;

                for (int i = 1; i <= r; i++) {
                    int cur = 0, w = c + i;

                    // left
                    n = i -1;
                    k = c;
                    cur += dp[n][k] + w * n;

                    // mid
                    cur += w;

                    // right
                    n = r - i;
                    k = c + i;
                    if (k <= N + K) cur += dp[n][k] + w * n;

                    res = min (res, cur);
                }

                dp[r][c] = res;
            }
        }

       printf("Case %d: %d\n", t+1, dp[N][K]); 
    }

    return 0;
}
