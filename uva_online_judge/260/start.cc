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

int dr [] = {-1, -1, 0, 0, 1, 1};
int dc [] = {-1, 0, -1, 1, 0, 1};

bool dfsW(int r, int c, vvi & grid) {
    int N = grid.size();

    if (r < 0 || c < 0 || r == N || c == N) return false;
    if (grid[r][c] != 'w') return false;
    if (c == N-1) return true;
    grid[r][c] = '.';

    for (int i = 0; i < 6; i++)
        if (dfsW(r + dr[i], c + dc[i], grid)) return true;
    
    return false;
}

bool dfsB(int r, int c, vvi & grid) {
    int N = grid.size();

    if (r < 0 || c < 0 || r == N || c == N) return false;
    if (grid[r][c] != 'b') return false;
    if (r == N-1) return true;
    grid[r][c] = '.';

    for (int i = 0; i < 6; i++)
        if (dfsB(r + dr[i], c + dc[i], grid)) return true;
    
    return false;
}

int main() {
    int count = 1;
    while(true) {
        int N;
        cin >> N;

        if (N == 0) break;
        vvi grid (N, vi(N));

        string s;
        for (int i = 0; i < N; i ++) {
            cin >> s;
            for (int j = 0; j < N; j++) {
                grid[i][j] = s[j];
            }
        }

        string res;

        for (int r = 0; r < N; r++) 
            if (dfsB(0, r, grid)) res = "B";
        for (int c = 0; c < N; c++) 
            if (dfsW(c, 0, grid)) res = "W";
    
        cout << count << " " << res << endl;
        count++;
    }

    return 0;
}
