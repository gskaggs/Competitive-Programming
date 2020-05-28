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


    ll N, M;
    while (cin >> N >> M) {
        ll res = 1;
        for(ll i = 0; i < M; i++) {
            res *= N - i;
            while (res % 10 ==0) res /= 10;
            res %= 1000000000;
        }
        cout << res % 10 << endl;
    }
    return 0;
}
