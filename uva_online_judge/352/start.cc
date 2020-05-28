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

int dr [] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dc [] = {0, -1, 1, 0, -1, 1, -1, 1};

bool dfs (int r, int c, vector<string> & grid) {
    int N = grid.size();
    if (r < 0 || c < 0 || r == N || c == N || grid[r][c] != '1') return false;

    grid[r][c] = '0';
    for (int i = 0; i < 8; i++) {
        dfs(r + dr[i], c + dc[i], grid);
    }
    return true;
}

int main() {
    int count = 1;

    while (true) {
        int N;
        cin >> N;

        if (cin.eof()) break;

        vector<string> grid(N);

        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }

        int res = 0;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (dfs(r, c, grid)) res++;
            }
        }

        printf("Image number %d contains %d war eagles.\n", count, res);
        count++;
    }
    
    
    return 0;
}
