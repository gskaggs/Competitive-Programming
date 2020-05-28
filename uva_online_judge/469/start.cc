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

vector<string> grid;
int dr [] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc [] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int r, int c) {
    int N = grid.size();
    int M = grid[0].size();
    //cout << "N M" << N << M  << endl;
    if (r < 0 || r == N || c < 0 || c == M)
        return 0;

    if (  grid[r][c] != 'W') {return 0;}

    grid[r][c] = '.';
    int res = 1;

    for (int i = 0; i < 8; i++) {
        res += dfs(r + dr[i], c + dc[i]);
    }

    return res;
}

void fill(int r, int c) {
    int N = grid.size();
    int M = grid[0].size();

    if (r < 0 || r == N || c < 0 || c == M || grid[r][c] != '.') 
        return;

    grid[r][c] = 'W';

    for (int i = 0; i < 8; i++) {
        fill(r + dr[i], c + dc[i]);
    }

}


int main() {
    int t;

    string s;
    getline(cin, s);
    t = stoi(s);

    getline(cin, s);
    for (int i = 0; i < t; i++) {
        grid.clear();

        while (true) {
            getline(cin, s);
            if (s[0] != 'L' && s[0] != 'W') break;
            //cout << s << endl;
            grid.push_back(s);
        }

        while (true) {
            //run dfs
            int res, r, c; 
            stringstream ss;
            ss << s;
            ss >> r;
            ss >> c;

            res = dfs(r-1, c-1);
            fill(r-1, c-1);

            cout << res << endl;
            //cout << grid[r-1] << endl;

            getline(cin, s);
            //cout << s << endl;
            if (s.empty()) break;
        }
        
        if(i != t-1) cout << endl;


    }

    return 0;
}
