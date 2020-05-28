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
    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;

        int M, N, T;
        ss >> M >> N >> T;

        vi dp (T+1, INT_MIN);

        dp[0] = 0;

        for (int i = 0; i <= T; i++) {
            if (i >= M && dp[i-M] != INT_MIN)
                dp[i] = dp[i-M] + 1;

            if (i >= N && dp[i-N] != INT_MIN) 
                dp[i] = max(dp[i], dp[i-N] + 1);

        }

        if (dp[T] != INT_MIN) 
            cout << dp[T] << endl;

        else {
            for (int i = T; i >= 0; i--) {
               if (dp[i] != INT_MIN) {
                   cout << dp[i] << " " << T-i << endl;
                   break;
               }

            }
        }

    }


    return 0;
}
