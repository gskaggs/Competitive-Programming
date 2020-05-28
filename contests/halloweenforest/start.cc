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

int main() {
    int N, H;
    cin >> N >> H;

    vector<pair<ll, ll>> trees(N);
    rep(i, 0, N) {
        ll h, x;
        cin >> h >> x;
        trees[i] = {x, h};
    }

    sort(trees.begin(), trees.end());
    ll count = 0;

    rep(i, 0, N) {
        ll xi = trees[i].first, hi = trees[i].second;
        rep(j, 0, i) {
            ll  hj = trees[j].second,
                xj = trees[j].first;
            if (hi > hj) continue;
            if ((hj - hi) * (xi) > (H - hi) * (xi - xj)) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}
