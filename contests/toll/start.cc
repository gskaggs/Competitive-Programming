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

    int N, M, S, V;
    cin >> N >> M >> S >> V;

    vector< vvii > adj (4, vvii(N + 1));

    for (int i = 0; i < M; i++) {

        int u , v , d , a;
        cin >> u >> v >> d >> a;

        adj[
}
