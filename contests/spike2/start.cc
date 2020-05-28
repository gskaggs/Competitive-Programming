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
    
    int N;
    cin >> N;
    const int M = 1000000000 + 7;

    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }

    if (N == 1) {
        cout << 12 << endl;
        return 0;
    }


    vector<ll> dp (N);

    dp[0] = 6;
    dp[1] = 66;

    rep(i, 2, N) {
        dp[i] = ((6*dp[i-1]) % M) + (6*5*dp[i-2]) % M;
        dp[i] %= M;
    } 

    cout << (2* dp[N-1]) % M << endl;

    return 0;
}
