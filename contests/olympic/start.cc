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

int N, M;
vvi val;

map<int, map<int, int>> mem;

int dp(int i, int j, int k) {
    if(i>= N || j >= M) return 0;
    int id = 750 * i + j;

    if (mem.count(id) && mem[id].count(k)) 
        return mem[id][k];

    int cur = val[i][j];
    if (i == N-1 && j == M-1) {
        return k == 0 ? cur : max(cur, -1*cur);
    }

    int result = dp(i+1,j,k) + cur;
    result = max(result, dp(i,j+1,k) + cur);
    if(cur < 0 && k > 0) {
        result = max(result, dp(i+1,j,k-1) - cur);
        result = max(result, dp(i,j+1,k-1) - cur);
    }

    mem[id][k] = result;
    return result;
}

int main() {
    int K;
    cin >> N >> M >> K;
    val = vvi(N, vi(M, 0));

    rep(r, 0, N) {
        rep(c, 0, M) {
            cin >> val[r][c];
        }
    }


    cout << dp(0, 0, K) << endl;

   
    return 0;
}
