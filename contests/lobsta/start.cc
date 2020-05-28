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
    
    int N;
    cin >> N;

    vi n (N);
    for (int i = 0; i < N;i++) {
        cin >> n[i];
    }

    vi m = n;
    reverse(m.begin(), m.end());

    n.insert(n.end(), m.begin(), m.end());

    ll dp = -1 * INF;
    ll res = 0;

    for (int i = 0;i <n.size(); i++) {
        dp = max(dp + n[i], (ll)n[i]);
        res = max(res, dp);
    }

    cout << res << endl;

    return 0;
}
