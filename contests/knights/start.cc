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

int dr [] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc [] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    
    vs board(5);

    int count = 0;

    string s;
    for (int i = 0; i < 5; i++) {
        cin >> board[i];
    }


    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == 'k') {
                count++;
                for (int i = 0; i < 8; i++) {
                    int R = r + dr[i];
                    int C = c + dc[i];

                    if (R >= 0 && R < 5 && C >= 0 && C < 5 && board[R][C] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                        //cout << r << " " << c << " " << R << " " << C << endl;
                    }
                }
            }
        }
    }


    cout << (count == 9 ? "valid" : "invalid") << endl;
    return 0;
}
