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

int N, M;

bool inBounds(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}

int main() {
    int T;
    cin >> T;

    rep(t, 0, T) {
        cin >> N >> M;

        vvi board(N, vi(M));

        rep(n, 0, N) 
            rep(m, 0, M) 
                cin >> board[n][m];
            
        
        vi dist(M*N, INF);
        dist[0] = board[0][0];

        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({dist[0], 0});

        while(!pq.empty()) {
            auto cur = pq.top();
            int u = cur.second;
            int d = cur.first;
            pq.pop();
            
            if (u == N*M-1) break;
            if (d > dist[u]) continue;
            
            int r = u/M;
            int c = u%M;

            int dr[] = {0, 1, 0, -1};
            int dc[] = {-1, 0, 1, 0};

            rep(i, 0, 4) {
                int R = r + dr[i], C = c + dc[i];
                if (inBounds(R, C) && d + board[R][C] < dist[(R)*M + C]) {
                    int v = (R) * M + C;
                    dist[v] = d + board[R][C];
                    pq.push({dist[v], v});
                }
            }

        }

        cout << dist[N*M-1] << endl;


    }

    return 0;
}
