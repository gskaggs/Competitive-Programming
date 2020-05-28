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
    
    int N, P;
    cin >> N >> P;

    int M = 1000000000 + 7;

    vi p;
    while (N) {
        p.push_back(N % P);
        N /= P;
    }

    ll T = 0;
    ll res = 1;

    rep(i, 0, sz(p)) {

    }

    return 0;
}
