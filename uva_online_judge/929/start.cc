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

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        
        int R, C;
        cin >> R >> C;
        
        vvi G (R, vi(C));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> G[r][c];
            }
        }

        priority_queue<ii, vii, greater<ii>> pq;
        pq.push({G[0][0], 0});

        vvi dist(R, vi(C, INF));
        dist[0][0] = G[0][0];
        int end = R*C - 1;

        while (!pq.empty()) {
            ii p = pq.top();
            int d = p.first, id = p.second;
            int r = id / C, c = id % C;
            pq.pop();

            if (id == end) break;
            if (d > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr == R || nc < 0 || nc == C) continue;
                int next = G[nr][nc] + dist[r][c];

                if (next < dist[nr][nc]) {
                    dist[nr][nc] = next;
                    pq.push({next, nr*C + nc});
                }
            }
        }

        cout << dist[R-1][C-1] << endl;

    }

    return 0;
}
