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
    int N, M;
    cin >> N >> M;

    ii start;
    
    vs board(N);
    rep(i, 0, N) {
        board[i].resize(M);
        rep(j, 0, M) {
            cin >> board[i][j];
            if (board[i][j] == 'K') {
                start = {i, j};
            }
        }
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    umap<int, umap<int, bool>> seen;

    queue<ii> q;
    q.push(start);

    bool home = false;

    while(!q.empty()) {
        auto cur = q.front();
        int i = cur.first, j = cur.second;
        q.pop();

        if (board[i][j] == 'H') {
            home = true;
            break;
        }
        if (seen[i][j] || board[i][j] == 'G') {
            seen[i][j] = true;
            continue;
        }        
        rep(d, 0, 4) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (!seen[i][j]) q.push({x, y});
        }

        seen[i][j] = true;
    }

    cout << (home ? "Safe" : "Spook") << endl;


    return 0;
}
