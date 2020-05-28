#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1<<20 
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int N, done;
vector<vector<float>> adj;
vector<float> val;
vector<vector<float>> mem;

float travel (int cur, int visited) {
    if (visited == done) 
        return -1 * adj[cur][0]; 

    if (mem[cur][visited] != INF) 
        return mem[cur][visited];

    float res = -1 * adj[cur][0];

    for (int i = 0; i <= N; i++) {
        if (visited & 1 << i || adj[cur][i] == INF)
            continue;

        cout << cur << " " << i << " " << val[i] << " " << adj[cur][i] << endl;
        res = max(res, travel(i, visited | 1 << i) + val[i] - adj[cur][i]);
    }

    mem[cur][visited] = res;
    return res;


}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
       int M;
       cin >> N >> M;
       done = (1 << (N+1)) -1;

       adj.clear();
       adj.assign(N+1, vector<float>(N+1, INF));

       for (int i = 0; i < M; i++) {
           int u, v;
           float d;
           cin >> u >> v >> d;
           cout << d << endl;
           adj[u][v] = d;
           adj[v][u] = d;
       }

       val.clear();
       val.assign(N+1, 0);

       int P;
       cin >> P;

       
       for (int i = 0; i < P; i++) {
           int u;
           float v;

           cin >> u >> v;
           //cout << u << " " << v << endl;
           val[u] = v;
       }

       mem.clear();
       mem.assign(N+1, vector<float> (1 << (N+2), INF));
       cout << travel(0, 1) << endl;

    }

    return 0;
}
