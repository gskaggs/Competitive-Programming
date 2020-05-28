#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1000000000 
#define mod 1000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int main() {

    vvi dp (101, vi(101, 1));

    rep(k, 2, 101) {
        int sum = 0;
        rep(i, 0, 101) {
            sum += dp[k-1][i];
            dp[k][i] = sum % mod;
        }
    }

    while (1) {
        int K, N;
        cin >> N >> K;
        if (N + K == 0) break;

        cout << dp[K][N] << endl;
    }


    return 0;
}
