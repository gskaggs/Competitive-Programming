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
  
    vi coins(21);
    for (int i = 1; i <= 21; i++) {
        coins[i-1] = i * i * i;
    }

    string s;
    while (getline(cin, s)) {

        int n = stoi(s);

        vector<ll> dp (n+1, 1);

        for (int i = 1; i < 21; i++) {
           vector<ll> cur(dp);

           for (int j = 0; j < n+1; j++) {
               if (j - coins[i] >= 0)
                   cur[j] += cur[j - coins[i]];
           }

           swap(cur, dp);
        }

        cout << dp[n] << endl;
    }


    return 0;
}
