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

vvi adj;
vi startDist;
int done, N;
vvi mem;

int getDist(vi a, vi b) {
    return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}

int travel(int cur, int visited) {
    if (visited == done) 
        return startDist[cur];

    if (mem[cur][visited] != -1) 
        return mem[cur][visited];

    int res = INF;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) 
            continue;
        res = min(res, travel(i, visited | 1 << i) + adj[i][cur]);
    }

    mem[cur][visited] = res;
    return res;

}
int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        
        int W, H;
        vi S(2);
        cin >> W >> H >> S[0] >> S[1] >> N;

        vvi coords (N, vi(2));
        for (int i = 0; i < N; i++) {
            cin >> coords[i][0] >> coords[i][1];
        }

        adj.clear();
        adj.assign(N, vi(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                adj[i][j] = adj[j][i] = getDist(coords[i], coords[j]);
            }
        }
       
        startDist.clear();
        startDist.resize(N);

        for (int i = 0; i < N; i++) 
            startDist[i] = getDist(S, coords[i]);

        int res = INT_MAX;
        done = (1 << N) - 1;
        mem.clear();
        mem.assign(N, vi(1 << N, -1));

        for (int i = 0; i < N; i++) {
            res = min(res, startDist[i] + travel(i, 1 << i));
        }

        printf("The shortest path has length %d\n", res);

    }

    return 0;
}
