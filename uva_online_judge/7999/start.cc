#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;


int maxSum( const vector< vector<int> > & grid) {
    int R = grid.size(), C = grid[0].size();
    vector<int> prev(grid[R-1]);

    for (int r = R - 2; r >= 0; r--) {
        vi cur(grid[r]);

        for (int c = 0; c < C; c++) {
            int best = prev[c];
            if (c != 0) best = max(best, prev[c-1]);
            if (c != C -1) best = max(best, prev[c+1]);
            cur[c] += best;
        }

        swap(prev, cur);
    }

    return *max_element(prev.begin(), prev.end());
}


int main() {
    int t, h, w;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> h >> w;
        vector< vi > cur(h, vi (w));

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                int s;
                cin >> s;
                cur[j][k] = s;
            }
        }

        cout << maxSum(cur) << endl;
    }

    return 0;
}
