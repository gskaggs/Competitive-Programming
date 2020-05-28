#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

vvi grid;

struct Node{
    int dist, x, y, d;

    bool operator () (const Node & n1, const Node & n2) const {
        return n1.dist > n2.dist;
    }
};

int main() {
      
    umap <string, int> dmap = {{"north", 0}, {"east", 1}, {"south", 2,}, {"west", 3}};

    while (true) {
        int R, C;
        cin >> R >> C;
        if (R == 0) break;

        grid.clear();
        grid.resize(R, vector<int>(C));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }

        int S1, S2, E1, E2;
        string d;
        cin >> S1 >> S2 >> E1 >> E2;
        cin >> d;

        priority_queue<Node, vector<Node>, Node> pq;
        pq.push({0, S1, S2, dmap[d]});
        int res = -1;

        uset<int> seen;

        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            int r = n.x, c = n.y;
            if (r < 1 || r == R || c < 1 || c == C) continue;
            if (grid[r][c] || grid[r][c-1] || grid[r-1][c] || grid[r-1][c-1]) continue;

            int ID = (R * r + c) * (n.d + 1);
            if (seen.count(ID)) continue;
            seen.insert(ID); 

            if (r == E1 && c == E2) {
                res = n.dist; 
                break;
            }

            pq.push({n.dist+1, r, c, (n.d + 1) %4});
            pq.push({n.dist+1, r, c, (n.d - 1) %4});

            for (int i = 1; i < R; i++) {
                if (n.d == 0 && i < r) 
                    pq.push({n.dist+1, i, c, n.d}); 

                if (n.d == 2 && i > r) 
                    pq.push({n.dist+1, i, c, n.d}); 

            }

            for (int i = 1; i < C; i++) {
                if (n.d == 3 && i < c) 
                    pq.push({n.dist+1, r, i, n.d}); 

                if (n.d == 1 && i > c) 
                    pq.push({n.dist+1, r, i, n.d}); 

            }

        }

        cout << res << endl;
            
         
    }
    return 0;
}
